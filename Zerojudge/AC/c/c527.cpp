#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<int,ll>> G[500005];
int bus[500005];
ll dp[500005];
vector<pair<ll,int>> del[500005];
int subbus[500005];
ll ans[500005];

void dfs_bus(int now,int pa){
    subbus[now]|=bus[now];
    for(auto i:G[now]){
        if(i.first==pa)continue;
        dfs_bus(i.first,now);
        subbus[now]+=subbus[i.first];
    }
}

void dfs(int now,int pa){
    if(G[now].size()==1u && now!=pa){return;}
    for(auto i:G[now]){
        if(i.first==pa)continue;
        dfs(i.first,now);
        if(subbus[i.first]){
            dp[now]+=dp[i.first]+2*i.second;
            del[now].emplace_back(dp[i.first]+2*i.second-(dp[i.first]-(del[i.first].size()?del[i.first][0].first:0))-i.second,i.first);
            sort(del[now].begin(),del[now].end(),greater<pair<ll,int>>());
            while(del[now].size()>2u)del[now].pop_back();
        }
    }
    // cout<<"dp["<<now<<"] is "<<dp[now]<<endl;
    // cout<<"del: "; for(auto i:del[now])cout<<"("<<i.first<<","<<i.second<<") "; cout<<endl;
}
void sdf(int now,int pa,ll backcost,ll leavecost){
    // cout<<"sdf "<<now<<" backcost: "<<backcost<<" , leavecost: "<<leavecost<<endl;
    ans[now]=min(dp[now]-(del[now].size()?del[now][0].first:0)+backcost,dp[now]+leavecost);
    for(auto i:G[now]){
        if(i.first==pa)continue;
        if(i.first==3 && now==1){
            // cout<<"front: "<<leavecost+dp[now]-(subbus[i.first]?dp[i.first]+2*i.second:0)<<endl;
        }
        sdf(i.first,now,
            backcost+dp[now]-
                (subbus[i.first]?dp[i.first]+2*i.second:0)+
                (subbus[1]>subbus[i.first]?2*i.second:0),
            min(leavecost+dp[now]-(subbus[i.first]?dp[i.first]+2*i.second:0),
                backcost+dp[now]-(subbus[i.first]?dp[i.first]+2*i.second:0)-
                    ((del[now].size() && del[now][0].second==i.first)?
                        (del[now].size()>1u?del[now][1].first:0):
                        (del[now].size()?del[now][0].first:0)))
            +(subbus[1]>subbus[i.first]?i.second:0));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,u,v,c;i<n;++i){
        cin>>u>>v>>c;
        G[u].emplace_back(v,c);
        G[v].emplace_back(u,c);
    }
    for(int i=1;i<=n;++i)cin>>bus[i];
    dfs_bus(1,1);
    dfs(1,1);
    sdf(1,1,0,0);
    for(int i=1;i<=n;++i)if(!bus[i])cout<<ans[i]<<endl;
}
