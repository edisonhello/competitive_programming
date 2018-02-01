#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int k,x,m;
vector<int> G[100005];
ll dp[100005][3][11],tmp[3][11];

void dfs(int now,int pa){
    for(int i:G[now]){
        if(i!=pa)dfs(i,now);
    }

    dp[now][0][0]=k-1;
    dp[now][1][1]=1;
    dp[now][2][0]=m-k;
    for(int i:G[now]){
        if(i==pa)continue;
        // cout<<"now: "<<now<<" , "<<"i: "<<i<<endl;
        memset(tmp,0,sizeof(tmp));
        for(int xx=0;xx<=x;++xx){
            for(int xi=0;xi<=xx;++xi){
                tmp[0][xx]=(tmp[0][xx]+dp[now][0][xx-xi]*(dp[i][0][xi]+dp[i][1][xi]+dp[i][2][xi])%mod)%mod;
                if(xx!=xi)tmp[1][xx]=(tmp[1][xx]+dp[now][1][xx-xi]*(dp[i][0][xi])%mod)%mod;
                tmp[2][xx]=(tmp[2][xx]+dp[now][2][xx-xi]*(dp[i][0][xi]+dp[i][2][xi])%mod)%mod;
            }
        }
        for(int tp=0;tp<3;++tp)for(int xx=0;xx<=x;++xx)dp[now][tp][xx]=tmp[tp][xx];
    }
    /* for(int xx=0;xx<=x;++xx){
        cout<<"now: "<<now<<" , "<<dp[now][0][xx]<<" "<<dp[now][1][xx]<<" "<<dp[now][2][xx]<<endl;
    } */
}

int main(){
    int n; cin>>n>>m;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin>>k>>x;
    dfs(1,1);
    ll ans=0;
    for(int i=0;i<3;++i)for(int j=0;j<=x;++j)ans+=dp[1][i][j];
    cout<<ans%mod<<endl;
}
