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
    char buffer[4112], *ptr=buffer, *end=buffer+4096;
    template <typename T> inline void writeint(T x, char endc='\n'){
        if(x<0)*ptr = '-', ++ptr, x=-x; if(!x)*ptr='0', ++ptr;
        char *s=ptr, c; T t;
        while(x){ t=x/10; c=x-10*t+'0'; *ptr=c, ++ptr, x=t; }
        char *f=ptr-1; while(s<f)swap(*s,*f), ++s, --f;
        if(ptr>end)fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
        *ptr=endc, ++ptr;
    }

    template<typename T>
    inline void output(T x){ writeint(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ writeint(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

vector<int> G[300005];

vector<pair<int,int>> tags[300005];

long long ans[300005];

long long vals[600005];
long long value;

void dfs(int now,int pa,int dep){
    for(auto &p:tags[now]){
        vals[p.first+dep]+=p.second;
        value+=p.second;
    }
    value-=vals[dep-1];
    ans[now]=value;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,dep+1);
    }
    value+=vals[dep-1];
    for(auto &p:tags[now]){
        vals[p.first+dep]-=p.second;
        value-=p.second;
    }
}

vector<pair<int,int>> edg;
int deg[300005];
int main(){
    int n; rit(n);
    edg.resize(n-1);
    for(int i=1,u,v;i<n;++i){
        rit(u,v);
        ++deg[u]; ++deg[v];
        edg[i-1]={u,v};
    }
    for(int i=1;i<=n;++i)G[i].resize(deg[i]);
    for(auto &p:edg){
        G[p.first][--deg[p.first]]=p.second;
        G[p.second][--deg[p.second]]=p.first;
    }
    int m,v,d,x; rit(m);
    while(m--){
        rit(v,d,x);
        d=min(d,n);
        tags[v].emplace_back(d,x);
    }
    dfs(1,1,1);
    for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
}
