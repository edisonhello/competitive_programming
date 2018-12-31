#include<bits/stdc++.h>
using namespace std;


vector<int> tar,G[100005];
bitset<100005> istar,v;
int d1[100005],d2[100005];

void dfs(int now,int pa,int *d){
    v[now]=1;
    for(int i:G[now]){
        if(v[i])continue;
        d[i]=d[now]+1;
        dfs(i,now,d);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,d; cin>>n>>m>>d;
    tar.resize(m);
    for(int &i:tar)cin>>i,istar[i]=1;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(tar[0],tar[0],d1);
    int z1=tar[0];
    for(int i:tar)if(d1[i]>d1[z1])z1=i;
    v.reset();
    dfs(z1,z1,d2);
    int z2=z1;
    for(int i:tar)if(d2[i]>d2[z2])z2=i;
    memset(d1,0,sizeof(d1));
    v.reset();
    dfs(z2,z2,d1);
    int c=0;
    for(int i=1;i<=n;++i)if(d1[i]<=d && d2[i]<=d)++c;
    cout<<c<<endl;
}
