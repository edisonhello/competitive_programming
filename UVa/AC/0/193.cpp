#include<bits/stdc++.h>
using namespace std;

int n,clr[122];
vector<int> G[122],ans,now;

void dfs(int x){
    if(x>n){
        if(now.size()>ans.size())ans=now;
        else if(now.size()==ans.size() && now.back()==n)ans=now;
        return;
    }
    bool bl=1;
    for(int i:G[x])if(clr[i]){bl=0; break;}
    if(bl){
        clr[x]=1;
        now.push_back(x);
        dfs(x+1);
        now.pop_back();
        clr[x]=0;
    }
    dfs(x+1);
}

int main(){
    int t; cin>>t; while(t--){
        int k; cin>>n>>k;
        for(int i=1;i<=n;++i)G[i].clear(),clr[i]=0;
        ans.clear(); now.clear();
        while(k--){
            int u,v; cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1);
        cout<<ans.size()<<endl;
        for(int i:ans)cout<<i<<" \n"[i==ans.back()];
    }
}
