#include<bits/stdc++.h>
using namespace std;

int _dp[111][111][111];
inline int& dp(int a,int b,int c){return _dp[a][b][c];}
#define u(y) dp(i,j,k)=min(dp(i,j,k),y)

long long solve3dp(int x,int y,int z,int a,int b,int c){
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
    return dp(x,y,z);
}

long long solve2(int x,int y,int a,int b){
    if(x<0 || y<0)return 2100000000;
    if(x==0)return y*a;
    if(y==0)return x*a;
    if(a*2<=b)return (x+y)*a;
    if(x>y)swap(x,y);
    return x*b+(y-x)*a;
}

long long solve3(int x,int y,int z,int a,int b,int c){
    if(x==0)return solve2(y,z,a,b);
    else return min(a+solve2(y,z,a,b),b+min(solve2(y-1,z,a,b),solve2(y,z-1,a,b)));
}

int main(){
    int t; cin>>t; while(t--){
        int x,y,z,a,b,c; cin>>x>>y>>z>>a>>b>>c;
        sort(&x,&x+3);
        int mxyz=x/2*2;
        long long ans;
        if(2*c<=3*b && 2*c<=6*a){
            ans=mxyz*c+solve3(x-mxyz,y-mxyz,z-mxyz,a,b,c);
        }
        else if(3*b<=2*c && 3*b<=6*a){
            ans=mxyz/2*3+solve3(x-mxyz,y-mxyz,z-mxyz,a,b,c);
        }
        else if(6*a<=2*c && 6*a<=3*b){
            ans=mxyz*3+solve3(x-mxyz,y-mxyz,z-mxyz,a,b,c);
        }
        ans=min(ans,x*b+solve3(0,y-x,z,a,b,c));
        ans=min(ans,x*b+solve3(0,y,z-x,a,b,c));
        ans=min(ans,y*b+solve3(0,x,z-y,a,b,c));
        cout<<ans<<endl;
    }
}
// TLE 400
// WA 400
// WA 400
