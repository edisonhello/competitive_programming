#include<bits/stdc++.h>
using namespace std;

int dp[4444];
int main(){
    int n,a[3]; cin>>n>>a[0]>>a[1]>>a[2];
    dp[0]=1;
    for(int i=0;i<3;++i){
        for(int j=a[i];j<=n;++j){
            if(dp[j-a[i]])dp[j]=max(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[n]-1<<endl;
}
