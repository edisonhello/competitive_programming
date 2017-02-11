#include<iostream>
using namespace std;
#include<vector>
vector<int> G[1981];
int v[1569];

bool dfs(int now,int cl){
    if(v[now] && v[now]!=cl)return 0;
    if(v[now])return 1;
    v[now]=cl;
    for(int i:G[now]){
        if(!dfs(i,-cl))return 0;
    }
    return 1;
}

int main(){
    int n;while(cin>>n,n){
        int m;cin>>m;
        for(int i=0;i<n;++i){
            G[i].clear();
            v[i]=0;
        }
        while(m--){
            int u,v;cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i=0;i<n;++i){
            if(!v[i]){
                if(!dfs(i,1)){
                    cout<<"NOT BICOLORABLE.\n";
                    goto nextT;
                }
            }
        }
        cout<<"BICOLORABLE.\n";
        nextT:;
    }
}
