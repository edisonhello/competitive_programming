#include<bits/stdc++.h>
using namespace std;

int a[200005];
vector<int> G[200005];

bitset<200005> np;
vector<int> p;
vector<int> mem[200005];

void init(){
    for(int i=2;i<=200000;++i){
        if(np[i])continue;
        p.push_back(i);
        for(auto j=1ll*i*i;j<=200000;j+=i){
            np[j]=1;
        }
    }
}

bitset<200005> ok;
bitset<200005> vis;
vector<int> part;
int d[200005];

int dfs(int now){
    part.push_back(now);
    vis[now]=1;
    for(int i:G[now]){
        if(!ok[i])continue;
        if(vis[i])continue;
        d[i]=d[now]+1;
        dfs(i);
    }
}

int main(){
    init();
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        int x=a[i];
        for(long long j:p){
            bool fi=1;
            while(x%j==0){
                if(fi)mem[j].push_back(i),fi=0;
                x/=j;
            }
            if(j*j>x)break;
        }
        if(x>1)mem[x].push_back(i);
    }
    if([&](){ for(int i=1;i<=n;++i)if(a[i]!=1)return 0; return 1; }())exit((cout<<0<<endl,0));
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mx=1;
    for(int i=2;i<=200000;++i){
        if(np[i])continue;
        for(int j:mem[i])ok[j]=1,vis[j]=0,d[j]=0;
        for(int j:mem[i]){
            if(vis[j])continue;
            part.clear();
            dfs(j);
            for(int k:part)vis[k]=0;
            int mxi=j;
            for(int k:part)if(d[k]>d[mxi])mxi=k;
            for(int k:part)d[k]=0;
            dfs(mxi);
            for(int k:part)if(d[k]>d[mxi])mxi=k;
            mx=max(mx,d[mxi]+1);
        }
        for(int j:mem[i])ok[j]=0;
    }
    cout<<mx<<endl;
}
