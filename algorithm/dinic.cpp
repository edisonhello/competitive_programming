
#define FLOW_POINTS 7122
struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> G[FLOW_POINTS];

void ae(int u,int v,int f){
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});
    G[v].push_back(edg.size());
    edg.push_back({v,u,0});
}


int dep[FLOW_POINTS],vv[FLOW_POINTS];
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

int cur[FLOW_POINTS];
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
    static int c=0;
    int f=0;
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,0x3f3f3f3f);
    }
    return f;
}
