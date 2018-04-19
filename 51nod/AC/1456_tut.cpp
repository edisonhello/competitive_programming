#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005],iG[100005],tp,cG[100005],root;
int bel[100005],sz[100005],djs[100005],ind[100005];
bitset<100005> v;

void dfs(int now){
    v[now]=1;
    for(int i:G[now])if(!v[i])dfs(i);
    tp.push_back(now);
}
void dfs(int now,int cc){
    bel[now]=cc;
    ++sz[cc];
    v[now]=1;
    for(int i:iG[now])if(!v[i])dfs(i,cc);
}

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
bool U(int x,int y){
    x=F(x); y=F(y);
    if(x==y)return 0;
    djs[F(x)]=F(y);
    return 1;
}

int sdf(int now){
    if(v[now])return 0;
    v[now]=1;
    int rt=0;
    for(int i:cG[now]){
        if(!v[i]){
            rt+=sdf(i);
        }
    }
    
    return max(rt,int(sz[now]>1));
}

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        iG[v].push_back(u);
    }
    for(int i=1;i<=n;++i){
        if(!v[i])dfs(i);
    }
    v.reset();
    int cc=0;
    for(int i=n-1;i>=0;--i){
        if(!v[tp[i]])dfs(tp[i],++cc);
    }
    int ans=0;
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i){
        for(int j:G[i]){
            if(bel[i]==bel[j])continue;
            if(U(bel[i],bel[j]))++ans;
        }
    }
    v.reset();
    for(int i=1;i<=cc;++i){
        if(sz[i]>1)v[F(i)]=1;
    }
    // cout<<"now ans: "<<ans<<endl;
    // for(int i=1;i<=cc;++i)if(!ind[i])root.push_back(i);
    // cout<<"root: "; for(int i:root)cout<<i<<" "; cout<<endl;
    // v.reset();
    // for(int r:root)ans+=!!sdf(r);
    // cout<<"ans: "<<ans<<endl;
    // cout<<"ccc: "<<cc<<endl;
    // for(int i=1;i<=cc;++i)cout<<"sz "<<i<<" "<<sz[i]<<endl;
    // for(int i=1;i<=n;++i)cout<<"bel "<<i<<" "<<bel[i]<<endl;
    // for(int i=1;i<=cc;++i)if(sz[i]>1)ans+=sz[i]-1;
    for(int i=1;i<=cc;++i)ans+=sz[i]-1;
    ans+=v.count();
    cout<<ans<<endl;
}
