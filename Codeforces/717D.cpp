#include<bits/stdc++.h>
#define ld long double
using namespace std;
ld dp[1000005][130];
ld ch[105];
int main(){
    int n,x;
    cin>>n>>x;
    for(int i=0;i<=x;++i){
        cin>>ch[i];
        dp[1][i]=ch[i];
    }
    int mx2=1;
    for(;mx2<=x;mx2*=2){};
    for(int i=2;i<=n;++i){
        for(int j=0;j<=x;++j){
            for(int k=0;k<mx2;++k){
                dp[i][k]+=dp[i-1][k^j]*ch[j];
            }
        }
    }
    // cout<<"dp:\n";
    // for(int i=1;i<=n;++i){
    //     for(int j=0;j<4;++j){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    // printf("%.8llf\n",1.0-dp[n][0]);
    cout<<fixed<<setprecision(6)<<1-dp[n][0]<<endl;
}
