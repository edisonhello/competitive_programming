#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<assert.h>
using namespace std;
#define ll long long

bool ab[100005];
int a[100005];
ll dp[100005],_wp[100005],Z;

ll wp(int n){
    if(_wp[2])return _wp[n];
    _wp[2]=1;
    for(int i=3;i<100004;++i)_wp[i]=(_wp[i-1]+_wp[i-2])%Z*(i-1)%Z;
    return _wp[n];
}

inline ll Dp(int em,int bl){
    dp[0]=1;
    for(int i=1;i<=em;++i){
        for(int j=min({i,bl,em});j>=0;--j){
            if(i==j)dp[j]=wp(j);
            else dp[j]=(j*dp[j-1]%Z+(i-j)*dp[j]%Z)%Z;
        }
    }
    return dp[bl];
}

int main(){
    ios_base::sync_with_stdio(0);
    freopen("31.in","r",stdin);
    freopen("31.out","w",stdout);
    int n,m=0,ep=0;cin>>n>>Z;
    if(Z==1){cout<<0<<endl;return 0;}
    for(int i=1;i<=n;++i)ab[i]=1;
    for(int i=1;i<=n;++i){
        cin>>a[i]; if(a[i]==i)assert(1==0);
        if(a[i]!=-1)ab[i]=0,ab[a[i]]=0;
    }
    for(int i=1;i<=n;++i)if(ab[i])++m;
    for(int i=1;i<=n;++i)if(!~a[i])++ep;
    cout<<Dp(ep,m)<<endl;
}
