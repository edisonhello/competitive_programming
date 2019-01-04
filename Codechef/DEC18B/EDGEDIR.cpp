#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
pair<int,int> edg[100005];
set<pair<int,int>> ast,exi;
bitset<100005> vis;

pair<int,int> make_edge(int u,int v){
    return make_pair(min(u,v),max(u,v));
}

int dfs(int now,int pa){
    vis[now]=1;
    int la=-1;
    for(int i:G[now]){
        if(i==pa)continue;
        if(vis[i]){
            if(exi.count(make_edge(i,now))==0)continue;
            if(la!=-1){
                ast.insert(make_pair(la,now));
                ast.insert(make_pair(i,now));
                exi.erase(make_edge(la,now));
                exi.erase(make_edge(i,now));
                la=-1;
            }
            else la=i;
        }
        else{
            int r=dfs(i,now);
            if(!r)continue;
            if(la!=-1){
                ast.insert(make_pair(la,now));
                ast.insert(make_pair(i,now));
                exi.erase(make_edge(la,now));
                exi.erase(make_edge(i,now));
                la=-1;
            }
            else la=i;
        }
    }
    if(la==-1)return 1;
    exi.erase(make_edge(la,now));
    exi.erase(make_edge(pa,now));
    ast.insert(make_pair(la,now));
    ast.insert(make_pair(pa,now));
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        ast.clear();
        vis.reset();
        exi.clear();
        for(int i=1;i<=m;++i){
            int u,v; cin>>u>>v;
            G[u].emplace_back(v);
            G[v].emplace_back(u); 
            edg[i]={u,v};
            exi.insert(make_edge(u,v));
        }
        int st=dfs(1,0);
        if(st){
            for(int i=1;i<=m;++i){
                if(ast.count(edg[i]))cout<<"0 ";
                else cout<<"1 ";
            }
            cout<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        for(int i=1;i<=n;++i)G[i].clear();
    }
}
