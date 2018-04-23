#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[300005],dp[3][5005];

int main(){
    srand(time(0));
    int n,k; cin>>n>>k;
    // int n=300000,k=5000;
    for(int i=1;i<=n;++i)cin>>a[i];
    // for(int i=1;i<=n;++i)a[i]=abs(int(rand()*rand())%1000000001);
    int len1=n/k,len2=n/k+1;
    int num1=k-n%k,num2=n%k;
    // cout<<len1<<" "<<len2<<" "<<num1<<" "<<num2<<endl;
    sort(a+1,a+1+n);
    for(int i=1;i<=k;++i){
        for(int j=0;j<=num1;++j){
            // /f(i>=4920)cout<<"i j "<<i<<" "<<j<<endl;
            dp[i&1][j]=1ll<<60;
            if(j>i || j>num1 || i-j>num2)continue;
            if(j){
                /* if(i>=4920){
                    cout<<"1 "<<j*len1+(i-j)*len2<<" "<<(j-1)*len1+(i-j)*len2+1<<endl;
                    cout<<j<<" "<<len1<<" "<<i-j<<" "<<len2<<" "<<j-1<<" "<<len1<<" "<<(i-j)<<" "<<len2<<endl;
                } */
                dp[i&1][j]=dp[(i-1)&1][j-1]+a[j*len1+(i-j)*len2]-a[(j-1)*len1+(i-j)*len2+1];
            }
            if(i-j<=num2 && i!=j){
                // if(i>=4920)cout<<"2 "<<j*len1+(i-j)*len2<<" "<<j*len1+(i-j-1)*len2+1<<endl;
                dp[i&1][j]=min(dp[i&1][j],dp[(i-1)&1][j]+a[j*len1+(i-j)*len2]-a[j*len1+(i-j-1)*len2+1]);
            }
            // if(i>=4920)cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i&1][j]<<endl;
        }
        // cout<<i<<endl;
    }
    cout<<dp[k&1][num1]<<endl;
}
