#include<bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int p,ind[666],oud[666];
// vector<int> G[666];

// int G[666][666];
vector<int> G[666];
int ways[666][666];
int mat[666][666];
int stid[666],edid[666];
bitset<666> vis[666];

void go(int i,int j){
    if(vis[i][j])return;
    vis[i][j]=1;
    if(i==j)ways[i][j]=1;
    else for(int z:G[i])go(z,j),ways[i][j]=(ways[i][j]+1ll*ways[z][j])%p;
}

int pw(int b,int n,int m,int a=1){
    while(n){
        if(n&1)a=1ll*a*b%m;
        b=1ll*b*b%m; n>>=1;
    } return a;
}
int inv(int x){ return pw(x,p-2,p); }

int32_t main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    // test(); exit(0);
    int n,m,u,v; rit(n,m,p);
    while(m--){
        rit(u,v);
        ++oud[u]; ++ind[v];
        // ++G[u][v];
        G[u].push_back(v);
        // ++ways[u][v];
    }
    /* for(int i=1;i<=n;++i){
        if(ind[i])continue;
        vector<int> _ind(ind,ind+666);
        ways[i][i]=1;
        queue<int> q;
        for(int i=1;i<=n;++i)if(_ind[i]==0)q.push(i);
        while(q.size()){
            int now=q.front(); q.pop();
            // cout<<"start from "<<i<<" go to "<<now<<" have "<<ways[i][now]<<" routes"<<endl;
            for(int j=1;j<=n;++j)if(G[now][j]){
                (ways[i][j]+=1ll*ways[i][now]*G[now][j]%p)%=p; _ind[j]-=G[now][j];
                if(_ind[j]==0)q.push(j);
            }
        }
    } */
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)go(i,j);
    // for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)ways[i][j]+=1ll*ways[i][k]*ways[k][j]%p,ways[i][j]<0?ways[i][j]+=p:0,ways[i][j]>=p?ways[i][j]-=p:0;
    int z=0;
    for(int i=1;i<=n;++i)if(!ind[i])++z;
    int inp=0,oup=0;
    for(int i=1;i<=n;++i)if(!ind[i])stid[i]=++inp;
    for(int i=1;i<=n;++i)if(!oud[i])edid[i]=++oup;
    for(int i=1;i<=n;++i)if(stid[i])for(int j=1;j<=n;++j)if(edid[j])mat[stid[i]][edid[j]]=ways[i][j];
    for(int i=1;i<=n;++i)if(stid[i] && edid[i])mat[stid[i]][edid[i]]=1;
    // for(int i=1;i<=z;++i){ for(int j=1;j<=z;++j)cout<<mat[i][j]<<" "; cout<<endl; }
    // cout<<z<<endl;
    auto calc=[&](int a,int b,int c,int d)->int{ int x=(1ll*a*d-1ll*b*c)%p; return x<0?x+p:x; };
    for(;z>2;--z){
        // for(int i=1;i<z;++i)for(int j=1;j<z;++j)mat[i][j]=((1ll*mat[i][j]*mat[z][z]-1ll*mat[i][z]*mat[z][j])%p+p)%p;
        int pi=-1,pj=-1,offset=1;
        for(int i=1;i<=z;++i)for(int j=1;j<=z;++j)if(mat[i][j])pi=i,pj=j;
        if(pi==-1 && pj==-1){ z=1; break; }
        if(pi!=1){ offset*=-1; for(int j=1;j<=z;++j)swap(mat[1][j],mat[pi][j]); }
        if(pj!=1){ offset*=-1; for(int i=1;i<=z;++i)swap(mat[i][1],mat[i][pj]); }
        offset*=pw(inv(mat[1][1]),z-2,p);
        if(offset<0)offset+=p;
        // for(int i=1;i<=z;++i){ for(int j=1;j<=z;++j)cout<<mat[i][j]<<" "; cout<<endl; }
        // cout<<"offset: "<<offset<<endl;
        for(int i=2;i<=z;++i)for(int j=2;j<=z;++j)mat[i][j]=calc(mat[1][1],mat[1][j],mat[i][1],mat[i][j]);
        for(int i=1;i<z;++i)for(int j=1;j<z;++j)mat[i][j]=mat[i+1][j+1];
        for(int j=1;j<z;++j)mat[1][j]=1ll*mat[1][j]*offset%p;
    }
    // for(int i=1;i<=z;++i){ for(int j=1;j<=z;++j)cout<<mat[i][j]<<" "; cout<<endl; }
    if(z==2){
        int x=(1ll*mat[1][1]*mat[2][2]-1ll*mat[1][2]*mat[2][1])%p;
        cout<<(x<0?x+p:x)<<endl;
    }
    else{
        cout<<(mat[1][1]<0?mat[1][1]+p:mat[1][1])<<endl;
    }
}
