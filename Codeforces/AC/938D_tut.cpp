#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<200005> v;
vector<pair<int,ll>> G[200005];
ll cost[200005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; ll w; cin>>u>>v>>w;
        G[u].emplace_back(v,w<<1);
        G[v].emplace_back(u,w<<1);
    }
    for(int i=1;i<=n;++i)cin>>cost[i];
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    for(int i=1;i<=n;++i)pq.emplace(cost[i],i);
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int np=pq.top().second; pq.pop();
        v[np]=1;
        for(auto e:G[np]){
            if(cost[e.first]>cost[np]+e.second){
                cost[e.first]=cost[np]+e.second;
                pq.emplace(cost[e.first],e.first);
            }
        }
    }
    for(int i=1;i<=n;++i)cout<<cost[i]<<" "; cout<<endl;
}
