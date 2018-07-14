#include<bits/stdc++.h>
using namespace std;

/* #pragma GCC diagnostic push
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
#pragma GCC diagnostic pop */

int n;
int dp[1003][100005],c[1003],l[1003],tmp[1003][100005];
vector<int> G[1003];

#ifdef WEAK
#include</home/edison/Coding/cpp/template/debug.cpp>
#else
#define PDE(...) ;
#endif

void dfs(int now,int k){
    if(c[now]>k)return;
    PDE(now,k);
    // for(int z=0,*ttmp=tmp[now],*tdp=dp[now];z<=k;++z,++ttmp,++tdp)*ttmp=*tdp;
    for(int z=0;z<=k;++z)tmp[now][z]=dp[now][z];
    // for(int z=0,*ndp=dp[now],*odp=dp[now]+c[now];z<=k-c[now];++z,++ndp,++odp)*ndp=(*odp)+l[now];
    for(int z=0;z<=k-c[now];++z)dp[now][z]=dp[now][z]+l[now];
    /* PDE(now);
    for(int z=0;z<=k-c[now];++z)PDE(z,dp[now][z]); */
    for(int i:G[now]){
        // for(int z=0,*dst=dp[i],*src=dp[now];z<=k-c[now];++z,++dst,++src)*dst=*src;
        for(int z=0;z<=k-c[now];++z)dp[i][z]=dp[now][z];
        dfs(i,k-c[now]);
        // for(int z=0,*dst=dp[now],*src=dp[i];z<=k-c[now];++z,++dst,++src)*dst=*src;
        for(int z=0;z<=k-c[now];++z)dp[now][z]=dp[i][z];
    }
    // for(int z=k,*odp=dp[now]+c[now],*tdp=dp[now],*ttmp=tmp[now]+c[now];z>=0;--z,--odp,--tdp,--ttmp)*odp=(z>=c[now]?max(*tdp,*ttmp):*ttmp);
    for(int z=k;z>=0;--z)dp[now][z]=(z>=c[now]?max(tmp[now][z],dp[now][z-c[now]]):tmp[now][z]);
    /* PDE(now);
    for(int z=0;z<=k;++z)PDE(z,dp[now][z]); */
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int k; cin>>n>>k;
        G[0].clear();
        for(int i=1,p;i<=n;++i){
            cin>>p>>c[i]>>l[i];
            G[p].push_back(i);
            G[i].clear();
        }
        for(int i=0;i<=n;++i)memset(dp[i],0,(k+2)<<2);
        dfs(0,k);
        cout<<*max_element(dp[0],dp[0]+k+1)<<endl;
    }
}
