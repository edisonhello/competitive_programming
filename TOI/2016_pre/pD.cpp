#include<iostream>
#include<algorithm>
using namespace std;

int a[10005],dp[2000005];

int main(){
    int n,tot=0,tott;cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        tot+=a[i];
    }
    tott=tot;
    tot>>=1;

    for(int i=0;i<n;++i){
        for(int j=tot;j>=a[i];--j){
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    cout<<dp[tot]<<" "<<tott-dp[tot]<<endl;
}
