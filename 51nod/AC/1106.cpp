#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

bool test(ll fake,ll s,ll t,ll x){
    if(fake==0 || fake==1 || fake==x-1)return 1;
    fake=pw(fake,s,x);
    if(fake==0 || fake==1 || fake==x-1)return 1;
    for(int i=0;i<t-1;++i){
        fake=pw(fake,2,x);
        if(fake==1)return 0;
        if(fake==x-1)return 1;
    }
    return 0;
}

bool isp(ll x){
    if(x==2)return 1;
    if(x%2==0)return 0;
    ll s=x-1,t=0;
    while(s%2==0)s>>=1,++t;
    for(int i=0;i<12;++i){
        if(!test(rand()%x,s,t,x))return 0;
    }
    return 1;
}

int main(){
    int n; cin>>n;
    while(n--){
        ll t; cin>>t;
        if(isp(t))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}
