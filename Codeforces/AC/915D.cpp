#include<bits/stdc++.h>
using namespace std;
#define lock loooooooskk

struct edge{
    int v,i;
};
vector<edge> v;
vector<int> G[505];
int ban,ind[505],cnt;
vector<int> head;
bitset<505> lock,vz;
bool ok;

void dfs(int now){
    ++cnt; lock[now]=1; vz[now]=1;
    for(int i:G[now]){
        if(v[i].i==ban)continue;
        if(lock[v[i].v] || !ok){ok=0; return;}
        if(vz[v[i].v])continue;
        dfs(v[i].v);
    }
    lock[now]=0;
}

int main(){
    auto ccc=clock();
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    v.resize(m);
    vector<int> vban(m);
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        v[i]={b,i};
        G[a].push_back(i);
        ++ind[b];
        vban[i]=i;
    }
    for(int i=1;i<=n;++i){
        if(!ind[i])head.push_back(i);
        random_shuffle(G[i].begin(),G[i].end());
    }
    random_shuffle(vban.begin(),vban.end());
    for(int iban=0;iban<m;++iban){
        ban=vban[iban];
        if(ind[v[ban].v]==1)head.push_back(v[ban].v);
        ok=1; cnt=0; vz.reset(); lock.reset();
        for(int i:head)dfs(i);
        if(ind[v[ban].v]==1)head.pop_back();
        if(ok && cnt==n)return cout<<"YES"<<endl,0;
        if((float)(clock()-ccc)/CLOCKS_PER_SEC>=0.95)break;
    }
    cout<<"NO"<<endl;
}
