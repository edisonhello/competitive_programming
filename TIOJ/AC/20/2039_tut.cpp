#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[2000006];
ll dp[2000006];
int n,cf[2000006];

int get(ll cost){
    // cout<<"use cost "<<cost<<endl;
    ll premax=-a[1]; int cfp=1;
    for(int i=2;i<=n;++i){
        dp[i]=dp[i-1], cf[i]=cf[i-1];
        if(dp[i]<a[i]+premax-cost){
            dp[i]=a[i]+premax-cost;
            cf[i]=cfp;
        }
        if(dp[i]-a[i]>premax){
            premax=dp[i]-a[i];
            cfp=i;
        }
    }
    int cnt=0,u=n;
    while(u){
        ++cnt;
        u=cf[u];
    }
    // cout<<"used: "<<cnt<<endl;
    return cnt;
}

// dp[i] = dp[j] + a[i] - a[j+1] - cost

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll L=0,R=1000000000000000000,a;
    while(R>L){
        ll m=((L+R)>>1);
        if(get(m)>k)L=m+1;
        else R=m,a=m;
    }
    get(a);
    cout<<dp[n]+a*k<<endl;
}

