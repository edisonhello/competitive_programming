#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll lcm(ll a,ll b,ll c){
    ll ab=a*b/__gcd(a,b);
    return ab*c/__gcd(ab,c);
}
ll lcm3(ll n){
    return max({
        lcm(n,n-1,n-2),
        lcm(n,n-1,n-3),
        lcm(n,n-2,n-3),
        lcm(n-1,n-2,n-3)
    });
}
int main(){
    int ts;cin>>ts;while(ts--){
        ll n;cin>>n;
        if(n==1)cout<<1<<endl;
        else if(n==2)cout<<2<<endl;
        else if(n==3)cout<<6<<endl;
        else cout<<lcm3(n)<<endl;
    }
}
