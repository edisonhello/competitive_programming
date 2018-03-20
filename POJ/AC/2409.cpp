#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long

ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(b,a);
    }
    return a;
}

ll pw(ll b,ll n,ll a=1){
    while(n){
        if(n&1)a*=b;
        b*=b; n>>=1;
    } return a;
}

ll get(int c,int n){
    ll ans=0;
    for(int i=0;i<n;++i){
        ans+=pw(c,gcd(i,n));
        if(!(n&1) && i&1)ans+=pw(c,(n>>1)+1);
        else ans+=pw(c,(n+1)>>1);
    }
    return (ans>>1)/n;
}


int main(){
    int c,n; while(cin>>c>>n,n){
        cout<<get(c,n)<<'\n';
    }
}
