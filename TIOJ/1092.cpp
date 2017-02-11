#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> G[10005];
int dp[10005];

int gV(int now){
    if(~dp[now])return dp[now];
    dp[now]=0;
    for(auto &i:G[now]){
        dp[now] |= !gV(i);
    }
    return dp[now];
}

int main(){
    int n,e;while(cin>>n>>e,n){
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<=e;++i){
            int a,b;cin>>a>>b;
            G[a].push_back(b);
        }
        string s;cin>>s;gV(1);
        /*for(int i=1;i<=n;++i){
            cout<<gV(i)<<" ";
        }cout<<endl;*/
        // cout<<gV(1)<<endl;
         if(gV(1)) cout<<(s[1]=='i'?"Moumou":s)<<endl;
         else cout<<s<<endl;
    }
}
