#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

#define ll long long

ll k,n,m,x,y,nm;

ll getMX(ll k,ll n,ll m){
    if(k<=n*m)return 1;
    k-=m;
    // cout<<k<<" "<<(n-1)*m<<endl;
    return (k-1)/((n-1)*m)+1;
}
ll getMN(ll k,ll n,ll m){
    if(k<n*m)return 0;
    k-=n*m-1;
    return (k-1)/((n-1)*m*2)+1;
}
ll getMX1(ll k,ll m){
    return (k-1)/m+1;
}
ll getMN1(ll k,ll m){
    return k/m;
}
ll getS1(ll k,ll m,ll y){
    return k/m+(k%m>=y?1:0);
}

int main(){
    cin>>n>>m>>k>>x>>y;
    if(k==0){cout<<"0 0 0\n";return 0;}
    nm=n*m;
    if(n==1){
        cout<<getMX1(k,m)<<" "<<getMN1(k,m)<<" "<<getS1(k,m,y);
        return 0;
    }

    cout<<getMX(k,n,m)<<" "<<getMN(k,n,m)<<" ";

    ll firstto=(x-1)*m+y;
    // cout<<"fsto="<<firstto<<endl;
    if(k<firstto){cout<<0<<endl;return 0;}
    k-=firstto;
    ll lp1=m-y+(n-x)*m+(n-1-x)*m+y;
    // cout<<"lp1="<<lp1<<endl;
    ll lp=(n-1)*m*2;
    ll ans=1;
    ans+=k/lp*2;
    if(x==1)ans-=k/lp;
    k%=lp;
    if(k>=lp1)++ans;
    if(x==n)ans>>=1;
    cout<<ans<<endl;
}
