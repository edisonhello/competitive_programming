#include<bits/stdc++.h>
using namespace std;
#define ll long long

int djs[100005],sz[100005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
bool lk(int x){
    while(x){
        if(x%10!=4 && x%10!=7)return 0;
        x/=10;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<n;++i){
        int u,v,w; cin>>u>>v>>w;
        if(!lk(w))djs[F(u)]=F(v);
    }
    for(int i=1;i<=n;++i)++sz[F(i)];
    ll ans=1ll*n*(n-1)*(n-2);
    for(int i=1;i<=n;++i)if(sz[i]){
        ans-=1ll*sz[i]*(sz[i]-1)*(sz[i]-2);
        ans-=1ll*sz[i]*(sz[i]-1)*(n-sz[i])*2;
    }
    cout<<ans<<endl;
}
