// UVa 1658
int n;
struct edge{
    int u,v,f,c;
    edge(int u,int v,int f,int c):u(u),v(v),f(f),c(c){};
};
vector<int> G[2222];
vector<edge> edg;
void init(){
    for(int i=0;i<2222;++i)G[i].clear();
    edg.clear();
}
void ae(int u,int v,int f,int c){
    G[u].push_back(edg.size());
    G[v].push_back(edg.size()+1);
    edg.push_back(edge(u,v,f,c));
    edg.push_back(edge(v,u,0,-c));
}

vector<bool> inq;
vector<int> nc,bn,cf;
int floww(int &nf){
    queue<int> q;
    nc.clear(), nc.resize(2222);
    bn.clear(), bn.resize(2222);
    cf.clear(), cf.resize(2222);
    inq.clear(),inq.resize(2222);
    for(int i=0;i<2222;++i)nc[i]=1e7;
    q.push(1); nc[1]=0; bn[1]=878787;
    while(q.size()){
        for(int i:G[q.front()]){
            edge e=edg[i];
            if(e.f>0 && nc[e.v] > nc[q.front()]+e.c){
                bn[e.v]=min(e.f,bn[q.front()]);
                nc[e.v]=nc[q.front()]+e.c;
                cf[e.v]=i;
                if(!inq[e.v])q.push(e.v),inq[e.v]=1;
            }
        }
        inq[q.front()]=0; q.pop();
    }
    if(nc[n]>7777777 || bn[n]<=0)return 0;
    for(int u=n;u!=1;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[n];
        edg[cf[u]^1].f+=bn[n];
    }
    return nf+=nc[n]*bn[n];
}

int mcmf(){
    int ans=0;
    floww(ans),floww(ans);
    return ans;
}

main(){
    int m; while(cin>>n>>m){
        init();
        for(int i=2;i<n;++i)ae(i,i+n,1,0);
        while(m--){
            int u,v,c; cin>>u>>v>>c; if(u>1&&u<n)u+=n;
            ae(u,v,1,c);
        }
        cout<<mcmf()<<endl;
    }
}

