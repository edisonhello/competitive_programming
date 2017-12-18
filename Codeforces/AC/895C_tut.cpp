#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67}; // 19
int cnt[77];
ll dpp[2][1<<20],_2[123456];

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    int n; cin>>n;
    while(n--){
        int t; cin>>t; ++cnt[t];
    }
    ll *dp=dpp[0],*prv=dpp[1];
    prv[0]=1; _2[0]=1; for(int i=1;i<123456;++i)_2[i]=_2[i-1]*2%mod;
    for(int i=1;i<=70;++i){
        if(!cnt[i])continue;
        int eff=0,ii=i;
        for(int j=0;j<19;++j){
            while(ii%p[j]==0)ii/=p[j],eff^=(1<<j);
        }
        // memset(dp,0,sizeof(dpp)/2);
        for(int x=0;x<(1<<19);++x){
            dp[x]=(prv[x]+prv[x^eff])%mod*_2[cnt[i]-1]%mod;
        }
        swap(dp,prv);
    }
    cout<<(prv[0]?prv[0]-1:1000000006)<<endl;
}
