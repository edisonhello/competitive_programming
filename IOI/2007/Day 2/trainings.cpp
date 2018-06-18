#include<bits/stdc++.h>
using namespace std;

struct paved{
    int u,v,c,vside,uside,dpdelta;
};
vector<paved> edg[1005];
vector<int> G[1005];
int p[12][1005],d[1005],dp[1005][1<<11],apx[1005],mxmsk[1005];

void dfs(int now,int pa,int dep){
    mxmsk[now]=(1<<G[now].size())-1;
    d[now]=dep;
    p[0][now]=pa;
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        apx[G[now][i]]=i;
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now,dep+1);
    }
}

int glca(int pa,int pb){
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<12;++i)if((d[pb]-d[pa])&(1<<i)){
        pb=p[i][pb];
    }
    if(pa==pb)return pa;
    for(int i=11;i>=0;--i)if(p[i][pa]!=p[i][pb]){
        pa=p[i][pa];
        pb=p[i][pb];
    }
    return p[0][pa];
}

void dfs(int now,int pa){
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
    }
    for(int z=0;z<=mxmsk[now];++z){
        for(int i=0;i<G[now].size();++i){
            if(G[now][i]==pa)continue;
            if(z&(1<<i)); else break;
            dp[now][z]+=dp[G[now][i]][mxmsk[G[now][i]]];
        }
    }
    for(paved &e:edg[now]){
        if(now==e.u || now==e.v){
            if(now==e.v)swap(e.u,e.v);
            int vside=e.v,dpdelta=e.c+dp[e.v][mxmsk[e.v]];
            while(p[0][vside]!=now){
                dpdelta+=dp[p[0][vside]][mxmsk[p[0][vside]]^(1<<apx[vside])];
                vside=p[0][vside];
            }
            e.vside=vside;
            e.dpdelta=dpdelta;
        }
        else{
            int vside=e.v,uside=e.u,dpdelta=e.c+dp[e.v][mxmsk[e.v]]+dp[e.u][mxmsk[e.u]];
            while(p[0][vside]!=now){
                dpdelta+=dp[p[0][vside]][mxmsk[p[0][vside]]^(1<<apx[vside])];
                vside=p[0][vside];
            }
            while(p[0][uside]!=now){
                dpdelta+=dp[p[0][uside]][mxmsk[p[0][uside]]^(1<<apx[uside])];
                uside=p[0][uside];
            }
            e.uside=uside;
            e.vside=vside;
            e.dpdelta=dpdelta;
        }
    }
    for(int z=0;z<=mxmsk[now];++z){
        for(paved e:edg[now]){
            if(now==e.u || now==e.v){
                if(z&(1<<apx[e.vside])); else continue;
                dp[now][z]=max(dp[now][z],dp[now][z^(1<<apx[e.vside])]+e.dpdelta);
            }
            else{
                if(z&(1<<apx[e.vside])); else continue;
                if(z&(1<<apx[e.uside])); else continue;
                dp[now][z]=max(dp[now][z],dp[now][z^(1<<apx[e.vside])^(1<<apx[e.uside])]+e.dpdelta);
            }
        }
    }
    /* for(int z=0;z<=mxmsk[now];++z){
        cout<<"dp "<<now<<" "<<z<<" "<<dp[now][z]<<endl;
    } */
}

int main(){
    int n,m; cin>>n>>m;
    queue<int> tmp;
    int totc=0;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        if(!c){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        else{
            tmp.push(u);
            tmp.push(v);
            tmp.push(c);
            totc+=c;
        }
    }
    dfs(1,1,1);
    // cout<<"after first dfs"<<endl;
    for(int i=1;i<12;++i)for(int j=1;j<=n;++j)p[i][j]=p[i-1][p[i-1][j]];
    // cout<<"after doubling"<<endl;
    while(tmp.size()){
        int u,v,c;
        u=tmp.front(); tmp.pop();
        v=tmp.front(); tmp.pop();
        c=tmp.front(); tmp.pop();
        // cout<<u<<" "<<v<<" "<<c<<endl;
        int lca=glca(u,v);
        if((d[u]+d[v]-d[lca]*2)&1)continue;
        edg[glca(u,v)].push_back({u,v,c,v,u,-7122});
    }
    dfs(1,1);
    cout<<totc-dp[1][mxmsk[1]]<<endl;
}

// tutorial 30
