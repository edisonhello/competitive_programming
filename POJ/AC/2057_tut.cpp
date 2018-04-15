#include<iostream>
#include<iomanip>
#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstring>
using namespace std;

vector<int> G[1002];
int lef[1002],dp[1002][1<<8],fal[1002],mlef[1002][1<<8];
bitset<1002> wr;

void dfs(int now){
    if(G[now].empty()){
        lef[now]=1;
        dp[now][0]=0;
        return;
    }
    for(int i=0;i<G[now].size();++i){
        dfs(G[now][i]);
        lef[now]+=lef[G[now][i]];
        fal[now]+=fal[G[now][i]]+2;
    }
    if(wr[now])fal[now]=0;
    dp[now][0]=0;
    for(int i=1;i<(1<<G[now].size());++i){
        for(int j=0;j<G[now].size();++j){
            if(i&(1<<j)){
                dp[now][i]=min(dp[now][i],dp[now][i^(1<<j)]+dp[G[now][j]][(1<<G[G[now][j]].size())-1]+lef[G[now][j]]+(fal[G[now][j]]+2)*mlef[now][i^(1<<j)]);
                mlef[now][i]+=lef[G[now][j]];
            }
        }
        // cout<<"dp["<<now<<"]["<<i<<"] = "<<dp[now][i]<<endl;
    }
}

int main(){
    int n; while(cin>>n,n){
        for(int i=1;i<=n;++i)G[i].clear();
        wr.reset();
        memset(lef,0,sizeof(lef));
        memset(mlef,0,sizeof(mlef));
        memset(dp,0x3f,sizeof(dp));
        memset(fal,0,sizeof(fal));
        for(int i=1;i<=n;++i){
            int p; char w; cin>>p>>w;
            if(p>0)G[p].push_back(i);
            else assert(i==1);
            wr[i]=(w=='Y');
        }
        dfs(1);
        cout<<fixed<<setprecision(4)<<(double)dp[1][(1<<G[1].size())-1]/lef[1]<<endl;
        // printf("%.4lf\n", 1. * suc[1] / lef[1]);
    }
}
