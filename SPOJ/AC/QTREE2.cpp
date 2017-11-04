#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[10008];
int d[10008],p[15][10008],sum[15][10008],in[10008],out[10008],timer;
void dfs(int now,int pa,int dep){
    in[now]=++timer;
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;(1<<i)<dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
        sum[i][now]=sum[i-1][now]+sum[i-1][p[i-1][now]];
    }
    for(auto &i:G[now]){
        if(i.first==pa)continue;
        sum[0][i.first]=i.second;
        dfs(i.first,now,dep+1);
    }
    out[now]=++timer;
}
inline int getlca(int pa,int pb){
    if(d[pb]<d[pa])swap(pa,pb);
    for(int i=0;i<15;++i){
        if((1<<i)&(d[pb]-d[pa])){
            pb=p[i][pb];
        }
    }
    if(pa==pb)return pa;
    for(int i=14;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return p[0][pa];
}
inline int getlen(int pa,int pb){
    int ret=0;
    if(d[pb]<d[pa])swap(pa,pb);
    for(int i=0;i<15;++i){
        if((1<<i)&(d[pb]-d[pa])){
            ret+=sum[i][pb];
            pb=p[i][pb];
        }
    }
    if(pa==pb)return ret;
    for(int i=14;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            ret+=sum[i][pa]+sum[i][pb];
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return ret+sum[0][pa]+sum[0][pb];
}
inline int getpa(int pa,int stp){
    for(int i=0;(1<<i)<=stp;++i){
        if(stp&(1<<i)){
            pa=p[i][pa];
        }
    }
    return pa;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
#define MS(x) memset(x,0,sizeof(x))
    for(int i=0;i<10008;++i)G[i].clear();
    MS(d), MS(p), MS(sum), MS(in), MS(out);
    timer=0;
    int n; cin>>n;
    for(int i=1,u,v,k;i<n;++i){
        cin>>u>>v>>k;
        G[u].emplace_back(v,k);
        G[v].emplace_back(u,k);
    }
    dfs(1,0,1);
    /*
    for(int i=0;i<=3;++i){
        for(int j=1;j<=n;++j){
            cout<<p[i][j]<<" ";
        } cout<<endl;
    }
    for(int i=0;i<=3;++i){
        for(int j=1;j<=n;++j){
            cout<<sum[i][j]<<" ";
        } cout<<endl;
    }
    */
    while(0==0){
        string str; cin>>str; if(str=="DONE")break;
        if(str[0]=='D'){
            int a,b; cin>>a>>b;
            cout<<getlen(a,b)<<endl;
        }
        else{
            int s,t,k; cin>>s>>t>>k; --k;
            int ca=getlca(s,t);
            if(k>d[s]+d[t]-d[ca]*2)cout<<-1<<endl;
            else if(k<=d[s]-d[ca])cout<<getpa(s,k)<<endl;
            else cout<<getpa(t,d[s]+d[t]-d[ca]*2-k)<<endl;
        }
    }
}}
