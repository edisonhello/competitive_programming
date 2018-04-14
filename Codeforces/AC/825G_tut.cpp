#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000006];

int ans,mn[1000006];

void dfs(int now,int pa,int nmn){
    mn[now]=nmn;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,min(nmn,i));
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    --q; 
    int root; cin>>root>>root;
    root=root%n+1;
    dfs(root,root,root);
    ans=root;
    int last=0;
    while(q--){
        int t,x; cin>>t>>x;
        x=(x+last)%n+1;
        // cout<<"decode: "<<t<<" "<<x<<endl;
        if(t==1){
            ans=min(ans,mn[x]);
        }
        else cout<<(last=min(ans,mn[x]))<<'\n';
    }
}
