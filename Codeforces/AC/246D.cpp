#include<bits/stdc++.h>
using namespace std;

int c[100005];
set<int> Q[100005];

int main(){
    int n,m,mc=1<<29; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i],mc=min(mc,c[i]);
    while(m--){
        int u,v; cin>>u>>v;
        if(c[u]==c[v])continue;
        Q[c[u]].insert(c[v]);
        Q[c[v]].insert(c[u]);
    }
    int mx=0;
    for(int i=1;i<=100000;++i)mx=max(int(Q[i].size()),mx);
    int cl=0;
    for(int i=100000;i>=0;--i)if(mx==Q[i].size())cl=i;
    cout<<(cl?:mc)<<endl;
}
