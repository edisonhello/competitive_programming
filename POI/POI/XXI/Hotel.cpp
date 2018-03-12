#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> G[5555];
vector<int> dep[5555];

void dfs(int now,int pa,int d,vector<int> &ds){
    if(ds.size()==d)ds.push_back(1);
    else ++ds[d];
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,d+1,ds);
    }
}

int main(){
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans=0;
    for(int i=1;i<=n;++i){
        memset(dep,0,sizeof(dep));
        for(int ii:G[i]){
            vector<int> ds;
            dfs(ii,i,0,ds);
            for(int i=0;i<ds.size();++i)dep[i].push_back(ds[i]);
        }
        for(int i=0;i<=n;++i){
            if(dep[i].empty())break;
            ll tot=0;
            for(int ii:dep[i])tot+=ii;
            ans+=tot*(tot-1)*(tot-2)/6;
            for(int ii=0;ii<dep[i].size();++ii){
                ans-=(tot-dep[i][ii])*(dep[i][ii]-1)*dep[i][ii]/2;
                ans-=1ll*(dep[i][ii]-2)*(dep[i][ii]-1)*dep[i][ii]/6;
            }
            dep[i].clear();
        }
    }
    cout<<ans<<endl;
}
