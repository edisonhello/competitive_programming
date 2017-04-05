#include<bits/stdc++.h>
using namespace std;
int dp[10005]={1};
int main(){
    for(int i=1;i<10002;++i){
        for(int j=i;j<10002;++j){
            dp[j]+=dp[j-i];
            dp[j]%=1000000007;
        }
    }
    int d,t;cin>>d>>t;while(t--){
        int n;cin>>n;cout<<dp[n]<<endl;
    }
}
// WA 100, dp from wiki
