#include<bits/stdc++.h>
using namespace std;
#define int int_fast64_t
#define X first
#define Y second

//bool v[222],**vis;
 bitset<44444> v,vis[222];
 int dp[222][44444],d[222],to[222],s,t,edge[222][44444];
//int **dp,d[222],to[222],s,t,edge[222][222];

vector<pair<int,int>> G[222];

void dij(int s,int t){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,t});
    memset(d,0x3f,sizeof(d)); d[t]=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        v[now]=1;
        for(auto e:G[now]){
            if(d[e.first]>d[now]+e.second){
                to[e.first]=now;
                d[e.first]=d[now]+e.second;
                pq.push({d[e.first],e.first});
            }
        }
    }
}

int dfs(int now,int k){
    if(t==now)return 0;
    if(vis[now][k])return dp[now][k];
    vis[now][k]=1;
    int &val=dp[now][k];
    val=dfs(to[now],k)+edge[now][to[now]];
    if(k)for(auto e:G[now]){
        val=max(val,dfs(e.first,k-1)+e.second);
    }
    return val;
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    int n,m,k; cin>>n>>m>>s>>t>>k;

    while(m--){
        int u,v,t; cin>>u>>v>>t;
        G[u].emplace_back(v,t);
        G[v].emplace_back(u,t);
        edge[u][v]=edge[v][u]=t;
    }
    dij(s,t);

    // cout<<"bf answer: "<<dfs(s,k)<<endl;
    // for(int i=0;i<=k;++i)cout<<"k: "<<i<<" , "<<dp[s][i]<<endl;

    int ans=dfs(s,min(k,n*5));
    if(n*5>=k)cout<<ans<<endl;
    else{
        int aans=0;
        vector<int> el;
        for(int i=n*3;i<=n*5;++i)el.push_back(dp[s][i]-dp[s][i-1]);
        // cout<<"el: "; for(int i:el)cout<<i<<" "; cout<<endl;
        for(int lpz=1;lpz<=n*2;++lpz){
            bool no=0;
            for(int l=0,r=lpz-1;r<el.size();l+=lpz,r+=lpz){
                for(int j=0;j<lpz;++j){
                    if(el[j]!=el[l+j])no=1;
                }
                if(no)break;
            }
            if(no)continue;
            int pp=dp[s][n*3];
            int mul=(k-n*3)/lpz;
            pp+=mul*(dp[s][n*3+lpz]-dp[s][n*3]);
            int le=(k-n*3)%lpz;
            pp+=dp[s][n*3+le]-dp[s][n*3];
            aans=max(aans,pp);
            break;
        }
        cout<<max(aans,d[s])<<endl;
    }
}
