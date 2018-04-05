#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll calc(ll upp){
    ll rt=0;
    for(ll r=2;;++r){
        if(r*r*r>upp)break;
        rt+=upp/(r*r*r);
    }
    return rt;
}

int main(){
    ll m; cin>>m;
    ll L=8,R=1e18;
    while(R>L){
        ll mid=(L+R)>>1;
        if(calc(mid)<m)L=mid+1;
        else R=mid;
    }
    if(calc(L)==m)cout<<L<<endl;
    else cout<<-1<<endl;
}
