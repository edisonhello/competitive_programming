#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll meow(ll a,ll b){
    return a/__gcd(a,b)*b;
}
ll meow(ll a,ll b,ll c){
    return meow(meow(a,b),c);
}
int main(){
    ll n; cin>>n;
    if(n==1)return cout<<"1"<<endl,0;
    if(n==2)return cout<<"2"<<endl,0;
    cout<<max(max(meow(n,n-1,n-2),meow(n,n-1,n-3)),max(meow(n,n-2,n-3),meow(n-1,n-2,n-3)))<<endl;
}
