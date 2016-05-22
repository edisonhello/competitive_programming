#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,d;cin>>n>>d;
    vector<pair<ll,ll> >fr;
    for(ll i=0;i<n;i++){
        ll m,s;cin>>m>>s;
        fr.push_back(make_pair(m,s));
    }
    sort(fr.begin(),fr.end());
    ll mx=-65656;
    ll i,j,buf=0;
    for(i=0,j=0;i<n;i++){
        if(i)buf-=fr[i-1].second;
        for(;fr[j].first-fr[i].first<d && j<n;j++){
            buf+=fr[j].second;  //cout<<buf<<endl;
        }
        mx=max(mx,buf);
    }

    cout<<mx<<endl;

}
