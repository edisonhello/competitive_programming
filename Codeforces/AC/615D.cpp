#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1e9+7;

int pw(ll b,int n,int m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<int,pair<int,pair<int,int>>> mp;
    while(n--){ int t; cin>>t; ++mp[t].first; }
    for(auto &p:mp)p.second.second=make_pair(1,1);
    for(auto it=mp.begin();it!=mp.end();++it){
        it->second.second.first=it->second.first+1;
        if(it!=mp.begin())it->second.second.first=1ll*it->second.second.first*prev(it)->second.second.first%(mod-1);
    }
    for(auto it=mp.rbegin();it!=mp.rend();++it){
        it->second.second.second=it->second.first+1;
        if(it!=mp.rbegin())it->second.second.second=1ll*it->second.second.second*prev(it)->second.second.second%(mod-1);
    }
    int ans=1;
    for(auto it=mp.begin();it!=mp.end();++it){
        int other=1;
        /* for(auto it2=mp.begin();it2!=mp.end();++it2){
            if(it==it2)continue;
            other=other*1ll*(it2->second+1)%(mod-1);
        } */
        if(it!=mp.begin())other=1ll*other*prev(it)->second.second.first%(mod-1);
        if(next(it)!=mp.end())other=1ll*other*next(it)->second.second.second%(mod-1);
        int me=1ll*it->second.first*(it->second.first+1)/2%(mod-1);
        int all=1ll*other*me%(mod-1);
        ans=1ll*ans*pw(it->first,all,mod)%mod;
    }
    cout<<ans<<endl;
}
