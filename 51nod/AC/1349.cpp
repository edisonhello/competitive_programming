#include<bits/stdc++.h>
using namespace std;

vector<int> pos[100005];
long long ans[100005];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        pos[t].push_back(i);
    }
    vector<pair<int,int>> qs;
    int q; cin>>q;
    for(int i=0;i<q;++i){
        int t; cin>>t;
        qs.emplace_back(t,i);
    }
    sort(qs.begin(),qs.end());
    reverse(qs.begin(),qs.end());
    int ptr=100000;
    long long nans=1ll*n*(n+1)/2,tot=nans;
    set<int> ext;
    ext.insert(0); ext.insert(n+1);
    for(auto &i:qs){
        while(ptr>=i.first){
            for(int pp:pos[ptr]){
                auto it=ext.lower_bound(pp);
                auto iit=it; --iit;
                int dis=*it-*iit-1;
                nans-=1ll*dis*(dis+1)/2;
                dis=pp-*iit-1;
                nans+=1ll*dis*(dis+1)/2;
                dis=*it-pp-1;
                nans+=1ll*dis*(dis+1)/2;
                ext.insert(pp);
            }
            --ptr;
        }
        ans[i.second]=tot-nans;
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
