#include<bits/stdc++.h>
using namespace std;

int t[10004],g[10004],p[10004],a[10004],b[10004];
int acs[104],da[104][16];
int pnl[104],dp[104][16];
vector<int> subs[104][16];

void sol(){
    int n,m,s,k; cin>>n>>m>>s>>k;
    for(int i=0;i<104;++i)for(int j=0;j<16;++j)subs[i][j].clear();
    memset(pnl,0,sizeof(pnl));
    memset(acs,0,sizeof(acs));
    for(int i=1;i<=s;++i)cin>>t[i]>>g[i]>>p[i]>>a[i]>>b[i],++g[i];
    for(int i=1;i<=s;++i)subs[g[i]][p[i]].push_back(i);
    for(int i=1;i<=n;++i)for(int j=0;j<m;++j){
        int op=-1,np=-1,wa=0;
        for(int z:subs[i][j])if(a[z]==0)++wa; else{ op=t[z]; break; }
        if(~op)op+=wa*20; 
        wa=0; 
        for(int z:subs[i][j])if(b[z]==0)++wa; else{ np=t[z]; break; }
        if(~np)np+=wa*20;

        if(~op && ~np)++acs[i],da[i][j]=0,pnl[i]+=op,dp[i][j]=np-op;
        else if(~op)++acs[i],da[i][j]=-1,pnl[i]+=op,dp[i][j]=-op;
        else if(~np)da[i][j]=1,dp[i][j]=np;
        else da[i][j]=dp[i][j]=0;
    }
    int rank=7122;
    for(int z=0;z<(1<<m);++z)if(int(bitset<16>(z).count())<=k){
        // cout<<bitset<16>(z)<<endl;
        vector<pair<int,int>> stn(n);
        for(int i=1;i<=n;++i){
            int t=pnl[i],ac=acs[i];
            for(int j=0;j<m;++j){
                if(z&(1<<j))t+=dp[i][j],ac+=da[i][j];
            }
            stn[i-1]={ac,t};
            // cout<<"pt "<<i<<" = "<<t<<" , ac = "<<ac<<endl;
        }
        int r=0;
        for(int i=1;i<n;++i)if(stn[i].first>stn[0].first || (stn[i].first==stn[0].first && stn[i].second<stn[0].second))++r;
        rank=min(rank,r+1);
    }
    cout<<rank<<endl;
}

int main(){
    int t; cin>>t; while(t--)sol();
}
