#include<bits/stdc++.h>
using namespace std;

int v[300005][2];
vector<int> g[300005];
vector<int> abi;
vector<long long> sa,sb;
long long ans[300005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>v[i][0]>>v[i][1];
    while(m--){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    abi.resize(n+5);
    for(int i=1;i<=n;++i)abi[i]=i;
    sort(abi.begin()+1,abi.begin()+1+n,[&](const int &a,const int &b){ return v[a][0]-v[a][1]<v[b][0]-v[b][1]; });
    // cout<<"abi: "; for(int i=1;i<=n;++i)cout<<abi[i]<<" "; cout<<endl;
    sa.resize(n+5,0); sb.resize(n+5,0);
    for(int i=1;i<=n;++i){
        sa[i]=sa[i-1]+v[abi[i]][0];
        sb[i]=sb[i-1]+v[abi[i]][1];
    }
    for(int i=1;i<=n;++i){
        int jie=lower_bound(abi.begin()+1,abi.begin()+1+n,i,[&](const int &a,const int &b){ return v[a][0]-v[a][1]<v[b][0]-v[b][1]; })-abi.begin();
        ans[i]+=sb[n]-sb[jie-1]+1ll*v[i][0]*(n-jie+1);
        ans[i]+=sa[jie-1]-sa[0]+1ll*v[i][1]*(jie-1);
        // cout<<"jie: "<<jie<<endl;
        // cout<<"ans["<<i<<"] before minus restrict: "<<ans[i]<<endl;
        ans[i]-=v[i][0]+v[i][1];
        for(int j:g[i]){
            ans[i]-=min(v[i][0]+v[j][1],v[j][0]+v[i][1]);
        }
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
}
