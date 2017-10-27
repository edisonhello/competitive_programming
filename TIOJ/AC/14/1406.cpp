#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> v;

bool can(ll y){
    // cout<<"go check at "<<y<<endl;
    ll tonext=0;
    pair<ll,ll> bk;
    for(int i=0;i<v.size();++i){
        bk=v[i];
        bk.second+=tonext;
        tonext=bk.second-y;
        if(i!=v.size()-1){
            if(tonext<0)tonext-=v[i+1].first-bk.first;
            else tonext=max(0ll,tonext-v[i+1].first+bk.first);
        }
        // cout<<"i="<<i<<", tonext="<<tonext<<endl;
    }
    if(tonext<0)return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n){
        v.clear();
        for(int i=0;i<n;++i){
            ll p,f; cin>>p>>f;
            v.emplace_back(p,f);
        }
        sort(v.begin(),v.end());
        ll L=0,R=1000000000000ll,M;
        while(R>L){
            M=(L+R+1)>>1;
            if(can(M))L=M;
            else R=M-1;
        } cout<<L<<endl;
    }
}
