#include<bits/stdc++.h>
using namespace std;

struct dinic {
    static const int inf = 1e9;
    static const int maxn = 605;
    struct edge {
        int dest, cap, rev;
        edge(int d, int c, int r): dest(d), cap(c), rev(r) {}
    };
    vector<edge> g[maxn];
    int qu[maxn], ql, qr;
    int lev[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            g[i].clear();
    }
    void add_edge(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size() - 0);
        g[b].emplace_back(a, 0, g[a].size() - 1);
    }
    bool bfs(int s, int t) {
        memset(lev, -1, sizeof(lev));
        lev[s] = 0;
        ql = qr = 0;
        qu[qr++] = s;
        while (ql < qr) {
            int x = qu[ql++];
            for (edge &e : g[x]) if (lev[e.dest] == -1 && e.cap > 0) {
                lev[e.dest] = lev[x] + 1;
                qu[qr++] = e.dest;
            }
        }
        return lev[t] != -1;
    }
    int dfs(int x, int t, int flow) {
        if (x == t) return flow;
        int res = 0;
        for (edge &e : g[x]) if (e.cap > 0 && lev[e.dest] == lev[x] + 1) {
            int f = dfs(e.dest, t, min(e.cap, flow - res));
            res += f;
            e.cap -= f;
            g[e.dest][e.rev].cap += f;
        }
        if (res == 0) lev[x] = -1;
        return res;
    }
    int operator()(int s, int t) {
        int flow = 0;
        for (; bfs(s, t); flow += dfs(s, t, inf));
        return flow;
    }
} fl;

vector<pair<int,int>> G[500005];
pair<int,int> cp[333];

int pa[20][500005],dep[500005],match[333],id[500005];
long long dis[20][500005],tdis[500005];

void dfs(int now,int p,int d){
    dep[now]=d;
    pa[0][now]=p;
    for(int i=1;i<=19;++i){
        pa[i][now]=pa[i-1][pa[i-1][now]];
        dis[i][now]=dis[i-1][now]+dis[i-1][pa[i-1][now]];
    }
    for(auto &v:G[now])if(v.first!=p){
        tdis[v.first]=tdis[now]+v.second;
        dis[0][v.first]=v.second;
        dfs(v.first,now,d+1);
    }
}

pair<long long,int> getd(int u,int v){
    if(dep[u]>dep[v])swap(u,v);
    long long r=0;
    for(int i=19;i>=0;--i)if((dep[v]-dep[u])&(1<<i)){
        r+=dis[i][v];
        v=pa[i][v];
    }
    if(u==v)return make_pair(r,v);
    for(int i=19;i>=0;--i)if(pa[i][u]!=pa[i][v]){
        r+=dis[i][u]+dis[i][v];
        u=pa[i][u];
        v=pa[i][v];
    }
    return make_pair(r+dis[0][u]+dis[0][v],pa[0][u]);
}

long long getmid(int u,int v){
    long long tot; int a;
    tie(tot,a)=getd(u,v);
    // cout<<"tot: "<<tot<<endl;
    long long mn=max(tdis[u],tdis[v])-tdis[a];
    // cout<<"init mn: "<<mn<<endl;
    if(tdis[u]>tdis[v])swap(u,v);
    // cout<<"u v a: "<<u<<" "<<v<<" "<<a<<endl;
    // { int vv=v; while(vv!=a)cout<<dis[0][vv]<<" ",vv=pa[0][vv]; cout<<endl; }
    int step=21,x=v;
    while(step--){
        if(dep[x]-(1<<step)<=dep[a])continue;
        int to=pa[step][x];
        mn=min(mn,max(tdis[u]+tdis[to]-tdis[a]*2,tdis[v]-tdis[to]));
        if(tdis[v]-tdis[to]<=tot/2)x=to;
    }
    mn=min(mn,max(tdis[u]+tdis[x]-tdis[a]*2,tdis[v]-tdis[x]));
    if(x!=a)x=pa[0][x];
    mn=min(mn,max(tdis[u]+tdis[x]-tdis[a]*2,tdis[v]-tdis[x]));
    return mn;
}

long long cpd[333][333];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<n;++i){
        int u,v,w; cin>>u>>v>>w;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    for(int i=1;i<=m;++i)cin>>cp[i].first;
    for(int i=1;i<=m;++i)id[cp[i].first]=i;
    for(int i=1;i<=m;++i)cin>>cp[i].second;
    for(int i=1;i<=m;++i)id[cp[i].second]=-i;
    dfs(1,0,0);
    vector<pair<long long,pair<int,int>>> cpds;
    for(int i=1;i<=m;++i)for(int j=1;j<=m;++j){
        // cpd[i][j]=getd(cp[i].first,cp[j].second).first;
        cpd[i][j]=getmid(cp[i].first,cp[j].second);
        cpds.emplace_back(cpd[i][j],make_pair(i,j));
        // cout<<"d "<<cp[i].first<<" and "<<cp[j].second<<" = "<<cpd[i][j]<<endl;
    }
    for(int i=1;i<=m;++i)fl.add_edge(0,i,1);
    for(int i=1;i<=m;++i)fl.add_edge(i+300,604,1);
    int nf=0,skip=0;
    sort(cpds.begin(),cpds.end());
    for(auto &p:cpds){
        fl.add_edge(p.second.first,p.second.second+300,1);
        // cout<<"add edge "<<p.second.first<<" , "<<p.second.second<<" , skip: "<<skip<<endl;
        --skip; if(skip>0)continue;
        if((nf+=fl(0,604))==m){
            cout<<p.first*2<<endl;
            return 0;
        }
        skip=max(skip,m-nf);
    }
}
