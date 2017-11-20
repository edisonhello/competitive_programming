#include<iostream>
using namespace std;
#define ll long long
const ll mod=1000000007;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    ll n,m,k; cin>>n>>m>>k;
    if(k==1)cout<<pw(2,(n-1)%(mod-1)*((m-1)%(mod-1))%(mod-1),mod)<<endl;
    else{
        if((n^m)&1)cout<<0<<endl;
        else cout<<pw(2,(n-1)%(mod-1)*((m-1)%(mod-1))%(mod-1),mod)<<endl;
    }
}
// solve with micc
