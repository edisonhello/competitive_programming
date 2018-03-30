#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&-(x))
#define exit(x) cout<<"exit code "<<x<<endl, exit(x)

struct sptb{
    int **table,level,n;
    void init(int n_){
        n=n_;
        level=0;
        while((1<<level)<n)++level;
        ++level;
        table=new int*[level];
        for(int i=0;i<level;++i)table[i]=new int[n+2];
    }
    void set_number(int x,int v){
        if(x>=n)exit(7122);
        table[0][x]=v;
    }
    void build(){
        for(int D=1,j=1;j<level;++j,D<<=1){
            for(int i=0;i+D*2<=n;++i){
                table[j][i]=min(table[j-1][i],table[j-1][i+D]);
            }
        }
    }
    int query(int l,int r){
        if(l==r)return table[0][l];
        int d=r-l+1;
        int j=0;
        while(d)d>>=1,++j; --j;
        return min(table[j][l],table[j][r-(1<<j)+1]);
    }

    int* operator[](const int x){return table[x];}

    sptb():table(0){}
} table[100005];

int a[100005],in[100005],out[100005],dep[100005],na[200005],mxdep,ntm;
vector<int> G[100005],dep_t_unq[100005];

void dfs(int now,int pa){
    dep[now]=dep[pa]+1;
    mxdep=max(mxdep,dep[now]);
    in[now]=++ntm;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
    }
    out[now]=++ntm;
    dep_t_unq[dep[now]].push_back(in[now]);
    dep_t_unq[dep[now]].push_back(out[now]);
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,n; cin>>n>>r;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(r,r);
    for(int i=1;i<=n;++i){
        na[in[i]]=a[i];
        na[out[i]]=a[i];
        // cout<<"i: in, out: "<<i<<" "<<in[i]<<" "<<out[i]<<endl;
    }
    for(int i=1;i<=mxdep;++i){
        int to=i+lowbit(i);
        if(to>mxdep)continue;
        for(int ii:dep_t_unq[i])dep_t_unq[to].push_back(ii);
    }
    for(int i=1;i<=mxdep;++i)sort(dep_t_unq[i].begin(),dep_t_unq[i].end());
    for(int i=1;i<=mxdep;++i){
        table[i].init(dep_t_unq[i].size());
        // cout<<"table "<<i<<" has: ";
        for(int j=0;j<dep_t_unq[i].size();++j){
            // cout<<dep_t_unq[i][j]<<" ";
            table[i].set_number(j,na[dep_t_unq[i][j]]);
        }
        // cout<<endl;
        table[i].build();
    }
    int last=0;
    int m; cin>>m;
    while(m--){
        int p,q; cin>>p>>q;
        int x=(p+last)%n+1;
        int k=(q+last)%n;
        // cout<<"xk: "<<x<<" "<<k<<endl;
        int ndep=dep[x]+k;
        if(ndep>mxdep)ndep=mxdep;
        int ans=1<<30;
        while(ndep>=dep[x]){
            int lest=lower_bound(dep_t_unq[ndep].begin(),dep_t_unq[ndep].end(),in[x])-dep_t_unq[ndep].begin();
            int rest=upper_bound(dep_t_unq[ndep].begin(),dep_t_unq[ndep].end(),out[x])-dep_t_unq[ndep].begin()-1;
            // cout<<"query "<<ndep<<"table ["<<lest<<","<<rest<<"]"<<endl;
            if(lest<=rest)ans=min(ans,table[ndep].query(lest,rest));
            ndep-=lowbit(ndep);
        }
        cout<<(last=ans)<<'\n';
    }
}
