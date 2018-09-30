#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t[55];

int main(){
    ll n,k,m; cin>>n>>k>>m;
    for(int i=1;i<=k;++i)cin>>t[i];
    ll ans=0,tot=0;
    for(int i=1;i<=k;++i)tot+=t[i];
    for(int i=0;i<=n;++i){
        if(tot*i>m)break;
        vector<int> co;
        for(int j=1;j<=n-i;++j)for(int z=1;z<=k;++z)co.push_back(t[z]);
        sort(co.begin(),co.end());
        ll tmp=(k+1)*i;
        ll le=m-tot*i;
        for(int i:co){
            if(i>le)break;
            le-=i;
            ++tmp;
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
}
