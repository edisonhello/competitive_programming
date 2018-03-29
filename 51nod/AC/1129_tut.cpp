#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<ll,int> 

const ll mod=10007;

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){return pw(x,mod-2,mod);}

pli operator+(const pli &a,const pli &b){
    return {a.first*b.first%mod,a.second+b.second};
}
pli operator-(const pli &a,const pli &b){
    return {a.first*inv(b.first)%mod,a.second-b.second};
}
pli operator*(const pli &a,const int x){
    return {a.first*x%mod,a.second};
}
ostream& operator<<(ostream &ostm,const pli &x){
    ostm<<"["<<x.first<<","<<x.second<<"]";
    return ostm;
}

pli pw(pli b,ll n){
    return pli(pw(b.first,n,mod),b.second*n);
}

pli cnt_mod(ll x){
    int rt=0;
    while(x){
        rt+=x/mod;
        x/=mod;
    }
    return pli(1,rt);
}

pli _frac[11111];
pli frac(ll x){
    if(x<10007)return _frac[x];
    // cout<<"count frac "<<pw(_frac[10006],x/10007)<<" "<<_frac[x%10007]<<endl;
    // return cnt_mod(x)+pw(_frac[10006],x/10007)+_frac[x%10007];
    return cnt_mod(x)+pw(_frac[10006],x/10007)+frac(x%10007)+frac(x/10007);
}

pli pre_pw(ll b,ll n,ll m){
    if(b%m==0)return {1,cnt_mod(b).second*n};
    else return {pw(b,n,m),0};
}

pli calc(ll x,ll y){
    if(y<x)swap(x,y);
    // cout<<"calc: "<<x<<" * "<<y<<endl;
    pli rt={1,0};
    for(int i=1;i<x;++i){
        pli ppw1=pre_pw(i,i,mod);
        pli ppw2=pre_pw(y+x-i,i,mod);
        // cout<<"ppws: "<<ppw1<<" , "<<ppw2<<endl;
        rt=rt+ppw1+ppw2;
    }
    // cout<<"rt: "<<rt<<endl;
    // cout<<"frac(y): "<<frac(y)<<endl;
    // cout<<"frac(x-1): "<<frac(x-1)<<endl;
    // cout<<"frac dif: "<<frac(y)-frac(x-1)<<endl;
    // cout<<"after pow: "<<pw(frac(y)-frac(x-1),x)<<endl;
    rt=rt+pw(frac(y)-frac(x-1),x);
    // cout<<"rt: "<<rt<<endl;
    return rt;
}

int main(){
    // cout<<inv(2632)<<endl;
    int n; cin>>n;
    _frac[0]={1,0};
    for(int i=1;i<10007;++i)_frac[i]=_frac[i-1]+pli(i,0);
    
    ll ans=0;
    for(int i=1;i*i<=n;++i){
        if(n%i)continue;
        
        pli fracn=frac(n);
        pli clc=calc(i,n/i);
        pli add=fracn-clc;
        // cout<<"fracn and clc: "<<fracn<<" "<<clc<<endl;
        // if(n%i==0)cout<<"b4 add multi 2: "<<add<<endl;
        if(n/i!=i)add=add*2;
        // if(n%i==0)cout<<"add: "<<add<<endl;
        if(add.second==0)ans+=add.first;
    }
    // ans=frac(n)-ans;
    cout<<ans%mod<<endl;
}
