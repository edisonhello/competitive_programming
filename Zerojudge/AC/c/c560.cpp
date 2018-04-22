#include<bits/stdc++.h>
using namespace std;

int cho[100005],dp[100005];

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int t; cin>>t;
        ++cho[t];
    }
    for(int i=1;i<=n;++i)cho[i]+=cho[i-1];
    dp[0]=1;
    for(int i=1;i<=n;++i){
        if(i>=3 && cho[i-1]==cho[i-3])dp[i]+=dp[i-3];
        dp[i]+=dp[i-1];
        dp[i]%=1000000007;
    }
    cout<<dp[n]<<endl;
}


