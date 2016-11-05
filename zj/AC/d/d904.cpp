#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int c,n,a[15],dp[1005];
int main(){
    cin>>c>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    memset(dp,0x55,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<n;++i){
        for(int j=a[i];j<=c;++j){
            dp[j]=min(dp[j],dp[j-a[i]]+1);
        }
    }
    cout<<dp[c]<<endl;
}
