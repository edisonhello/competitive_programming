#include<bits/stdc++.h>
using namespace std;

bitset<200005> v;
int djs[200005],sz[200005],tp[200005];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y); if(x==y)return; djs[x]=y; sz[y]+=sz[x];}
vector<int> G[200005];

void dfs(int now,int type=1){
    v[now]=1;
    tp[now]=type;
    for(int i:G[now]){
        if(!v[i]){
            dfs(i,-type);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)djs[i]=i,sz[i]=1;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        U(u,v);
    }
    for(int i=1;i<=n;++i){
        if(sz[F(i)]==1){
            cout<<"NIE"<<endl;
            exit(0);
        }
    }
    for(int i=1;i<=n;++i){
        if(F(i)==i)dfs(i);
    }
    cout<<"TAK"<<endl;
    for(int i=1;i<=n;++i)cout<<(tp[i]==1?"K":"S")<<'\n';
}
