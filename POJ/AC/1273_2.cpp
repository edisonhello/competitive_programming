#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
#define int long long

struct edge{
    int u,v;
    ll f;
    edge(int u,int v,ll f):u(u),v(v),f(f){}
};

vector<edge> edg;
vector<int> G[5005];
ll w[5005];

void ae(int u,int v,ll f){
    G[u].push_back(edg.size());
    edg.push_back(edge(u,v,f));
    G[v].push_back(edg.size());
    edg.push_back(edge(v,u,0));
}

int vis[5005],d[5005];
bool bfs(int s,int t,int bid){
    queue<int> q; q.push(s); vis[s]=bid;
    d[s]=0;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i=0;i<G[now].size();++i){
            edge &e=edg[G[now][i]];
            if(e.f>0 && vis[e.v]!=bid){
                vis[e.v]=bid;
                q.push(e.v);
                d[e.v]=d[now]+1;
            }
        }
    }
    return vis[t]==bid;
}

int cur[5005];
ll dfs(int now,int t,ll mx){
    if(!mx)return mx;
    if(now==t)return mx;
    ll rt=0,f;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        if(e.f && d[e.v]==d[now]+1 && (f=dfs(e.v,t,min(mx,e.f)))){
            mx-=f;
            rt+=f;
            e.f-=f;
            edg[G[now][i]^1].f+=f;
        }
    }
    return rt;
}

ll flow(int s,int t){
    ll f=0; int bid=0;
    while(bfs(s,t,++bid)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,1ll<<50);
        memset(d,0,sizeof(d));
    }
    return f;
}

main(){
    int n,m; while(cin>>m>>n){
        edg.clear();
        for(int i=0;i<5005;++i)G[i].clear();
        memset(w,0,sizeof(w));
        memset(vis,0,sizeof(vis));
        memset(d,0,sizeof(d));


	    while(m--){
	        int u,v,w; cin>>u>>v>>w;
	        ae(u,v,w);
	    }
	    ll f=flow(1,n);
        cout<<f<<endl;
	}
}
