// SPOJ NKLEAVES Leaves
#include<bits/stdc++.h>
using namespace std;

int n;
long long w[100005],piw[100005],pw[100005],dp[13][100005];

long long get(int l,int r){
    return (piw[r]-piw[l-1])-(pw[r]-pw[l-1])*l;
}

void go(int layer,int l,int r,int tl,int tr){
    if(l>r)return;
    int x=(l+r)>>1;
    long long mn=LLONG_MAX;
    int tp=-1;
    for(int i=max(x,tl);i<=min(tr,n-layer+1);++i){
        // cout<<"get("<<x<<","<<i<<")="<<get(x,i)<<endl;
        if(get(x,i)+dp[layer-1][i+1]<mn){
            mn=get(x,i)+dp[layer-1][i+1];
            tp=i;
        }
    }
    // cout<<"dp "<<layer<<" , "<<x<<" = "<<mn<<endl;
    dp[layer][x]=mn;
    go(layer,l,x-1,tl,tp);
    go(layer,x+1,r,tp,tr);
}

int main(){
    int k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n;++i)pw[i]=pw[i-1]+w[i];
    for(int i=1;i<=n;++i)piw[i]=piw[i-1]+w[i]*i;
    for(int i=1;i<=n;++i)dp[1][i]=get(i,n);
    for(int i=2;i<=k;++i){
        go(i,1,n-i+1,1,n-i+1);
    }
    cout<<dp[k][1]<<endl;
}
