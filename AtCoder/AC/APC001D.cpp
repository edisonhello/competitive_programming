#include<bits/stdc++.h>
using namespace std;

int w[100005],d[100005],z[100005];
int f(int x){ return d[x]==x?x:d[x]=f(d[x]); }

priority_queue<int,vector<int>,greater<int>> pq[100005];

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n;++i)d[i]=i;
    while(m--){
        int u,v; cin>>u>>v; ++u, ++v;
        d[f(u)]=f(v);
    }
    for(int i=1;i<=n;++i)pq[f(i)].push(w[i]);
    for(int i=1;i<=n;++i)z[i]=i;
    sort(z+1,z+1+n,[&](const int &a,const int &b){ return pq[a].size()>pq[b].size(); });
    long long ans=0;
    for(int x=2;x<=n;++x){
        int i=z[x];
        if(pq[i].size() && !pq[z[1]].size())exit((cout<<"Impossible"<<endl,0));
        if(pq[i].empty())continue;
        ans+=pq[i].top()+pq[z[1]].top();
        pq[i].pop(); pq[z[1]].pop();
        while(pq[i].size()){ pq[z[1]].push(pq[i].top()); pq[i].pop(); }
    }
    cout<<ans<<endl;
}
