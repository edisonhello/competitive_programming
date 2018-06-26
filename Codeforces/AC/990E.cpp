#include<bits/stdc++.h>
using namespace std;

bitset<2000006> isblock;
int pe[2000006],cost[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int t; cin>>t;
        isblock[t]=1;
    }
    for(int i=1;i<=n*2;++i){
        if(isblock[i])pe[i]=pe[i-1];
        else pe[i]=i;
    }
    for(int i=1;i<=k;++i)cin>>cost[i];
    long long ans=LLONG_MAX;
    for(int i=k;i>=1;--i){
        int cnt=0,now=0;
        while(now<n){
            if(isblock[now] || pe[now+i]==now){
                cnt=-1;
                break;
            }
            ++cnt;
            now=pe[now+i];
        }
        if(cnt==-1)break;
        ans=min(ans,1ll*cnt*cost[i]);
    }
    if(ans==LLONG_MAX)ans=-1;
    cout<<ans<<endl;
}
