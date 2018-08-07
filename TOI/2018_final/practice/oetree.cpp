#include<bits/stdc++.h>
using namespace std;

vector<int> G[50005];
bitset<50005> even;
int ans;

int dfs(int now,int pa){
    int ch=0;
    for(int i:G[now]){
        if(i!=pa)ch^=dfs(i,now);
    }
    if(ch==even[now]){
        ++ans;
        return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        for(int i=0;i<n;++i)G[i].clear();
        even.reset();
        int z; cin>>z; for(int t;z--;){ cin>>t; even[t]=1; }
        for(int i=1,u,v;i<n;++i){ cin>>u>>v; G[u].push_back(v); G[v].push_back(u); }
        ans=0;
        int res=dfs(0,0);
        if(res)cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
