#include<iostream>
#define pll pair<ll,ll>
#define ll long long
#define X first
#define Y second
using namespace std;
ll a,n,g;
pll ___gcd(ll x,ll y){
    if(!y){
        g=x;
        return {1,0};
    }
    pll rt=___gcd(y,x%y);
    return {rt.Y,rt.X-x/y*rt.Y};
}
int main(){
    while(cin>>a>>n){
        if(n==1){cout<<"No Inverse\n"<<endl;continue;}
        g=0;
        pll rt=___gcd(a,n);
        while(rt.X<0)rt.X+=n;
        if(g!=1)cout<<"No Inverse\n";
        else cout<<rt.X<<endl;
    }
}
