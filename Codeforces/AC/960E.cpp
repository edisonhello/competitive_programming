#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

const ll mod=1000000007;

vector<int> G[200005];
int sif[200005][2];
ll val[200005],ans;

void dfs1(int now,int pa){
    sif[now][0]=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        sif[now][0]+=sif[i][1];
        sif[now][1]+=sif[i][0];
    }
}
void dfs2(int now,int pa,int up0,int up1){
    // cout<<"dfsing now: "<<now<<" , up: "<<up0<<" , "<<up1<<endl;
    int tot0=up0+1,tot1=up1;
    for(int i:G[now]){
        if(i==pa)continue;
        tot0+=sif[i][1];
        tot1+=sif[i][0];
    }
    ans+=1ll*(up0-up1)*(tot0+tot1-up0-up1)%mod*val[now]%mod;
    ans=(ans%mod+mod)%mod;
    for(int i:G[now]){
        if(i==pa)continue;
        ans+=1ll*(sif[i][1]-sif[i][0])*(tot0+tot1-sif[i][0]-sif[i][1])%mod*val[now]%mod;
        ans=(ans%mod+mod)%mod;
    }
    // cout<<"after, ans: "<<ans<<endl;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs2(i,now,tot1-sif[i][0],tot0-sif[i][1]);
    }
}

int32_t main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>val[i];
    for(int i=1;i<=n;++i){
        ans+=val[i]*n%mod;
        ans=(ans%mod+mod)%mod;
    }
    // cout<<"nans: "<<ans<<endl;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,1);
    dfs2(1,1,0,0);
    cout<<(ans%mod+mod)%mod<<endl;
}
