#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

bitset<123> v,inr;
int d[123],cf[123],cdep[123],police;
vector<int> G[123],dG[123];
ll dp[123];

void dfs(int now,int ddd){
    inr[now]=1;
    for(int i:G[now]){
        if(d[i]==ddd-1){
            dG[i].push_back(now);
            if(!inr[i])dfs(i,ddd-1);
        }
    }
}

void go(int now){
    // cout<<"go "<<now<<endl;
    if(v[now])return;
    v[now]=1;
    for(int i:dG[now]){
        go(i);
        dp[now]+=dp[i];
    }
}

void _go(int now){
    if(v[now])return;
    v[now]=1;
    for(int i:dG[now]){
        _go(i);
        if(d[i]==d[police]){
            if(i==police)dp[now]+=dp[i];
        }
        else dp[now]+=dp[i];
    }
}

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    queue<int> q; q.push(1); v[1]=1;
    while(q.size()){
        for(int i:G[q.front()]){
            if(i==cf[q.front()])continue;
            if(v[i])continue;
            d[i]=d[q.front()]+1;
            q.push(i);
            v[i]=1;
            cf[i]=q.front();
        }
        q.pop();
    }
    // cout<<"d: "; for(int i=1;i<=n;++i)cout<<d[i]<<" "; cout<<endl;
    dfs(n,d[n]);
    for(int i=1;i<=n;++i)if(inr[i])++cdep[d[i]];
    ld ans=0;
    dp[n]=1;
    v.reset();
    go(1);
    ll allroute=dp[1];
    ans=1;
    // cout<<"all route: "<<allroute<<endl;
    for(int i=2;i<n;++i){
        if(!inr[i])continue;
        memset(dp,0,sizeof(dp));
        police=i;
        dp[n]=1;
        v.reset();
        _go(1);
        // cout<<"dp[1]: "<<dp[1]<<endl;
        ans=max(ans,(ld)dp[1]*2/allroute);
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
