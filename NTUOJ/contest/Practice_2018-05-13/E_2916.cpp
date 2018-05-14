#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[100005];
int d[100005],p[20][100005],sz[100005],mx[20][100005],mn[20][100005];

void dfsz(int now,int pa,int dep){
    sz[now]=1;
    p[0][now]=pa;
    d[now]=dep;
    for(int i=1;(1<<i)<=dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
        mx[i][now]=max(mx[i-1][now],mx[i-1][p[i-1][now]]);
        mn[i][now]=min(mn[i-1][now],mn[i-1][p[i-1][now]]);
    }
    for(auto &i:G[now]){
        if(i.first==pa)continue;
        mn[0][i.first]=mx[0][i.first]=i.second;
        dfsz(i.first,now,dep+1);
        sz[now]+=sz[i.first];
    }
}

pair<int,int> glca(int pa,int pb){
    if(d[pa]>d[pb])swap(pa,pb);
    int x=0,n=0x3f3f3f3f;
    for(int i=0;i<20;++i){
        if((d[pb]-d[pa])&(1<<i)){
            x=max(x,mx[i][pb]);
            n=min(n,mn[i][pb]);
            pb=p[i][pb];
        }
    }
    if(pa==pb)return make_pair(n,x);
    for(int i=19;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            x=max(x,mx[i][pb]);
            n=min(n,mn[i][pb]);
            x=max(x,mx[i][pa]);
            n=min(n,mn[i][pa]);
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    x=max(x,mx[0][pa]);
    x=max(x,mx[0][pb]);
    n=min(n,mn[0][pa]);
    n=min(n,mn[0][pb]);
    return make_pair(n,x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(cin>>n){

        for(int i=0;i<n;++i)G[i].clear();
        memset(p,0,sizeof(p));
        memset(d,0,sizeof(d));
        // memset(mx,0,sizeof(mx));
        // memset(mn,0x3f,sizeof(mn));

        for(int i=1,u,v,c;i<n;++i){
            cin>>u>>v>>c;
            G[u].emplace_back(v,c);
            G[v].emplace_back(u,c);
        }
        mx[0][1]=mn[0][1]=0;
        dfsz(1,1,0);
        // dfs(1,1,++cc,1);
        int q; cin>>q; while(q--){
            int a,b; cin>>a>>b;
            auto res=glca(a,b);
            cout<<res.first<<" "<<res.second<<'\n';
        }
        cout<<endl;
    }
}
