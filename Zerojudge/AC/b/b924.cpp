#include<bits/stdc++.h>
using namespace std;

int deg[11111];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        ++deg[u]; ++deg[v];
    }
    int cnt=0;
    for(int i=1;i<=n;++i){
        if(deg[i]&1){
            ++cnt;
        }
    }
    if(cnt<=2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
