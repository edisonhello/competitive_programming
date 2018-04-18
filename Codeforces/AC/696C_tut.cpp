#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll pw(ll b,ll n,ll m=mod,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    int k; cin>>k;
    ll zi=1,mu=1;
    ll inv3=pw(3,mod-2);
    bool even=0;
    while(k--){
        ll n; cin>>n;
        if(n%2==0)even=1;
        zi=zi*(n%(mod-1))%(mod-1);
    }
    --zi; zi+=mod-1; zi%=mod-1;
    // cout<<"zi: "<<zi<<endl;
    mu=zi=pw(2,zi);
    if(even)++zi;
    else --zi;
    cout<<zi*inv3%mod<<"/"<<mu<<endl;
}
