#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005],tp;
int ind[100005],pa[100005];

int main(){
    ios_base::sync_with_stdio(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<n+m;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        ++ind[v];
    }
    queue<int> q;
    for(int i=1;i<=n;++i)if(ind[i]==0)q.push(i);
    while(q.size()){
        int now=q.front(); q.pop();
        tp.push_back(now);
        for(int i:G[now])--ind[i];
        for(int i:G[now])if(ind[i]==0){
            q.push(i);
            pa[i]=now;
        }
    }
    for(int i=1;i<=n;++i)cout<<pa[i]<<'\n';
}
