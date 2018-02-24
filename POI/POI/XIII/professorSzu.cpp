#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<int> G[1000006],memb[1000006];
bitset<1000006> v;
int bel[1000006],dp[1000006],n;

void dfs(int now){
    v[now]=1;
    for(int i:G[now]){
        if(!v[i])dfs(i);
    }
    tp.push_back(now);
}

void idfs(int now,int ccn){
    v[now]=1;
    bel[now]=ccn;
    ++sz[ccn];
    memb[ccn].push_back(now);
    for(int i:iG[now]){
        if(!v[i])idfs(i,ccn);
    }
}

void cdfs(int now){
    v[now]=1;
    for(int i:icG[now]){
        if(!v[i])cdfs(i);
    }
}

int dpdfs(int now){
    if(v[now])return dp[now];
    v[now]=1;
    dp[now]=(now==n);
    for(int i:G[now]){
        dp[now]+=dpdfs(i);
        if(dp[now]>36500)dp[now]=36501;
    }
    cout<<now<<" "<<dp[now]<<endl;
    return dp[now];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m; cin>>n>>m; ++n;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;++i)if(!v[i])dfs(i); v.reset();
    reverse(tp.begin(),tp.end()); int cc=0;
    for(int i:tp){
        if(!v[i]){
            idfs(i,++cc);
        }
    }
    --cc;
    for(int i=1;i<=n;++i){
        for(int j:iG[i]){
            icG[i].push_back(j);
        }
    }
    v.reset();
    cdfs(n);
    bool hascircle=0;
    vector<int> incirclelist;
    for(int i=1;i<=cc;++i){
        if(v[i] && sz[i]>1){
            hascircle=1;
        }
        if(hascircle){
            for(int ii:memb[i])incirclelist.push_back(ii);
        }
    }
    if(hascircle){
        cout<<"zawsze"<<endl;
        cout<<incirclelist.size()<<endl;
        v.reset();
        for(int i:incirclelist)v[i]=1;
        for(int i=1;i<n;++i)if(v[i])cout<<i<<" ";
        cout<<endl;
        exit(0);
    }
    v.reset();
    for(int i=1;i<n;++i){
        if(iG[i].size())continue;
        dp[i]=dpdfs(i);
    }
    int mxdp=-1,ans=0;
    for(int i=1;i<n;++i){
        mxdp=max(mxdp,dp[i]);
    }
    v.reset();
    for(int i=1;i<n;++i){
        if(dp[i]==mxdp)v[i]=1,++ans;
    }
    if(mxdp<=36500)cout<<mxdp<<endl;
    else cout<<"zawsze"<<endl;
    cout<<ans<<endl;
    for(int i=1;i<n;++i)if(v[i])cout<<i<<" "; cout<<endl;
}
