#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
using namespace std;
#define ll long long

ll n,m,p[13],v[13],P,fac[200005],Ps[13],invPs[13];
int k;

inline ll meow(ll b,ll n,ll m,ll a=0){
    while(n){
        if(n&1)a=(a+b),a>=m?a-=m:0;
        b=(b+b),b>=m?b-=m:0; n>>=1;
    } return a;
}
inline ll pow(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=meow(a,b,m);
        b=meow(b,b,m); n>>=1;
    } return a;
}

inline ll inv(ll x,ll m){
    return pow(x%m,m-2,m);
}

inline ll C(ll n,ll m,ll p){
    if(m>n)return 0;
    return fac[n]%p*inv(fac[m],p)%p*inv(fac[n-m],p)%p;
}
ll CC(ll n,ll m,ll p){
    if(n==0 && m==0)return 1;
    return C(n%p,m%p,p)*CC(n/p,m/p,p)%p;
}

inline ll CRT(){
    for(int i=0;i<k;++i)Ps[i]=P/p[i];
    for(int i=0;i<k;++i)invPs[i]=inv(Ps[i]%p[i],p[i]);
    ll ans=0;
    for(int i=0;i<k;++i)ans=(ans+meow(v[i],meow(invPs[i],Ps[i],P),P))%P;
    return ans%P;
}

int main(){
    int t; cin>>t; while(t--){
        cin>>n>>m>>k; P=1;
        for(int i=0;i<k;++i)cin>>p[i],P*=p[i];
        fac[0]=1; for(int i=1;i<=200000;++i)fac[i]=meow(fac[i-1],i,P);
        for(int i=0;i<k;++i)v[i]=CC(n,m,p[i]);
        // for(int i=0;i<k;++i)cout<<"v["<<i<<"]: "<<v[i]<<endl;
        cout<<CRT()<<endl;
    }
}
