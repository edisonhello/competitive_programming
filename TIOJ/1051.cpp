#include<iostream>
#include<algorithm>
using namespace std;

int a[666],b[666],dp[666],iprv[666];

int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        for(int i=n;i;--i)cin>>a[i];
        for(int i=n;i;--i)cin>>b[i];
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(a[i]==b[j]){
                    // dp[j]=dp[iprv[j]]+1;
                    iprv[j]=i;
                }
                if()
            }
        }
        for(int i=1;i<=n;++i){
            cout<<dp[i]<<" ";
        }cout<<endl;
    }
}
