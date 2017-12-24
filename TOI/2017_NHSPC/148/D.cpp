#include<bits/stdc++.h>
using namespace std;

vector<int> G[200006];
int djs[200006];
bitset<200006> v;
int cnt[2][200006];

int F(int x){return djs[x]==x?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

void dfs(int now){
    v[now]=1;
    for(int i:G[now]){
        if(v[i])continue;
        U(now,i);
        dfs(i);
    }
}

void meow(int p,int q,int k){
    int n=p+q;
    for(int i=1;i<=n;++i){
        djs[i]=i;
        cnt[0][i]=cnt[1][i]=0;
    }
    v.reset();
    for(int i=1;i<=n;++i){
        if(!v[i])dfs(i);
    }
    for(int i=1;i<=n;++i){
        if(i<=p)++cnt[0][F(i)];
        else ++cnt[1][F(i)];
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        ans+=min(cnt[0][i],cnt[1][i]);
    }
    cout<<ans<<endl;
}

int main(){
    int ts; cin>>ts; while(ts--){
        int p,q,k; cin>>p>>q>>k;
        for(int i=0;i<p+q+3;++i)G[i].clear();
        while(k--){
            int u,v; cin>>u>>v; v+=p;
            G[v].push_back(u);
            G[u].push_back(v);
        }
        meow(p,q,k);
    }
}
