#include<iostream>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

vector<int> G[5005];
int n,m;
bool v[5005];
set<int> nice,bad;

int longestLength=-1,longestPoint;
int dfs1(int now,int dep){
    v[now]=1;
    if(dep>longestLength){
        longestLength=dep;
        longestPoint=now;
    }
    for(int i=0;i<(int)G[now];++i){
        if(!v[G[now][i]])dfs1(G[now][i],dep+1);
    }
}
int dfs2(int now,int dep){
    v[now]=1;
    if(dep==longestLength){
        bad.insert(now);
    }
    for(int i=0;i<(int)G[now];++i){
        if(!v[G[now][i]])dfs2(G[now][i],dep+1);
    }
}
void solve(){
    dfs1(1,0);memset(0,v,sizeof(v));
    dfs1(longestPoint,0);memset(0,v,sizeof(v));
    bad.insert(longestPoint);
    dfs2(longestPoint,0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    {int a,b;while(m--){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }}
    solve();
}
