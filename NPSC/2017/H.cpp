#include<bits/stdc++.h>
using namespace std;

int w,h,mp[1111][222],pre[1111][222];

struct {

} N;
struct {

} P;
struct {
    int dp[1111][222];
    void init(){
        for(int i=5;i<=h;i+=2){
            for(int j=2;j<=w;++j){
                dp[i][j]=max(dp[i-2][j],max(dp[i-2][j-1],dp[i][j-1]));
                for(int dj=2,di=5;dj<=j && di<=i;++dj,di+=2){
                    dp[i][j]=max(dp[i][j],
                                 rec(i-di+1,j-dj+1,i,j)-rec(i-di+2,j-dj+2,i-di/2-1,j)-rec(i-di/2+1,j-dj+1,i-1,j-1)
                                 );
                }
            }
        }
    }
} S;
struct {

} C;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>w>>h;
    for(int j=h;j>=1;--j){
        for(int i=1;i<=w;++i){
            cin>>mp[j][i];
        }
    }
    for(int i=1;i<=h;++i){
        for(int j=1;j<=w;++j){
            pre[i][j]=-pre[i-1][j-1]+mp[i][j]+pre[i][j-1]+pre[i-1][j];
        }
    }
    N.init();
    P.init();
    S.init();
    C.init();
    int mx=-2147483648;
    for(int i=4;i<=w;++i){
        for(int j=i+3;j<=w;++j){
            for(int k=j+2;k<=w;++k){
                mx=max(mx,N.solve(1,i-1)+P.solve(i+1,j-1)+S.solve(j+1,k-1)+C.solve(k+1,w));
            }
        }
    }
    cout<<mx<<endl;
}
