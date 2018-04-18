#include<bits/stdc++.h>
using namespace std;

double w[2555],dp[2555][2];
vector<pair<int,int>> edg;
vector<int> G[2555];
int djs[2555];
bitset<2555> v;

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

void dfs(int now,int pa){
    // cout<<"dfs "<<now<<endl;
    dp[now][0]=0;
    dp[now][1]=w[now];
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
        dp[now][0]=max(dp[now][0],max(dp[i][1],dp[i][0]));
        dp[now][1]+=max(0.,dp[i][1]);
    }
    // cout<<dp[now][0]<<" "<<dp[now][1]<<endl;
}

int main(){
    srand(time(0));
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>w[i]>>w[i];
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        edg.emplace_back(u,v);
    }
    // int cnt=10000;
    double ans=0;
    long long run=0;
    while(1){
        ++run;
        // random_shuffle(edg.begin(),edg.end());
        for(int i=0;i<10;++i)swap(edg[rand()%edg.size()],edg[rand()%edg.size()]);
        for(int i=1;i<=n;++i)djs[i]=i;
        for(int i=1;i<=n;++i)G[i].clear();
        // cout<<"meow"<<endl;
        for(auto &e:edg){
            if(F(e.first)==F(e.second))continue;
            if(w[e.first]<0 || w[e.second]<0)continue;
            U(e.first,e.second);
            G[e.first].push_back(e.second);
            G[e.second].push_back(e.first);
        }
        for(auto &e:edg){
            if(F(e.first)==F(e.second))continue;
            U(e.first,e.second);
            G[e.first].push_back(e.second);
            G[e.second].push_back(e.first);
        }
        memset(dp,0,sizeof(dp));
        dfs(1,1);
        double na=max(dp[1][0],dp[1][1]);
        if(na>ans){
            ans=na;
            cout<<"now answer: "<<fixed<<setprecision(10)<<na<<endl;
        }
        if((run&((1<<14)-1))==0)cout<<"run "<<run<<endl;
    }
}
