#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define int long long
struct edge{ll u,v,w;bool us;} eg[200009];
struct eege{ll u,w;};
vector<eege> G[100009];
int djs[100009];
int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}
bool C(int x,int y){return F(x)==F(y);}
int p[20][100009],d[100009];
ll mx[20][100009];

void dfs(int now,int pa,int dep,ll r){
    d[now]=dep; p[0][now]=pa; mx[0][now]=r;
    for(int i=1;i<20;++i){
        if((1<<i)>dep)break;
        p[i][now]=p[i-1][p[i-1][now]];
        mx[i][now]=max(mx[i-1][now],mx[i-1][p[i-1][now]]);
    }
    for(auto i:G[now]){
        if(i.u==pa)continue;
        dfs(i.u,now,dep+1,i.w);
    }
}
ll meow(int pa,int pb){
    ll r=0;
    if(d[pb]<d[pa])swap(pa,pb);
    for(int i=0;i<20;++i){
        if((1<<i)&(d[pb]-d[pa])){
            r=max(r,mx[i][pb]);
            pb=p[i][pb];
            if(d[pa]==d[pb])break;
        }
    }
    if(pa==pb)return r;
    for(int i=19;i>=0;--i){
        if(p[i][pa]==p[i][pb])continue;
        r=max({r,mx[i][pa],mx[i][pb]});
        pa=p[i][pa],pb=p[i][pb];
    }
    return max({r,mx[0][pa],mx[0][pb]});
}

main(){
    int n,m;cin>>n>>m;
    for(int i=0;i<m;++i){
        int u,v,w; cin>>u>>v>>w;
        eg[i]={u,v,w,0};
    }
    sort(eg,eg+m,[](const edge &a,const edge &b){return a.w<b.w;});
    for(int i=0;i<=100005;++i)djs[i]=i;
    ll MST=0;
    for(int i=0;i<m;++i){
        if(C(eg[i].u,eg[i].v))continue;
        U(eg[i].u,eg[i].v);
        MST+=eg[i].w;
        G[eg[i].u].push_back({eg[i].v,eg[i].w});
        G[eg[i].v].push_back({eg[i].u,eg[i].w});
        eg[i].us=1;
    }
    dfs(1,0,0,0);
    ll MMST=99999999999999999ll;
    for(int i=0;i<m;++i){
        if(eg[i].us)continue;
        ll jizz=MST-meow(eg[i].u,eg[i].v)+eg[i].w;
        if(jizz==MST)continue;
        MMST=min(MMST,MST-meow(eg[i].u,eg[i].v)+eg[i].w);
    }
    cout<<MMST<<endl;
}
