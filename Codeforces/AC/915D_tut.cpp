#include<bits/stdc++.h>
using namespace std;
#define lock loooooooskk

struct edge{
    int u,v,i;
};
vector<edge> v;
vector<int> G[505];
int ban,cnt;
vector<int> head,cmem;
bitset<505> lock,vz;
bool ok;

void dfs(int now){
    if(vz[now])return;
    ++cnt; lock[now]=1; vz[now]=1;
    for(int i:G[now]){
        if(v[i].i==ban)continue;
        if(lock[v[i].v] || !ok){ok=0; return;}
        if(vz[v[i].v])continue;
        dfs(v[i].v);
    }
    lock[now]=0;
}


bool circle(int now){
    if(lock[now])return 1;
    if(vz[now])return 0;
    vz[now]=1; lock[now]=1;
    for(int i:G[now]){
        if(circle(v[i].v)){
            cmem.push_back(v[i].i);
            return 1;
        }
    }
    lock[now]=0;
    return 0;
}

int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    v.resize(m);
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        v[i]={a,b,i};
        G[a].push_back(i);
    }
    for(int i=1;i<=n;++i){
        vz.reset();
        if(circle(i))break;
    }
    if(cmem.empty())return cout<<"YES"<<endl,0;

    for(int _ban:cmem){
        ban=_ban;
        ok=1; cnt=0; vz.reset(); lock.reset();
        for(int i=1;i<=n;++i)dfs(i);
        if(ok && cnt==n)return cout<<"YES"<<endl,0;
    }
    cout<<"NO"<<endl;
}
