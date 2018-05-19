#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n; while(n--){
        ll p,q,b,g; cin>>p>>q>>b;
        g=__gcd(p,q);
        p/=g, q/=g;
        if(q==1){ cout<<"Finite"<<endl; continue; }
        while((g=__gcd(q,b))!=1){
            q/=g;
            b=__gcd(b,q);
        }
        if(q!=1){ cout<<"Infinite"<<endl; continue; }
        else{ cout<<"Finite"<<endl; continue; }
    }
}
