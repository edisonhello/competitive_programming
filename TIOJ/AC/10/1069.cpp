#include<bits/stdc++.h>
using namespace std;

struct E{
    int t,x,y;
} es[1002];

struct edge{
    int u,v,f;
};
vector<int> G[2100];
vector<edge> edg;

void ae(int u,int v,int f){
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}

int idx[2100],dep[2100];
bitset<2100> vis;
bool bfs(int s,int t){
    queue<int> q; q.push(s); vis.reset(); vis[s]=1; dep[s]=0;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(!e.f || vis[e.v])continue;
            vis[e.v]=1;
            dep[e.v]=dep[now]+1;
            q.push(e.v);
        }
    }
    return vis[t];
}

int dfs(int now,int t,int fl){
    if(now==t)return fl;
    int rt=0;
    for(int &i=idx[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        if(dep[e.v]!=dep[now]+1 || !e.f)continue;
        int tmp=dfs(e.v,t,min(fl,e.f));
        fl-=tmp; rt+=tmp;
        edg[G[now][i]].f-=tmp;
        edg[G[now][i]^1].f+=tmp;
        if(!fl)break;
    }
    return rt;
}

int flow(int s,int t){
    int rt=0;
    while(bfs(s,t)){
        memset(idx,0,sizeof(idx));
        rt+=dfs(s,t,0x3f3f3f3f);
    }
    return rt;
}

// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
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
    char _buffer[4112],*_ptr=_buffer,*_end=_buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*_ptr='-',++_ptr,x=-x; if(!x)*_ptr='0',++_ptr;
        char *s=_ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *_ptr=c,++_ptr,x=t;}
        char *f=_ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(_ptr>_end)fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout),_ptr=_buffer;
        *_ptr=endc,++_ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout); }
} pit;

int main(){
    int ts; rit(ts); while(ts--){
        int n; rit(n);
        for(int i=1;i<=n;++i)rit(es[i].t,es[i].x,es[i].y);
        for(int i=0;i<=2*n+1;++i)G[i].clear(); edg.clear();
        for(int i=1;i<=n;++i)ae(0,i,1),ae(i+n,2*n+1,1);
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){
            if(i==j || es[i].t>=es[j].t)continue;
            if(es[j].t-es[i].t >= abs(es[i].x-es[j].x) + abs(es[i].y-es[j].y)){
                ae(i,j+n,1);
            }
        }
        pit(n-flow(0,n*2+1));
    }
}
