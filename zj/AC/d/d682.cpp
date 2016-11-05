#include<iostream>
#include<algorithm>
using namespace std;
int m,n,p,c[55][55],v[55][55],dp[55][10005];
int main(){
    cin>>m>>n>>p;
    for(int i=0;i<n;++i){
        for(int j=0;j<p;++j){
            cin>>c[i][j]>>v[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<p;++j){
            for(int k=0;k<=m;++k){
                if(k<c[i][j])dp[i+1][k]=max({dp[i+1][k],dp[i][k]});
                else{
                    dp[i+1][k]=max({
                        dp[i][k],
                        dp[i+1][k],
                        dp[i][k-c[i][j]]+v[i][j]});
                }
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
