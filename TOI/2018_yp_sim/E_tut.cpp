#pragma GCC optimize("no-stack-protector,O2")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long

vector<int> a[100005];

ll pre[100005];
inline ll query(const vector<int> &a,const vector<int> &b){
    ll rt=0;
    for(int i=0;i<a.size();++i)pre[i+1]=pre[i]+a[i];
    // int big=0;
    for(int i=0;i<b.size();++i){
        int big=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        // while(big<a.size() && a[big]<b[i])++big;
        rt+=(pre[a.size()]-pre[big])-1ll*b[i]*(a.size()-big)+1ll*b[i]*big-pre[big];
    }
    return rt;
}

map<int,ll> ans[100005];
int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n; scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int s; scanf("%d",&s); a[i].resize(s);
        for(int j=0;j<s;++j)scanf("%d",&a[i][j]);
        sort(a[i].begin(),a[i].end());
    }
    int q; scanf("%d",&q); while(q--){
        int i,j; scanf("%d%d",&i,&j);
        if(a[j].size()>a[i].size())swap(i,j);
        if(a[i].size()==a[j].size() && i<j)swap(i,j);
        auto it=ans[i].find(j);
        printf("%lld\n",it==ans[i].end()?ans[i][j]=query(a[i],a[j]):it->second);
    }
}
// AC
