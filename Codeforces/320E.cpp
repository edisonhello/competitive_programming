#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll h[100005],c[100005],dp[100005];

ll dfs(int now){
    if(now==1)return 0;
    if(dp[now])return dp[now];
    int ref=-1;
    ll val=1000000000000000000ll;
    for(int i=now-1;i>=1;--i){
        ll nv=dfs(i)+h[now]*c[i];
        if(nv<val){
            val=nv;
            ref=i;
        }
    }
    cout<<"now: "<<now<<" , ref: "<<ref<<endl;
    return dp[now]=val;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)cin>>h[i];
    for(int i=1;i<=n;++i)cin>>c[i];
    cout<<dfs(n)<<endl;
}
