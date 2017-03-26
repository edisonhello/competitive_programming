#include<iostream>
using namespace std;
#include<algorithm>
#include<cstdint>
#include<assert.h>
#define ll unsigned long long
#define ld long double

struct nm{
    ll u,d;
    nm():u(0),d(1){};
    nm(ll U,ll D):u(U),d(D){};
    nm operator=(const nm &a){
        this->u=a.u,this->d=a.d;
        return *this;
    }
};
bool operator<(const nm &a,const nm &b){
    // if()
    return (ld)a.u/(ld)a.d<(ld)b.u/(ld)b.d;
}
nm operator*(const nm &a,const nm &b){
    ll U=a.u*b.u,D=a.d*b.d;
    ll G=__gcd(U,D);
    // cout<<(nm){G/U,G/D}
    return (nm){U/G,D/G};
}
ostream& operator<<(ostream &ostm,const nm &a){
    ostm<<a.u<<"/"<<a.d;
}

nm a[505][505];
nm dp[505][505][105];
const ll MOD=1e9+9;

int main(){
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>a[i][j].u>>a[i][j].d;
            dp[i][j][0]=dp[i][j][1]=a[i][j];
            if(i>1)dp[i][j][1]=max(dp[i-1][j][1],dp[i][j][1]);
            if(j>1)dp[i][j][1]=max(dp[i][j-1][1],dp[i][j][1]);
        }
    }

    // for(int k=0;k<=3;++k){
    //     for(int i=1;i<=n;++i){
    //         for(int j=1;j<=n;++j){
    //             cout<<dp[i][j][k]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }

    int K;cin>>K;
    for(int k=2;k<=K;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dp[i][j][k]={0,1};
                // cout<<i<<" "<<j<<" "<<k<<" ";
                if(i>1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
                // cout<<dp[i][j][k]<<" ";
                if(j>1)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
                // cout<<dp[i][j][k]<<" ";
                if(i>1)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]*a[i][j]);
                // cout<<dp[i][j][k]<<" ";
                if(j>1)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]*a[i][j]);
                // cout<<dp[i][j][k]<<endl;
                if(dp[i][j][k].d==0)assert(1==0);
            }
        }
    }
    ll g=__gcd(dp[n][n][K].u,dp[n][n][K].d);
    ll u=dp[n][n][K].u/g,d=dp[n][n][K].d/g;
    u%=MOD,d%=MOD;
    cout<<u<<" "<<d<<endl;
}

/* WA 9 */
