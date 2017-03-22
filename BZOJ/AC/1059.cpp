#include<bits/stdc++.h>

using namespace std;

vector<int> G[444];
int mch[444];
bool v[444];

bool dfs(int now){
    for(int i=0;i<G[now].size();++i){
        if(v[G[now][i]])continue;
        v[G[now][i]]=1;
        if(mch[G[now][i]]==-1 || dfs(mch[G[now][i]])){
            mch[G[now][i]]=now;
            mch[now]=G[now][i];
            return 1;
        }
    }
    return 0;
}

int main(){
    int ts;cin>>ts;while(ts--){
        int n;cin>>n;
        for(int i=0;i<=n*2+5;++i)G[i].clear();
        for(int i=0;i<n;++i)for(int j=0;j<n;++j){
            int t;cin>>t;if(t)G[i].push_back(j+n),G[j+n].push_back(i);
        }
        int m=0;
        memset(mch,-1,sizeof(mch));
        for(int i=0;i<n;++i){
            if(mch[i]==-1){
                memset(v,0,sizeof(v)); v[i]=1;
                if(dfs(i))++m;
            }
        }
        if(m==n)cout<<"Yes\n";
        else cout<<"No\n";
    }
}
