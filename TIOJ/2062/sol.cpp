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

vector<int> G[1000006];
bitset<1000006> v;
int clr[1000006],qu[1000006];

void bfs(int s){
    int qf=-1,qb=-1,now;
    qu[++qf]=s; clr[s]=1; v[s]=1;
    while(qf!=qb){
        now=qu[++qb];
        for(int i:G[now]){
            if(v[i]){
                if(clr[i]==clr[now]){ cout<<-1<<endl; exit(0); }
            }
            else{
                qu[++qf]=i;
                clr[i]=3-clr[now];
                v[i]=1;
            }
        }
    }
}

pair<int,int> es[2000006];
int deg[1000006];
int main(){
    int n,m,s,t; rit(n,m);
    for(int i=0;i<m;++i){
        rit(s,t);
        es[i]=pair<int,int>(s,t);
        ++deg[s]; ++deg[t];
    }
    for(int i=1;i<=n;++i)G[i].resize(deg[i]);
    for(int i=0;i<m;++i){
        G[es[i].first][--deg[es[i].first]]=es[i].second;
        G[es[i].second][--deg[es[i].second]]=es[i].first;
    }
    for(int i=1;i<=n;++i){
        if(!v[i])bfs(i);
    }
    vector<int> v[4];
    for(int i=1;i<=n;++i)v[clr[i]].push_back(i);
    cout<<v[1].size()<<" "<<v[2].size()<<endl;
    for(int i:v[1])pit.write(i,i==v[1].back()?'\n':' ');
    for(int i:v[2])pit.write(i,i==v[2].back()?'\n':' ');
}

