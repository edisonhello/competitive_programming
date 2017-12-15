#include<bits/stdc++.h>
using namespace std;

vector<int> odd;
int d[1004][1004],deg[1004],match[22],dp[1<<21],totwei;

int dfs(int x,int now){
    if(dp[x])return dp[x];
    if(x==0)return 0;
    while(!(x&(1<<now)))--now;
    int a=now; x^=(1<<now); --now;
    dp[x]=99999999;
    for(int val;now>=0;--now){
        if(x&(1<<now)){
            if((val=dfs(x^(1<<now),a-1))+d[odd[a]][odd[now]]<dp[x]){
                dp[x]=val+d[odd[a]][odd[now]];
                match[a]=now;
                match[now]=a;
            }
        }
    }
    return dp[x];
}
void addodd(){
    dfs((1<<odd.size())-1,odd.size()-1);
    int tmp=0;
    for(int i=0;i<odd.size();++i)tmp+=d[odd[i]][odd[match[i]]];
    totwei+=tmp/2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,s,t; cin>>n>>m>>s>>t;
    memset(d,0x3f,sizeof(d));
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        ++deg[u], ++deg[v];
        d[u][v]=d[v][u]=c;
        totwei+=c;
    }
    ++deg[s], ++deg[t];
    for(int i=0;i<1004;++i)d[i][i]=0,(deg[i]&1?odd.push_back(i):void());
    for(int k=1;k<=n;++k)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    addodd();
    int ans=0;
    cout<<totwei<<endl;
}
