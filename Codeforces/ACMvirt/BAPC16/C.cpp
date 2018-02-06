#include<bits/stdc++.h>
using namespace std;

vector<int> G[200007];
int leave[200007];
bitset<200007> jizz;

void dfs(int now){
    jizz[now]=1;
    for(int i:G[now]){
        if(jizz[i])continue;
        ++leave[i];
        if(leave[i]*2>=G[i].size()){
            dfs(i);
        }
    }
}

int main(){
    int n,m,x,l; cin>>n>>m>>x>>l;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(l);
    if(jizz[x])cout<<"leave"<<endl;
    else cout<<"stay"<<endl;
}
