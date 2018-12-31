#include<bits/stdc++.h>
using namespace std;

struct e{
    int v,w,i;
};
vector<e> G[300005];
bitset<300005> v;
int uedg[300005];
long long d[300005];

void dij(int s,int k){
    memset(d,0x3f,sizeof(d)); d[s]=0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    pq.emplace(0,s);
    while(pq.size() && k>0){
        while(pq.size() && v[pq.top().second])pq.pop();
        int now=pq.top().second;
        v[now]=1; --k;
        // cout<<"add "<<now<<endl;
        for(auto edg:G[now]){
            if(v[edg.v])continue;
            if(d[edg.v]>d[now]+edg.w){
                d[edg.v]=d[now]+edg.w;
                uedg[edg.v]=edg.i;
                pq.emplace(d[edg.v],edg.v);
            }
        }
    }
}

int main(){
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w; cin>>u>>v>>w;
        G[u].push_back({v,w,i});
        G[v].push_back({u,w,i});
    }
    dij(1,k+1);
    vector<int> ans;
    for(int i=2;i<=n;++i)if(v[i])ans.push_back(uedg[i]);
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
