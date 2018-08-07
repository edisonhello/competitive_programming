#include "grader.h"
#include<bits/stdc++.h>

using namespace std;

/* struct edge{
    int u,v,f;
};
vector<edge> edg;
vector<int> G[11115];

void ae(int u,int v,int f){
    // cout<<"addedge: "<<u<<" "<<v<<" "<<f<<endl;
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}

int idx[11115],vis[11115],dep[11115];

bool bfs(int s,int t,int z){
    vis[s]=z; dep[s]=1;
    queue<int> q; q.push(s);
    while(q.size()){
        int now=q.front(); q.pop();
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(vis[e.v]!=z && e.f>0){
                q.push(e.v);
                vis[e.v]=z;
                dep[e.v]=dep[now]+1;
            }
        }
    }
    // cout<<"finish bfs"<<endl;
    return (vis[t]==z);
}

int dfs(int now,int fl,int dis){
    if(now==dis)return fl;
    if(!fl)return 0;
    int rt=0;
    for(int &i=idx[now];i<G[now].size();++i){
        int eid=G[now][i];
        edge &e=edg[eid];
        if(dep[e.v]==dep[now]+1 && e.f>0){
            int f=dfs(e.v,min(fl,e.f),dis);
            rt+=f; fl-=f;
            e.f-=f;
            edg[eid^1].f+=f;
            if(!fl)return rt;
        }
    }
    return rt;
}

int flow(int s,int t){
    int vis_ptr=0,ans=0;
    while(bfs(s,t,++vis_ptr)){
        memset(idx,0,sizeof(idx));
        ans+=dfs(s,1e9,t);
    }
    return ans;
} */

int putaway(int a, int b, int t, int x[], int y[], int w[], int s[]) {
    // cout<<"in: putaway"<<endl;
    if([&]()->bool{
        int xmx=0,ymx=0;
        for(int i=0;i<a;++i)xmx=max(xmx,x[i]);
        for(int i=0;i<b;++i)ymx=max(ymx,y[i]);
        for(int i=0;i<t;++i)if(w[i]>=xmx && s[i]>=ymx)return 1;
        return 0;
    }())return -1;
    vector<pair<int,int>> pz(t);
    for(int i=0;i<t;++i)pz[i].first=w[i],pz[i].second=s[i];
    sort(pz.begin(),pz.end());
    sort(x,x+a);
    sort(y,y+b);
    int L=1,R=t;
    while(R>L){
        // cout<<"BS range "<<L<<" to "<<R<<endl;
        int M=(L+R)>>1;
        if([&](int T)->bool{
            priority_queue<int,vector<int>,less<int>> pq;
            int pzt=0;
            for(int i=0;i<a;++i){
                // cout<<"i: "<<i<<endl;
                while(pzt<t && pz[pzt].first<x[i])pq.push(pz[pzt++].second);
                for(int z=0;z<T;++z)if(pq.size())pq.pop(); else break;
            }
            while(pzt<t)pq.push(pz[pzt++].second);
            for(int i=b-1;i>=0;--i){
                // cout<<"i: "<<i<<endl;
                if(pq.size() && pq.top()>=y[i])return 0;
                for(int z=0;z<T;++z)if(pq.size())pq.pop(); else break;
            }
            return pq.empty();
        }(M))R=M;
        else L=M+1;
    }
    return L;
}
