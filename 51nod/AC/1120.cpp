#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

ll inv(int x){
    return pw(x,10005,10007);
}

int cnt=0;
ll c(int u,int d){
    ll rt=1;
    for(int i=2;i<=u;++i){
        if(i%10007==0)++cnt;
        else rt=rt*i%10007;
    }
    for(int i=2;i<=d;++i){
        if(i%10007==0)--cnt;
        else rt=rt*inv(i)%10007;
    }
    for(int i=2;i<=u-d;++i){
        if(i%10007==0)--cnt;
        else rt=rt*inv(i)%10007;
    }
    return rt;
}

ll cc(int u,int d){
    return c(u/10007/10007,d/10007/10007)*c(u/10007,d/10007)*c(u%10007,d%10007)%10007;
}

int main(){
    int n; cin>>n; --n;
    // if(n>=100000)return cout<<0<<endl,0;
    // cout<<inv(n+1)<<" "<<c(2*n,n)<<endl;
    ll arg1=inv(n+1);
    ll arg2=cc(2*n,n);

    // cout<<arg1<<" "<<arg2<<" "<<cnt<<endl;

    while(arg1%10007==0)arg1/=10007,++cnt;
    while(arg2%10007==0)arg2/=10007,++cnt;

    cout<<2ll*arg1*arg2%10007<<endl;
}

