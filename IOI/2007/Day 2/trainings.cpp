#include<bits/stdc++.h>
using namespace std;

vector<int> Q;
vector<int> idx[1005];
vector<int> G[1005];
int p[1005],d[1005],dp[1005][1<<11],apx[1005],mx[1005];

void dfs1(int now,int pa,int dep){
    p[now]=pa;
    d[now]=dep;
    mx[now]=(1<<G[now].size())-1;
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        apx[G[now][i]]=i;
        dfs1(G[now][i],now,dep+1);
    }
}

void dfs2(int now,int pa){
    for(int i=0;i<G[now].size();++i){
        if(G[now][i]==pa)continue;
        dfs2(G[now][i],now);
    }
    for(int z=0;z<=mx[now];++z){
        for(int i=0;i<G[now].size();++i){
            if(G[now][i]==pa)continue;
            if(z&(1<<i))dp[now][z]+=dp[G[now][i]][mx[G[now][i]]];
        }
    }
    for(int i:idx[now]){
        int u=Q[i],v=Q[i+1],c=Q[i+2];
        if(v==now)swap(u,v);
        if(u==now){
            c+=dp[v][mx[v]];
            while(p[v]!=now){
                c+=dp[p[v]][mx[p[v]]^(1<<apx[v])];
                v=p[v];
            }
            Q[i]=u; Q[i+1]=v; Q[i+2]=c;
        }
        else{
            c+=dp[v][mx[v]]+dp[u][mx[u]];
            while(p[v]!=now){
                c+=dp[p[v]][mx[p[v]]^(1<<apx[v])];
                v=p[v];
            }
            while(p[u]!=now){
                c+=dp[p[u]][mx[p[u]]^(1<<apx[u])];
                u=p[u];
            }
            Q[i]=u; Q[i+1]=v; Q[i+2]=c;
        }
    }
    for(int z=0;z<=mx[now];++z){
        for(int i:idx[now]){
            int u=Q[i],v=Q[i+1],c=Q[i+2];
            // cout<<"(u,v,c): "<<u<<" "<<v<<" "<<c<<endl;
            if(u==now){
                if(z&(1<<apx[v]))dp[now][z]=max(dp[now][z],dp[now][z^(1<<apx[v])]+c);
            }
            else{
                if((z&(1<<apx[v]))&&(z&(1<<apx[u])))dp[now][z]=max(dp[now][z],dp[now][z^(1<<apx[v])^(1<<apx[u])]+c);
            }
        }
        // cout<<"dp["<<now<<"]["<<z<<"]: "<<dp[now][z]<<endl;
    }
}

int main(){
    int n,m; cin>>n>>m;
    int tot=0;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        tot+=c;
        if(!c){
            G[u].push_back(v);
            G[v].push_back(u);
        }
        else{
            Q.push_back(u);
            Q.push_back(v);
            Q.push_back(c);
        }
    }
    dfs1(1,0,1);
    for(int i=0;i<Q.size();i+=3){
        int u=Q[i],v=Q[i+1];
        while(d[u]>d[v])u=p[u];
        while(d[u]<d[v])v=p[v];
        while(u!=v)u=p[u],v=p[v];
        if((d[Q[i]]+d[Q[i+1]]-2*d[u])&1)continue;
        idx[u].push_back(i);
    }
    dfs2(1,0);
    cout<<tot-dp[1][mx[1]]<<endl;
}

// tutorial 30
// rewrite tutorial AC
