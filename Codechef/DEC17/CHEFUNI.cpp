#include<bits/stdc++.h>
using namespace std;

int _dp[111][111][111];
inline int& dp(int a,int b,int c){return _dp[a][b][c];}
#define u(y) dp(i,j,k)=min(dp(i,j,k),y)

int main(){
    int t; cin>>t; while(t--){
        int x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
        sort(&x,&x+3);
        // cout<<x<<" "<<y<<" "<<z<<endl;
        for(int i=0;i<=x;++i){
            for(int j=0;j<=y;++j){
                for(int k=0;k<=z;++k){
                    dp(i,j,k)=102039203;
                    if(!(i||j||k))dp(i,j,k)=0;
                    if(i)u(dp(i-1,j,k)+a);
                    if(j)u(dp(i,j-1,k)+a);
                    if(k)u(dp(i,j,k-1)+a);
                    if(i&&j)u(dp(i-1,j-1,k)+b);
                    if(i&&k)u(dp(i-1,j,k-1)+b);
                    if(j&&k)u(dp(i,j-1,k-1)+b);
                    if(i&&j&&k)u(dp(i-1,j-1,k-1)+c);
                    // cout<<i<<" "<<j<<" "<<k<<" "<<dp(i,j,k)<<endl;
                }
            }
        }
        cout<<dp(x,y,z)<<endl;
    }
}
// TLE 400
