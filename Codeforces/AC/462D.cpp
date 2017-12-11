#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool b[100005];
vector<int> G[100005];
const ll mod=1000000007,inv2=500000004;

#define norm(x) ((x%mod+mod)%mod)

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
ll inv(ll x){return pw(x,mod-2,mod);}

ll a[100005][2];
ll dfs(int now,int pa){
    a[now][0]=1;
    ll protta=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
        a[now][0]=a[now][0]*(a[i][0]+a[i][1])%mod;
        protta=(a[i][0]+a[i][1])*protta%mod;
    }
    for(int i:G[now]){
        if(i==pa)continue;
        a[now][1]=(a[now][1]+(protta*inv(a[i][0]+a[i][1])%mod*a[i][1]%mod))%mod;
    }
    if(b[now]){
        a[now][1]=a[now][0];
        a[now][0]=0;
    }
}

int main(){
    int n,rt; cin>>n;
    for(int i=1,p;i<n;++i){
        cin>>p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    for(int i=0;i<n;++i)cin>>b[i];
    G[n].push_back(0);
    cout<<(dfs(n,n),a[n][1])<<endl;
}
