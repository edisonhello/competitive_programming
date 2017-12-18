#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll get(ll x,ll mod){
    ll xx=x,b=1;
    while(b<=x)b*=10; xx*=b;
    while(x){
        b/=10;
        xx+=x%10*b;
        x/=10;
    }
    xx%=mod;
    return xx;
}
int main(){
    // for(int i=1;i<=100;++i)if(i%10)cout<<get(i,100000000)<<endl;
    int k; ll p; cin>>k>>p;
    ll ans=0;
    for(int i=1;;++i){
        // if(i%10==0)continue;
        --k;
        ans=(ans+get(i,p))%p;
        if(k==0)break;
    }
    cout<<ans<<endl;
}
