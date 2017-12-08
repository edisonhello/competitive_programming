#include<bits/stdc++.h>
using namespace std;

vector<int> G[300008];
int val[300008],f[300008];
const int mod=1000000007;

void mdf(int now,int pa,int mdep,int dep){
    val[now]=(val[now]+(dep>1?f[dep]=(f[dep-1]+f[dep-2])%mod:f[dep]))%mod;
    if(dep==mdep)return;
    for(int i:G[now]){
        if(i==pa)continue;
        mdf(i,now,mdep,dep+1);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n,q; cin>>n>>q;
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while(q--){
            int c,v; cin>>c>>v;
            if(c==1){
                int k,a,b; cin>>k>>a>>b;
                f[0]=a; f[1]=b;
                mdf(v,v,k,0);
            }   
            else cout<<val[v]<<endl;
        }

        for(int i=1;i<=n;++i)G[i].clear(),val[i]=0;
    }
}
// TLE 415
