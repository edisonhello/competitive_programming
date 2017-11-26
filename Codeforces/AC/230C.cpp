#include<bits/stdc++.h>
using namespace std;

string mp[122];
int dp[10004];
int far[10004];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i)for(char &j:mp[i])j-='0';
    for(int i=0,ok=0;i<n;++i){
        for(char j:mp[i])ok|=j;
        if(!ok)return cout<<-1<<endl,0;
        ok=0;
    }
    for(int i=0;i<n;++i){
        memset(far,0x3f,sizeof(far));
        for(int j=0;j<m;++j){
            if(mp[i][j]==1)far[j]=0;
        }
        for(int j=1;j<m;++j)far[j]=min(far[j],far[j-1]+1);
        far[0]=min(far[0],far[m-1]+1);
        for(int j=1;j<m;++j)far[j]=min(far[j],far[j-1]+1);
        for(int j=m-2;j>=0;--j)far[j]=min(far[j],far[j+1]+1);
        far[m-1]=min(far[m-1],far[0]+1);
        for(int j=m-2;j>=0;--j)far[j]=min(far[j],far[j+1]+1);
        for(int j=0;j<m;++j)dp[j]+=far[j];
    }
    int mn=0x3f3f3f3f;
    for(int i=0;i<m;++i)mn=min(mn,dp[i]);
    cout<<mn<<endl;
}
