#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> G[100005];
int clr[100005];

void dfs(int now,int c){
    clr[now]=c;
    for(int i:G[now]){
        if(clr[i]==c)exit((cout<<-1<<endl,0));
        if(!clr[i])dfs(i,3-c);
    }
}

int main(){
    int n,m; cin>>n>>m; while(m--){
        int u,v; cin>>u>>v;
        G[u].pb(v);
        G[v].pb(u);
    }
    for(int i=1;i<=n;++i)if(!clr[i])dfs(i,1);
    vector<int> c[3];
    for(int i=1;i<=n;++i)c[clr[i]].pb(i);
    cout<<c[1].size()<<endl;
    for(int i:c[1])cout<<i<<" "; cout<<endl;
    cout<<c[2].size()<<endl;
    for(int i:c[2])cout<<i<<" "; cout<<endl;
}
