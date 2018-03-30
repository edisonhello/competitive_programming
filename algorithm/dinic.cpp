#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> G[84504];

void ae(int u,int v,int f){
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}


int dep[84504],vv[84504];
bool bfs(int s,int t,int c){
    queue<int> q; q.push(s);
    dep[s]=0; vv[s]=c;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f>0 && vv[e.v]!=c){
                vv[e.v]=c;
                q.push(e.v);
                dep[e.v]=dep[now]+1;
            }
        }
    }
    return vv[t]==c;
}

int cur[84503];
int dfs(int now,int t,int fl){
    if(fl==0)return 0;
    if(t==now)return fl;
    int f=0,df;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        while(e.f && dep[e.v]==dep[now]+1 && (df=dfs(e.v,t,min(fl,e.f)))){
            f+=df;
            fl-=df;
            e.f-=df;
            edg[G[now][i]^1].f+=df;
            if(!fl)break;
        }
    }
    return f;
}


int flow(int s,int t){
    int f=0,c=0;
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,0x3f3f3f3f);
    }
    return f;
}
