#include<bits/stdc++.h>

using namespace std;

vector<int> G[88],l[88];
bool vis[88];
bitset<28> v;
map<bitset<28>,int> dp;
int djs[88],sz[88],tot;
bool operator<(const bitset<28> &a,const bitset<28> &b){
    for(int i=0;i<28;++i)if(a[i]!=b[i])return a[i]<b[i];
    return 0;
}

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){
    x=F(x), y=F(y); if(x==y)return;
    djs[x]=y; sz[y]+=sz[x]; --tot;
}
bool C(int x,int y){return F(x)==F(y);}

int dfs(int now){
    auto it=dp.find(v);
    if(it!=dp.end())return it->second;
    vector<int> chlist;
    v[now]=1; for(int i:G[now]){
        if(v[i])continue;
        v[i]=1; chlist.push_back(i);
    }
    int mx=0;
    for(int i:l[F(now)])if(!v[i])mx=max(mx,dfs(i));
    for(int i:chlist)v[i]=0; v[now]=0;
    dp[v]=mx+1;
    return mx+1;
}
int meow(int now){
    int mx=0;
    for(int i:l[now])mx=max(mx,dfs(i));
    return mx;
}

void jizz(int n){
    for(int i=0;i<n;++i)sz[i]=1; tot=n;
    for(int i=0;i<n;++i)for(int j:G[i])U(i,j);
    for(int i=0;i<n;++i)l[F(i)].push_back(i);
    int ans=0;
    for(int i=0;i<n;++i){
        if(!vis[F(i)]){
            dp.clear(); v.reset();
            vis[F(i)]=1;
            ans+=meow(i);
        }
    }
    cout<<ans<<endl;
    exit(0);
}


int __match[88];


bool __dfs(int now){
    for(int i:G[now]){
        if(vis[i])continue;
        vis[i]=1;
        if(__match[i]==-1 || __dfs(__match[i])){
            __match[i]=now;
            __match[now]=i;
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,m;cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    if(n<=24)jizz(n);
    memset(__match,-1,sizeof(__match));
    int ans=0;
    for(int i=0;i<n;++i){
        if(__match[i]==-1){
            memset(vis,0,sizeof(vis));
            if(__dfs(i))++ans;
            // for(int ii=0;ii<n;++ii)cout<<match[ii]<<" ";cout<<endl;
        }
    }
    cout<<max(n-ans,ans)<<endl;
}
