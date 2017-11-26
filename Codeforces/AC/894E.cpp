#include<bits/stdc++.h>
using namespace std;
#define getchar gtx
inline char gtx(){
    const int N=1048576;
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
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
};
vector<edge> edg;
vector<int> G[1000006],iG[1000006],tp;
vector<pair<int,int>> cG[1000006];
bitset<1000006> v;
int bel[1000006];
long long bcw[1000006],dp[1000006];

void dfs1(int now){
    v[now]=1;
    for(int &eid:G[now])if(!v[edg[eid].v])dfs1(edg[eid].v);
    tp.push_back(now);
}
void dfs2(int now,int ccc){
    v[now]=1; bel[now]=ccc;
    for(int &eid:iG[now])if(!v[edg[eid].u])dfs2(edg[eid].u,ccc);
}
void dfs3(int now){
    if(dp[now])return;
    for(auto i:cG[now]){
        dfs3(i.first);
        dp[now]=max(dp[now],i.second+dp[i.first]);
    } 
    dp[now]+=bcw[now];
}
inline long long meow(long long w){
    long long L=0,R=14444,M;
    while(R>L){
        M=(L+R+1)>>1;
        if((((M-1)*M)>>1)<=w)L=M;
        else R=M-1;
    }
    return w*L-((L-1)*L*(L+1))/6;
}
signed main(){
    int n,m; rit(n,m);
    while(m--){
        int u,v,w; rit(u,v,w);
        G[u].push_back(edg.size());
        iG[v].push_back(edg.size());
        edg.emplace_back(u,v,w);
    }
    for(int i=1;i<=n;++i)if(!v[i])dfs1(i); v.reset();
    for(int i=n-1,cc=0;i>=0;--i)if(!v[tp[i]])dfs2(tp[i],cc++);
    for(auto &e:edg){
        if(bel[e.u]==bel[e.v])bcw[bel[e.u]]+=meow(e.w);
        else cG[bel[e.u]].emplace_back(bel[e.v],e.w);
    }
    int st; rit(st); st=bel[st];
    dfs3(st);
    printf("%lld\n",dp[st]);
}
