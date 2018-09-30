#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ll long long

const int mod=1e9+7;

unsigned int hh[2222],pp[2222];

gp_hash_table<int,pair<int,int>> mp[2222];

int gethh(int l,int r){
    return 1ll*(hh[r]-(l?hh[l-1]:0)+mod)*pp[2221-r]%mod;
}
int gethh(string s){
    int rt=0;
    for(int i=0;i<int(s.size());++i)rt=(rt+1ll*s[i]*pp[i])%mod;
    return 1ll*rt*pp[2221-int(s.size())+1]%mod;
}

int main(){
    pp[0]=1;
    for(int i=1;i<2222;++i)pp[i]=1ll*pp[i-1]*7902131%mod;
    string s,t; cin>>s>>t;
    for(int i=0;i<int(s.size());++i)hh[i]=((i?hh[i-1]:0)+1ll*s[i]*pp[i])%mod;
    for(int i=0;i<int(s.size());++i){
        for(int j=1;i+j-1<int(s.size());++j){
            mp[j][gethh(i,i+j-1)]=make_pair(i,i+j-1);
        }
    }
    reverse(s.begin(),s.end());
    for(int i=0;i<int(s.size());++i)hh[i]=((i?hh[i-1]:0)+1ll*s[i]*pp[i])%mod;
    for(int i=0;i<int(s.size());++i){
        for(int j=1;i+j-1<int(s.size());++j){
            mp[j][gethh(i,i+j-1)]=make_pair(int(s.size())-1-i,int(s.size())-1-(i+j-1));
        }
    }
    // cout<<"gethh(4,4): "<<gethh(4,4)<<endl;
    // cout<<"gethh(\"y\"): "<<gethh("y")<<endl;
    vector<pair<int,int>> ans;
    for(int i=0;i<int(t.size());){
        // cout<<"nowi: "<<i<<endl;
        int l=1;
        int nowhh=0,tmphh=0;
        for(int j=i;j<int(t.size());++j,++l){
            // cout<<"now jl: "<<j<<" "<<l<<endl;
            tmphh=nowhh;
            nowhh=(nowhh+1ll*pp[l-1]*t[j])%mod;
            auto it=mp[l].find(1ll*nowhh*pp[2221-l+1]%mod);
            if(it==mp[l].end()){
                if(l==1)exit((cout<<-1<<endl,0));
                break;
            }
        }
        --l;
        // cout<<"fin get l: "<<l<<endl;
        auto it=mp[l].find(1ll*(i+l==int(t.size())?nowhh:tmphh)*pp[2221-l+1]%mod);
        ans.push_back(it->second);
        i+=l;
        // cout<<"newi: "<<i<<endl;
    }
    cout<<ans.size()<<'\n';
    for(auto &p:ans)cout<<p.first+1<<" "<<p.second+1<<'\n';
}
