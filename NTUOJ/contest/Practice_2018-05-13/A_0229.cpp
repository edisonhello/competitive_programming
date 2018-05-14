#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[10005];
double tot;
int sz[10005],n;

void dfsz(int now,int pa){
    for(auto i:G[now]){
        if(i.first==pa)continue;
        dfsz(i.first,now);
        sz[now]+=sz[i.first];
    }
    ++sz[now];
}
void dfs(int now,int pa){
    for(auto i:G[now]){
        if(i.first==pa)continue;
        dfs(i.first,now);
        tot+=(double)i.second*sz[i.first]*(n-sz[i.first]);
    }
}


int main(){
    int t; cin>>t; while(t--){
        cin>>n;
        for(int i=0;i<n;++i)G[i].clear();
        for(int i=1;i<n;++i){
            int u,v,c; cin>>u>>v>>c;
            G[u].emplace_back(v,c);
            G[v].emplace_back(u,c);
        }
        memset(sz,0,sizeof(sz));
        tot=0;
        dfsz(0,0);
        dfs(0,0);
        cout<<fixed<<setprecision(3)<<tot/n/(n-1)*2<<endl;
    }
}
