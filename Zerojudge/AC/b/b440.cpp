#include<bits/stdc++.h>
using namespace std;
#define ll long long

int u[10000007]={0,1},pre[10000007];

void mobius(){
    for(int i=1;i<=10000000;++i){
        pre[i]=pre[i-1]+u[i];
        for(int j=i*2;j<=10000000;j+=i){
            u[j]-=u[i];
        }
    }
}

ll solve(ll n,ll m){
    ll ans=0;
    for(int k=1;k<=min(n,m);){
        /* if(k==min(n,m)){
            ans+=u[k]*(n/k)*(m/k);
            break;
        } */
        int end=min(n/(n/k),m/(m/k));
        ans+=n/k*(m/k)*(pre[end]-pre[k-1]);
        k=end+1;
    }
    return ans;
}

int main(){
    mobius();
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        cout<<solve(n,m)<<'\n';
    }
}
