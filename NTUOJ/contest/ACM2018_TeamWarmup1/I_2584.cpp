#include<bits/stdc++.h>
using namespace std;

int pa[1004],pb[1004];
vector<int> da,db;
vector<int> Ga[1004],Gb[1004];
char ca[1004],cb[1004];
int dp[1004][1004];

void dfsa(int now,int p){
    da.push_back(now);
    pa[now]=p;
    for(int i:Ga[now]){
        if(i==p)continue;
        dfsa(i,now);
    }
}
void dfsb(int now,int p){
    db.push_back(now);
    pb[now]=p;
    for(int i:Gb[now]){
        if(i==p)continue;
        dfsb(i,now);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        da.clear(); db.clear();
        da.push_back(0); db.push_back(0);
        for(int i=1;i<=n;++i)Ga[i].clear();
        for(int i=1;i<=m;++i)Gb[i].clear();
        memset(dp,0,sizeof(dp));

        cin>>(ca+1);
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            Ga[u].push_back(v);
            Ga[v].push_back(u);
        }
        cin>>(cb+1);
        for(int i=1,u,v;i<m;++i){
            cin>>u>>v;
            Gb[u].push_back(v);
            Gb[v].push_back(u);
        }
        dfsa(1,0);
        dfsb(1,0);

        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(ca[da[i]]==cb[db[j]])dp[da[i]][db[j]]=dp[pa[da[i]]][pb[db[j]]]+1;
                dp[da[i]][db[j]]=max(dp[da[i]][db[j]],max(dp[pa[da[i]]][db[j]],dp[da[i]][pb[db[j]]]));
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)ans=max(ans,dp[i][j]);
        cout<<ans<<endl;
    }
}
