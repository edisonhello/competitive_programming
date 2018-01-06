#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int ind[100005];
int dep[100005];

long long dfs(int now){
    if(G[now].empty())return dep[now];
    long long sum=0;
    for(int i:G[now]){
        sum+=dfs(i);
        dep[now]=max(dep[now],dep[i]+1);
    }
    return sum+dep[now];
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int t; cin>>t; while(t--){
            int tt; cin>>tt; ++ind[tt];
            G[i].push_back(tt);
        }
    }
    int root;
    for(int i=1;i<=n;++i)if(!ind[i])root=i;
    cout<<root<<endl<<dfs(root)<<endl;
}
