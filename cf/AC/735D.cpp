#include<iostream>
#define ll long long
using namespace std;

bool isprime(ll x){
    if(x==0 || x==1 || x==4)return 0;
    if(x==2 || x==3)return 1;
    for(ll i=2;i*i<=x;++i){
        if(!(x%i))return 0;
    }
    return 1;
}

int main(){
    ll n;cin>>n;
    if(isprime(n))cout<<1<<endl;
    else if(!(n&1))cout<<2<<endl;
    else if(isprime(n-2))cout<<2<<endl;
    else cout<<3<<endl;
}
