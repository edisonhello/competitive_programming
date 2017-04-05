#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int ind[654];bool v[456];
vector<int> G[654];
stack<int> ans;

void dfs(int now){
    v[now]=1;
    for(int i:G[now]){
        if(!v[i])dfs(i);
    }
    ans.push(now);
}

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;while(cin>>n>>m,n){
        for(int i=1;i<=n;++i){
            ind[i]=0;
            G[i].clear();
            v[i]=0;
        }
        while(ans.size())ans.pop();
        while(m--){
            int u,v;cin>>u>>v;
            G[u].push_back(v);
            ++ind[v];
        }
        for(int i=1;i<=n;++i){
            if(!v[i] && !ind[i]){
                dfs(i);
            }
        }
        while(ans.size()){
            cout<<ans.top();ans.pop();
            if(ans.size())cout<<" ";
        }
        cout<<endl;
    }
}
