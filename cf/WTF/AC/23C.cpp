#include<iostream>
using namespace std;
#define ll long long
const ll Z=1e9+7;
ll _fac[200008];
ll fac(int n){
    if(_fac[0])return _fac[n];
    _fac[0]=_fac[1]=1;
    for(int i=2;i<=200005;++i){
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
    return _pow(n,1e9+5);
}
ll C(int n,int m){
    return fac(n)*inv(fac(m))%Z*inv(fac(n-m))%Z;
}
ll cal(int s,int e,int l){
    int d=e-s;
    return C(l+d,d);
}
int main(){
    string s;cin>>s;
    s="0"+s+"9";
    ll ans=1;
    for(auto i=1u;i<s.length();++i){
        if(s[i]=='?'){
            for(auto j=i;j<s.length();++j){
                if(s[j]!='?'){
                    if(s[j]<s[i-1]){
                        cout<<0<<endl;
                        return 0;
                    }
                    ans=ans*cal(s[i-1]-'0',s[j]-'0',j-i)%Z;
                    i=j;
                    break;
                }
            }
        }
        else{
            if(s[i]<s[i-1]){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}
