#include<bits/stdc++.h>
using namespace std;

int c[1000006];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>c[i];
    bool ok=1;
    while(m--){
        int u,v; cin>>u>>v;
        if(c[u]==c[v])ok=0;
    }
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
