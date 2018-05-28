#include<bits/stdc++.h>
using namespace std;

unsigned int val1[1000006],val2[1000006];

unsigned int rnd(){
    return (rand()<<16)^rand();
}

const int mod=1000000007;

int fac[1000006];

int main(){
    srand(clock());
    fac[0]=1;
    for(int i=1;i<1000006;++i)fac[i]=1ll*fac[i-1]*i%mod;
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(n--){
        int g; cin>>g;
        map<int,int> cnt;
        for(int i=0,t;i<g;++i)cin>>t,++cnt[t];
        map<int,unsigned int> mp1,mp2;
        for(auto &p:cnt)mp1[p.second]=rnd();
        for(auto &p:cnt)mp2[p.second]=rnd();
        for(auto &p:cnt){
            val1[p.first]^=mp1[p.second];
            val2[p.first]^=mp2[p.second];
        }
    }
    map<pair<unsigned int,unsigned int>,int> rec;
    for(int i=1;i<=m;++i)++rec[make_pair(val1[i],val2[i])];
    int ans=1;
    for(auto &p:rec){
        ans=1ll*ans*fac[p.second]%mod;
    }
    cout<<ans<<endl;
}
