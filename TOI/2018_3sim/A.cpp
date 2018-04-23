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

//    dp=new int*[n+5];
//    vis=new bool*[n+5];
//    for(int i=0;i<n+5;++i){
//        dp[i]=new int[k+10];
//        vis[i]=new bool[k+10];
//        for(int j=0;j<k+10;++j)dp[i][j]=0,vis[i][j]=0;
//    }

    while(m--){
        int u,v,t; cin>>u>>v>>t;
        G[u].emplace_back(v,t);
        G[v].emplace_back(u,t);
        edge[u][v]=edge[v][u]=t;
    }

    dij(s,t);

//    int ans=dfs(s,min(k,n*n+10*n));
//    if(n*n+10*n>=k)cout<<ans<<endl;
//    else{
//        int aans=0;
//        for(int lp=1;lp<=n*10;++lp){
//            int maxk=n*n+10*n;
//            int leftk=k-maxk;
//            while(leftk%lp)--maxk,++leftk;
////            cout<<lp<<" "<<maxk<<" "<<leftk<<endl;
//            aans=max(aans,dp[s][maxk-lp+1]+(dp[s][maxk]-dp[s][maxk-lp])*((leftk)/lp));
//        }
//        cout<<aans<<endl;
//    }



    cout<<dfs(s,k)<<endl;
    for(int i=0;i<=k;++i)cout<<dp[s][i]<<endl;
    for(int i=1;i<=k;++i)cout<<dp[s][i]-dp[s][i-1]<<endl;


    /* for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
        dp[i][j][0]=max(dp[i][j][0],dp[i][k][0]+dp[k][j][0]);

    for(int z=1;z<=k;++z){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j][z]
            }
        }
    } */
}
