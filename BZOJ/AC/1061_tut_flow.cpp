#include<bits/stdc++.h>
using namespace std;
#define ll long long

int need[1111];

struct edge{
    int u,v,f,c;
};
vector<edge> edg;
vector<int> G[1111];

void ae(int u,int v,int f,int c){
    // cout<<"add edge "<<u<<" "<<v<<" "<<f<<" "<<c<<endl;
    G[u].push_back(edg.size());
    edg.push_back({u,v,f,c});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0,-c});
}

int cf[1111],bn[1111];
ll d[1111];
bitset<1111> inq;
bool floww(int s,int t,ll &ncost,ll &nflow){
    queue<int> q; q.push(s);
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    memset(d,0x3f,sizeof(d)); d[s]=0;
    inq.reset(); inq[s]=1;
    while(q.size()){
        int now=q.front(); q.pop(); inq[now]=0;
        // cout<<"now: "<<now<<endl;
        for(int i=0;i<G[now].size();++i){
            int eid=G[now][i];
            edge &e=edg[eid];
            if(e.f && d[e.v]>d[e.u]+e.c){
                d[e.v]=d[e.u]+e.c;
                bn[e.v]=min(e.f,bn[now]);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    // cout<<bn[t]<<endl;
    if(!bn[t])return 0;
    ncost+=d[t]*bn[t];
    nflow+=bn[t];
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    // cout<<nflow<<" "<<ncost<<endl;
    return 1;
}

ll flow(int s,int t){
    ll cost=0,flow=0;
    while(floww(s,t,cost,flow));
    return cost;
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>need[i];
    }
    for(int i=1;i<=m;++i){
        int l,r,c; cin>>l>>r>>c;
        ae(l,r+1,0x3f3f3f3f,c);
    }
    for(int i=1;i<=n+1;++i){
        int f=need[i]-need[i-1];
        if(f>=0)ae(0,i,f,0);
        else ae(i,n+2,-f,0);
        if(i>1)ae(i,i-1,0x3f3f3f3f,0);
    }
    cout<<flow(0,n+2)<<endl;
}
