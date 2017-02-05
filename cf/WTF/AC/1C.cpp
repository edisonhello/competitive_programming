#include<iostream>
using namespace std;
long long a[2005],Z=1000000007;
bool ab[2005];
#define ll long long
ll _fac[2005];

ll fac(int n){
    if(_fac[0])return _fac[n];
    _fac[0]=_fac[1]=1;
    for(int i=2;i<=2003;++i){
        _fac[i]=_fac[i-1]*i%Z;
    }
    return _fac[n];
}
ll _pow(ll b,int n){
    ll a=1;
    while(n){
        if(n&1)a=a*b%Z;
        b=b*b%Z;
        n>>=1;
    }
    return a;
}
ll inv(int n){
    // cout<<"inv "<<n<<" = "<<_pow(n,Z-2)<<endl;
    return _pow(n,Z-2);
}
ll C(int n,int m){
    // cout<<"C "<<n<<" "<<m<<" = "<<fac(n)<<" "<<inv(fac(m))<<" "<<inv(fac(n-m))<<endl;
    return fac(n)*inv(fac(m))%Z*inv(fac(n-m))%Z;
}
ll hf(int ps,int ep){
    ll a=0;
    for(int i=1;i<=ps;++i){
        if(i&1)a+=C(ps,i)*fac(ep-i)%Z;
        else a-=C(ps,i)*fac(ep-i)%Z;
        a%=Z;
        // cout<<"i:"<<i<<" "<<C(ps,i)<<" "<<fac(ep-i)<<endl;
    }
    a=a%Z;a+=Z;a%=Z;
    return a;
}

int main(){
    int n;cin>>n;
    for(int i=1;i<=n;++i)ab[i]=1;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]!=-1){
            ab[i]=0,ab[a[i]]=0;
        }
    }
    int m=0;
    for(int i=1;i<=n;++i)if(ab[i])++m;
    int ep=0;
    for(int i=1;i<=n;++i)if(!~a[i])++ep;
    // cout<<hf(m,ep)<<endl;
    ll ans=fac(ep)-hf(m,ep);
    ans%=Z;ans+=Z;ans%=Z;
    cout<<ans<<endl;
}
