#include<bits/stdc++.h>
using namespace std;

const long long mod=1000000007;

long long pw(long long b,long long n,long long m=mod,long long a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

long long inv(long long x){
    return pw(x,mod-2,mod);
}

long long a[5555],xi[5555];

int main(){
    int n; long long k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    long long cu=k-1,cn=0,c=1;
    for(int i=1;i<=n;++i){
        xi[i]=c;
        ++cu, ++cn;
        c=c*cu%mod*inv(cn)%mod;
    }
    for(int i=1;i<=n;++i){
        long long ans=0;
        for(int j=1;j<=i;++j){
            ans+=a[j]*xi[i+1-j]%mod;
        }
        cout<<ans%mod<<'\n';
    }
}
