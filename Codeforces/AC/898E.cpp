#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> dts;
int main(){
    int n,nn; cin>>n; nn=n;
    ll ans=0,iss=0,is0=0;
    while(n--){
        ll t; cin>>t;
        ll sqt=sqrt(t);
        if(t==0)++iss,++is0;
        else if(sqt*sqt==t)++iss;
        else dts.push_back(min(t-sqt*sqt,(sqt+1)*(sqt+1)-t));
    }
    if(iss<nn/2){
        sort(dts.begin(),dts.end()); reverse(dts.begin(),dts.end());
        while(iss<nn/2){
            ++iss;
            ans+=dts.back();
            dts.pop_back();
        }
    }
    else if(iss>nn/2){
        ll nt0=iss-is0;
        if(nt0>=iss-nn/2){
            ans=iss-nn/2;
        }
        else{
            ans=nt0*2;
            iss-=nt0;
            ans+=(iss-nn/2)*2;
        }
    }
    cout<<ans<<endl;
}
