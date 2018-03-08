// POJ 1811
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<ctime>
using namespace std;
#define ll long long
#define abs(x) ((x)>0?(x):-(x))

vector<ll> tester;
vector<int> p;
bitset<30000> _p;

void init(){
    for(int i=2;i<30000;++i){
        if(_p[i])continue;
        p.push_back(i);
        for(int j=i*i;j<30000;j+=i)_p[j]=1;
    }
}

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    } return a;
}

ll meow(ll b,ll n,ll m,ll a=0){
    while(n){
        if(n&1)a=(a+b),a>=m?a-=m:0;
        b=(b+b),b>=m?b-=m:0; n>>=1;
    } return a;
}

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=meow(a,b,m);
        b=meow(b,b,m); n>>=1;
    } return a;
}

inline bool isprime(ll x){
    ll s=x-1,t=0;
    while(s%2==0)s/=2,++t;
    for(int i=0;i<tester.size();++i){
        ll test=tester[i]%x;
        if(test==0)continue;
        ll a=pw(test,s,x);
        if(a==1 || a==x-1)continue;
        for(int _=1;_<t;++_){
            a=meow(a,a,x);
            if(a==x-1)break;
        }
        if(a==x-1)continue;
        return 0;
    }
    return 1;
}

ll offset;
inline ll f(ll xx,ll x){return (meow(xx,xx,x)+offset)%x;}
inline ll ff(ll xx,ll x){return f(f(xx,x),x);}
ll rho(ll x,ll _offset=2){
    // cout<<"minprime "<<x<<endl;
    offset=_offset;
    if(x%2==0)return 2;
    if(isprime(x))return x;
    ll g;
    register ll a=2,b=2;
    // cout<<"start from "<<a<<" , offset: "<<offset<<endl;
    a=f(a,x),b=ff(b,x);
    for(;;a=f(a,x),b=ff(b,x)){
        // cout<<"a="<<a<<" , b="<<b<<endl;
        if((g=gcd(abs(a-b),x))!=1){
            // if(g==x)exit(7122);
            return g;
            // while(x%g==0)x/=g;
            // cout<<x<<" "<<g<<endl;
        }
    }
}

ll bf(ll x){
    for(int i=0;i<p.size() && p[i]*p[i]<=x;++i){
        if(x%p[i]==0)return p[i];
    }
    return x;
}

ll minprime(ll x,ll i=1){
    if(x<=900000000)return bf(x);
    if(isprime(x))return x;
    ll d=x;
    while(d==x)d=rho(x,++i);
    return min(minprime(d,i),minprime(x/d,i));
}

int main(){
    init();
    tester.push_back(2);
    tester.push_back(325);
    tester.push_back(9375);
    tester.push_back(28178);
    tester.push_back(450775);
    tester.push_back(9780504);
    tester.push_back(1795265022);
    // ll ptr=18014398509481920ll;
    int t; cin>>t; while(t--){
        ll x; cin>>x;
        // ll x=++ptr;
        // cout<<x<<" : ";
        if(isprime(x)){
            cout<<"Prime"<<endl;
        }
        else cout<<minprime(x)<<endl;
    }
}
