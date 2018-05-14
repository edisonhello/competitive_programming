#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int cnt[100005],p[20][100005],d[100005];

void dfs(int now,int pa,int dep){
    p[0][now]=pa;
    d[now]=dep;
    for(int i=1;(1<<i)<=dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,dep+1);
    }
}
int glca(int pa,int pb){
    if(pa==pb)return pa;
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<20;++i){
        if((d[pb]-d[pa])&(1<<i)){
            pb=p[i][pb];
        }
    }
    if(pa==pb)return pa;
    for(int i=19;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return p[0][pa];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;++i)G[i].clear();
        memset(cnt,0,sizeof(cnt));
        memset(p,0,sizeof(p));
        memset(d,0,sizeof(d));
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[v].push_back(u);
            G[u].push_back(v);
        }
        dfs(1,1,0);
        for(int i=0,u,v;i<k;++i){
            cin>>u>>v;
            ++cnt[glca(u,v)];
        }
        int mx=*max_element(cnt,cnt+1+n);
        int z=0;
        for(int i=1;i<=n;++i)if(cnt[i]==mx){z=i;break;}
        cout<<z<<'\n';
    }
}
