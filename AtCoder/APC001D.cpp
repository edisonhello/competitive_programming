#include<bits/stdc++.h>
using namespace std;

int w[100005],d[100005];
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
    auto cmp=[&](const int &a,const int &b){ return tie(pq[a].top(),a)<tie(pq[b].top(),b); };
    set<int,decltype(cmp)> g(cmp);
    for(int i=1;i<=n;++i)g.insert(f(i));
    long long ans=0;
    while(g.size()>1u){
        int u=*g.begin(); g.erase(g.begin());
        int v=*g.begin(); g.erase(g.begin());
        if(pq[u].empty() || pq[v].empty()){ exit((cout<<"Impossible"<<endl,0)); }
        if(pq[u].size()<pq[v].size())swap(u,v);
        ans+=pq[u].top()+pq[v].top();
        pq[u].pop(); pq[v].pop();
        while(pq[v].size()){
            pq[u].push(pq[v].top());
            pq[v].pop();
        }
        d[v]=u;
        if(pq[u].empty()){
            if(g.empty())break;
            else{ exit((cout<<"Impossible"<<endl,0)); }
        }
        g.insert(u);
    }   
    cout<<ans<<endl;
}
