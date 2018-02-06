#include<bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> tmpp,ans,tmp;

int main(){
    set<ll> *now=&tmp,*prv=&tmpp;
    int n; cin>>n; while(n--){
        ll t; cin>>t;
        now->insert(t);
        ans.insert(t);
        for(auto i:*prv){
            ll g=__gcd(i,t);
            now->insert(g);
            ans.insert(g);
        }
        swap(now,prv);
        now->clear();
    }
    cout<<ans.size()<<endl;
}
