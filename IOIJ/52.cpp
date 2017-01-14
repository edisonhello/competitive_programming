#include<iostream>
using namespace std;
#define ll long long

ll mp(ll b,ll n,ll m){
    if(!b)return 0;
    ll a=1;
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m;
        n>>=1;
    }
    return a;
}

int main(){
    int ts;cin>>ts;while(ts--){
        ll a0,a1,a2,a3,m;
        cin>>a0>>a1>>a2>>a3>>m;
        // a0%=m,a1%=m,a2%=m,a3%=m;
        a2=mp(a2%m,a3,m);
        a1=mp(a1,a2,m);
        a0=mp(a0,a1,m);
        cout<<a0<<endl;
    }
}
