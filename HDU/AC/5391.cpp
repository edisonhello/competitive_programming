#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
#define abs(x) ((x)>0?(x):-(x))

vector<ll> tester;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

bool isprime(ll x){
    ll s=x-1,t=0;
    while(s%2==0)s/=2,++t;
    for(int i=0;i<tester.size();++i){
        ll test=tester[i];
        if(test%x==0)continue;
        ll a=pw(test%x,s,x);
        if(a==1 || a==x-1)continue;
        for(int _=1;_<t;++_){
            a=a*a%x;
            if(a==x-1)break;
        }
        if(a==x-1)continue;
        return 0;
    }
    return 1;
}

int main(){
    tester.push_back(2);
    tester.push_back(325);
    tester.push_back(9375);
    tester.push_back(28178);
    tester.push_back(450775);
    tester.push_back(9780504);
    tester.push_back(1795265022);
    int t; cin>>t; while(t--){
        ll x; cin>>x;
        if(x==4){
            cout<<2<<endl;
        }
        else if(isprime(x)){
            cout<<x-1<<endl;
        }
        else cout<<0<<endl;
    }
}
