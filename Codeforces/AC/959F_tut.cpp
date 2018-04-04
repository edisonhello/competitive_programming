#include<bits/stdc++.h>
using namespace std;

int a[100005],p2[100005],ans[100005];
vector<pair<int,int>> qs[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    p2[0]=1;
    for(int i=1;i<100005;++i)p2[i]=p2[i-1]*2,p2[i]>=1000000007?p2[i]-=1000000007:0;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=0;i<q;++i){
        int l,x; cin>>l>>x;
        qs[l].emplace_back(x,i);
    }
    vector<int> base;
    for(int i=1;i<=n;++i){
        for(int ii:base)a[i]=min(a[i],a[i]^ii);
        if(a[i])base.push_back(a[i]);
        for(auto q:qs[i]){
            for(int ii:base)q.first=min(q.first,q.first^ii);
            ans[q.second]=q.first?0:p2[i-base.size()];
        }
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
