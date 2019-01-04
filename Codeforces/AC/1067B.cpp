#include<bits/stdc++.h>
using namespace std;
#define kill jsj

set<int> G[100005];
vector<int> G2[100005];
set<int> pa,kill;
int cnt[100005],skip[100005];

void dfs(int now,int pa,int k){
    if(k==0){
        if(G2[now].size()!=1u)exit((cout<<"No"<<endl,0));
        return;
    }
    if(G2[now].size()<4u)exit((cout<<"No"<<endl,0));
    for(int i:G2[now]){
        if(i==pa)continue;
        dfs(i,now,k-1);
    }
}

int main(){
    int n,k; cin>>n>>k;
    if(k>10)exit((cout<<"No"<<endl,0));
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
        G2[u].push_back(v);
        G2[v].push_back(u);
    }
    for(int i=0;i<k;++i){
        kill.clear();
        pa.clear();
        for(int i=1;i<=n;++i){
            if(skip[i])continue;
            if(G[i].size()==1u){
                kill.insert(i);
                pa.insert(*G[i].begin());
                ++cnt[*G[i].begin()];
            }
        }
        // cout<<"kill: "; for(int i:kill)cout<<i<<" "; cout<<endl;
        // cout<<"pa  : "; for(int i:pa)cout<<i<<" "; cout<<endl;
        for(int i:kill){
            if(pa.find(i)!=pa.end())exit((cout<<"No"<<endl,0));
        }
        for(int i:pa){
            if(cnt[i]<3)exit((cout<<"No"<<endl,0));
        }
        // if(pa.size()<3u)exit((cout<<"No"<<endl,0));
        for(int i:kill){
            skip[i]=1;
            G[*G[i].begin()].erase(i);
        }
    }
    int stay=0;
    for(int i=1;i<=n;++i)if(!skip[i])++stay;
    if(stay!=1)exit((cout<<"No"<<endl,0));
    for(int i=1;i<=n;++i){
        if(!skip[i]){
            G2[i].push_back(0);
            dfs(i,0,k);
        }
    }
    cout<<"Yes"<<endl;
}
