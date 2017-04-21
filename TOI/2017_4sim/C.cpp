#include<bits/stdc++.h>
using namespace std;

bool v[1000009];
vector<int> G[1000006],iG[1000006],tp,bG[1000006];
int sz[1000006],bel[1000006],dp[1000006];

void dfs1(int now){
    v[now]=1;
    for(int i:G[now]){
        if(!v[i])dfs1(i);
    }
    tp.push_back(now);
}
void dfs2(int now,int num){
    v[now]=1; sz[num]++; bel[now]=num;
    for(int i:iG[now]){
        if(!v[i])dfs2(i,num);
    }
}

void _dp(int now){
    if(v[now])return;
    v[now]=1; int bs=0;
    for(int i:bG[now]){
        _dp(i);
        bs=max(bs,dp[i]);
    }
    dp[now]=bs+sz[now];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        G[u].push_back(v);
        iG[v].push_back(u);
    }
    for(int i=0;i<n;++i){
        if(!v[i])dfs1(i);
    }
    reverse(tp.begin(),tp.end());
    memset(v,0,sizeof(v)); int cnt=0;
    for(int i=0;i<n;++i){
        if(!v[tp[i]]){
            dfs2(tp[i],cnt++);
        }
    }
    for(int i=0;i<n;++i){
        for(int ii:G[i]){
            if(bel[i]==bel[ii])continue;
            bG[bel[i]].push_back(bel[ii]);
        }
    }
    memset(v,0,sizeof(v));
    for(int i=0;i<cnt;++i){
        _dp(i);
    }
    int mx=0;
    for(int i=0;i<cnt;++i){
        mx=max(mx,dp[i]);
    }
    cout<<mx<<endl;
}
