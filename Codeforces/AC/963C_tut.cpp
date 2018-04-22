#include<bits/stdc++.h>
using namespace std;

map<long long,vector<pair<long long,long long>>> mp;

int main(){
    int n; cin>>n;
    long long g=0;
    for(int i=0;i<n;++i){
        long long w,h,c; cin>>w>>h>>c;
        mp[w].emplace_back(h,c);
        g=__gcd(g,c);
    }
    sort(mp.begin()->second.begin(),mp.begin()->second.end());
    for(auto it=mp.begin(),it2=++mp.begin();it2!=mp.end();++it2){
        sort(it2->second.begin(),it2->second.end());
        if(it->second.size()!=it2->second.size())exit((cout<<0<<endl,0));
        for(int i=0;i<it->second.size();++i){
            if(it->second[i].first!=it2->second[i].first)exit((cout<<0<<endl,0));
            if(abs((long double)it->second[0].second/it2->second[0].second-(long double)it->second[i].second/it2->second[i].second)>1e-13)exit((cout<<0<<endl,0));
        }
    }
    /* auto mnit=mp.begin();
    long long mn=mnit->second[0].second;
    for(auto it=mp.begin();it!=mp.end();++it){
        if(it->second[0].second<mn){
            mn=it->second[0].second;
            mnit=it;
        }
    }
    long long g=mnit->second[0].second;
    for(int i=1;i<mnit->second.size();++i)g=__gcd(g,mnit->second[i].second); */
    long long ans=1;
    for(long long i=2;i*i<=g;++i){
        int cnt=0;
        while(g%i==0){
            g/=i; ++cnt;
        }
        ans*=cnt+1;
    }
    if(g>1)ans<<=1;
    cout<<ans<<endl;
}
