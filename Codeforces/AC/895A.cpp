#include<bits/stdc++.h>
using namespace std;
int a[366],dp[366][366];
int main(){
    int n,ans=12934; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
        int sum=0;
            for(int k=i;k<=j;++k)
            sum+=a[k];
        ans=min(ans,abs(360-2*sum));
        }
    }
    cout<<ans<<endl;
}
