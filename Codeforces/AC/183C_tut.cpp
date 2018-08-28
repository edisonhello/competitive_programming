#include<bits/stdc++.h>
using namespace std;

bitset<100005> v;
int co[100005],g,n;
vector<int> G[100005],iG[100005];

void dfs(int now){
    v[now]=1;
    for(int i:G[now]){
        int x=co[now]+1;
        if(v[i]){
            int z=abs(x-co[i]);
            g=__gcd(g,z);
        }
        else{
            co[i]=x;
            dfs(i);
        }
    }
    for(int i:iG[now]){
        int x=co[now]-1;
        if(v[i]){
            int z=abs(x-co[i]);
            g=__gcd(g,z);
        }
        else{
            co[i]=x;
            dfs(i);
        }
    }
}

void dfz(int now){
    v[now]=1;
    for(int i:G[now]){
        int x=co[now]+1;
        if(v[i]){
            int z=abs(x-co[i]);
            if(__gcd(g,z)!=g)g=0;
        }
        else{
            co[i]=x;
            dfs(i);
        }
    }
    for(int i:iG[now]){
        int x=co[now]-1;
        if(v[i]){
            int z=abs(x-co[i]);
            if(__gcd(g,z)!=g)g=0;
        }
        else{
            co[i]=x;
            dfs(i);
        }
    }
}

bool ok(int x){
    v.reset();
    memset(co,0,sizeof(co));
    g=x;
    for(int i=1;i<=n;++i)if(!v[i])dfz(i);

    // cout<<x<<" : "; for(int i=1;i<=n;++i)cout<<co[i]<<" "; cout<<endl;
    return g;
}

int main(){
    ios_base::sync_with_stdio(0);
    int m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        iG[v].push_back(u);
        if(u==v){ exit((cout<<1<<endl,0)); }
    }
    for(int i=1;i<=n;++i)if(!v[i])dfs(i);
    if(g==0){ exit((cout<<n<<endl,0)); }
    if(g==1){ exit((cout<<1<<endl,0)); }
    int G=g;
    // cout<<"g: "<<g<<endl;
    int mx=1;
    for(int i=G;i>=2;--i){
        if(G%i)continue;
        if(ok(i)){ mx=max(mx,i); break; }
    }
    cout<<mx<<endl;
}
