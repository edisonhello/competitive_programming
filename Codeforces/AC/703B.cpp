#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c[100005];
int cap[100005];
bitset<100005> nex;

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1;i<=k;++i)cin>>cap[i];
    ll ans=c[1]*c[n];
    for(int i=2;i<=n;++i)ans+=c[i-1]*c[i];
    ll add=0;
    for(int i=1;i<=n;++i)add+=c[i];
    for(int i=1;i<=k;++i){
        int p=cap[i];
        ll pr=add-c[p]-(nex[p==1?n:p-1]?0:c[p==1?n:p-1])-(nex[p==n?1:p+1]?0:c[p==n?1:p+1]);
        // cout<<"pr: "<<pr<<endl;
        ans+=c[p]*pr;
        add-=c[p];
        nex[p]=1;
    }
    cout<<ans<<endl;
}
