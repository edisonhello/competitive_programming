#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
using namespace std;
#define ll long long
#define abs(x) ((x)>0?(x):-(x))

ll a[100005],s[100005],ans,tot;
vector<int> G[100005];

void dfs(int now,int pa){
    s[now]=a[now];
    for(int it=0,i;it<G[now].size();++it){
        i=G[now][it];
        if(i==pa)continue;
        dfs(i,now);
        s[now]+=s[i];
    }
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ks=0; while(scanf("%d%d",&n,&m),n){
        if(n!=m+1)exit(7122);
        ans=1ll<<60;
        tot=0;
        for(int i=1;i<=n;++i)G[i].clear();
        for(int i=1;i<=n;++i)scanf("%lld",&a[i]),tot+=a[i];
        for(int i=1,u,v;i<n;++i){
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1);
        for(int i=1;i<=n;++i)ans=min(ans,abs(tot-s[i]-s[i]));
        printf("Case %d: %lld\n",++ks,ans);
    }
}
