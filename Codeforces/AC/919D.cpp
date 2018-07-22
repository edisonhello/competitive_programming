#include<bits/stdc++.h>
using namespace std;

string s;
int mx[300005][28],ans;
bitset<300005> v,in,out;
vector<int> G[300005];

void dfs1(int now){
    in[now]=1;
    for(int i:G[now]){
        if(out[i])continue;
        if(in[i])exit((cout<<-1<<endl,0));
        dfs1(i);
    }
    out[now]=1;
}

void dfs2(int now){
    if(v[now])return;
    v[now]=1;
    for(int i:G[now]){
        dfs2(i);
        for(int z=1;z<=26;++z)mx[now][z]=max(mx[now][z],mx[i][z]);
    }
    ++mx[now][s[now]];
    ans=max(ans,mx[now][s[now]]);
}

int main(){
    int n,m; cin>>n>>m>>s;
    s="."+s;
    for(char &c:s)c-='a'-1;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=1;i<=n;++i){
        if(!in[i])dfs1(i);
    }
    for(int i=1;i<=n;++i){
        if(!v[i])dfs2(i);
    }
    cout<<ans<<endl;
}
