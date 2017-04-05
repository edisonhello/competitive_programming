#include<cstdio>
#include<algorithm>
using namespace std;
#include<vector>

vector<int> G[100005];
const int lg=18;
int p[18][100005],d[100005];

void dfs(int now,int par,int dep){
    p[0][now]=par;
    d[now]=dep;
    for(int i=1;i<lg;++i){
        if((1<<i)>dep)break;
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int &i:G[now]){
        if(i==par)continue;
        dfs(i,now,dep+1);
    }
}
int lca(int pa,int pb){
    if(pa==pb)return pa;
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<lg;++i){
        if((d[pb]-d[pa])&(1<<i))pb=p[i][pb];
        if(d[pa]==d[pb])break;
    }
    if(pa==pb)return pa;
    for(int i=lg-1;i>=0;--i){
        if(p[i][pa]!=p[i][pb])pa=p[i][pa],pb=p[i][pb];
        if(pa==pb)break;
    }
    if(pa==pb)return pa;
    return p[0][pa];
}

int main(){
    int ts;scanf("%d",&ts);while(ts--){
        int n,q;scanf("%d%d",&n,&q);
        {
            for(int i=1;i<=n;++i){
                for(int j=0;j<lg;++j)p[j][i]=0;
                G[i].clear();
                d[i]=0;
            }
        }
        {
            for(int i=1,a,b;i<n;++i){
                scanf("%d%d",&a,&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }
        dfs(1,0,0);
        {
            while(q--){
                int u,v,w;scanf("%d%d%d",&u,&v,&w);
                int a=lca(u,v),
                    b=lca(u,w),
                    c=lca(v,w);
                if(d[a]>d[b])printf("%d\n",a);
                else if(d[a]==d[c])printf("%d\n",b);
                else printf("%d\n",c);
            }
        }
    }
}
