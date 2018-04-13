#include<bits/stdc++.h>
using namespace std;

int deg[300005],cnt[300005],pre[300005];
vector<int> G[300005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p; cin>>n>>p;
    for(int i=1,u,v;i<=n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    for(int i=1;i<=n;++i){
        ++cnt[deg[i]];
    }
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+cnt[i];
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        int targ=p-deg[i];
        if(targ<=0){
            // cout<<i<<" is best!"<<endl;
            ans+=(n-1);
            continue;
        }
        int ok=pre[n]-pre[targ-1];
        if(deg[i]>=targ)--ok;
        // cout<<i<<" init ok is "<<ok<<endl;
        for(int j:G[i]){
            --deg[j];
            if(deg[j]==targ-1)--ok;
        }
        ans+=ok;
        for(int j:G[i])++deg[j];
    }
    cout<<ans/2<<endl;
}
