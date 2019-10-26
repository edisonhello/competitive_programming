#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
};
vector<edge> G;

int djs[100005];
long long tw[100005];

int F(int x){ return djs[x]==x?x:djs[x]=F(djs[x]); }
int U(int x,int y){ djs[F(x)]=F(y); }

bool ok(edge e){
    if(F(e.u)==F(e.v)){
        if(e.w<
    }
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>tw[i],djs[i]=i;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        G.push_back({u,v,w});
    }
    sort(G.begin(),G.end(),[&](const edge &a,const edge &b){ return a.w<b.w });
    int ans=0;
    for(auto &e:G){
        if(ok(e))U(e.u,e.v);
        else ++ans;
    }
    cout<<ans<<endl;
}
