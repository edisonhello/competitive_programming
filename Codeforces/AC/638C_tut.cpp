#include<bits/stdc++.h>
using namespace std;
#define fixed iiisooso

vector<pair<int,int>> G[200005];
vector<int> work[200005];
int mxday;

void dfs(int now,int pa,int pud){
    int nt=1;
    for(auto i:G[now]){
        if(i.first==pa)continue;
        if(nt==pud)++nt;
        work[nt].push_back(i.second);
        mxday=max(mxday,nt);
        dfs(i.first,now,nt);
        ++nt;
    }
}

int main(){
    int n; cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].emplace_back(v,i);
        G[v].emplace_back(u,i);
    }
    dfs(1,1,0);
    cout<<mxday<<'\n';
    for(int i=1;i<=mxday;++i){
        cout<<work[i].size();
        for(int j:work[i])cout<<" "<<j;
        cout<<'\n';
    }
}
