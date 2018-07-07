#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[18];
int dp[1<<18],cf[1<<18],rec[18][1<<18],go[18][1<<18];
bitset<(1<<18)> v[18];

int dfs(int le,int now,int ss){
    // cout<<"dfs "<<le<<" "<<now<<" "<<ss<<endl;
    if(v[now][le])return rec[now][le];
    if(le==0)return 0;
    rec[now][le]=1e9;
    v[now][le]=1;
    int mn=1e9;
    for(auto i:G[now]){
        if((1<<i.first)&ss){
            int nv=dfs(le&(1<<i.first)?le^(1<<i.first):le,i.first,ss)+i.second;
            if(nv<mn){
                mn=nv;
                go[now][le]=i.first;
            }
        }
    }
    // cout<<"go["<<now<<"]["<<le<<"] = "<<go[now][le]<<endl;
    // cout<<"rec["<<now<<"]["<<le<<"] = "<<mn<<endl;
    return rec[now][le]=mn;
}

int main(){
    // freopen("immediate.in","r",stdin);
    // freopen("immediate.out","w",stdout);
    memset(go,-1,sizeof(go));
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w; --u, --v;
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    for(int i=0;i<(1<<n);++i){
        if(i&1); else continue;
        dp[i]=dfs(i^1,0,i);
        cf[i]=i;
        // cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<(1<<n);++j){
            if(j&(1<<i))continue;
            if(dp[j^(1<<i)]<dp[j]){
                dp[j]=dp[j^(1<<i)];
                cf[j]=cf[j^(1<<i)];
            }
        }
    }
    int ans=INT_MAX,cf1=-1,cf2=-1;
    for(int i=0;i<(1<<n);++i){
        if(i&1); else continue;
        if(max(dp[i],dp[((1<<n)-2)^i])<ans){
            ans=max(dp[i],dp[((1<<n)-2)^i]);
            cf1=cf[i]; cf2=cf[((1<<n)-2)^i];
        }
    }
    // cout<<"cf1 cf2: "<<cf1<<" "<<cf2<<endl;
    cout<<ans<<endl;
    auto meow=[&](int le){
        int now=0;
        vector<int> rec;
        while(go[now][le]!=-1){
            tie(now,le)=make_pair(go[now][le],le&(1<<go[now][le])?le^(1<<go[now][le]):le);
            rec.push_back(now);
            // cout<<"now, le: "<<now<<" "<<le<<endl;
        }
        cout<<rec.size()<<" 1";
        for(int i:rec)cout<<" "<<i+1;
        cout<<endl;
    };
    meow(cf1^1); meow(cf2^1);
}
