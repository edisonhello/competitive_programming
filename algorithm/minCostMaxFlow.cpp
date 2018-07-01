
template <typename T> class minCostMaxFlow{
private:
    struct edge{
        int u,v;
        T cap,cst;
        edge(int u=0,int v=0,T cap=0,T cst=0):u(u),v(v),cap(cap),cst(cst){};
    };
    int n;
    vector<bool> inq;
    vector<int> source;
    vector<T> bottle,cost;
    vector<vector<int>> G;
    vector<edge> edg;
    T INF;
    bool wolf(int s,int t,T &_flow,T &_cost){
        fill(inq.begin(),inq.end(),0);
        fill(cost.begin(),cost.end(),INF);
        bottle[s]=INF; cost[s]=0;
        queue<int> q; q.push(s);
        while(q.size()){
            for(int &eid:G[q.front()])if(edg[eid].cap>0 && cost[edg[eid].v]>cost[edg[eid].u]+edg[eid].cst){
                if(!inq[edg[eid].v])inq[edg[eid].v]=1,q.push(edg[eid].v);
                bottle[edg[eid].v]=min(bottle[edg[eid].u],edg[eid].cap);
                cost[edg[eid].v]=cost[edg[eid].u]+edg[eid].cst;
                source[edg[eid].v]=eid;
            }
            inq[q.front()]=0; q.pop();
        }
        if(cost[t]==INF)return 0;
        for(int u=t;u!=s;u=edg[source[u]].u){
            edg[source[u]].cap-=bottle[t];
            edg[source[u]^1].cap+=bottle[t];
        }
        _flow+=bottle[t]; _cost+=bottle[t]*cost[t];
        return 1;
    }
public:
    minCostMaxFlow(int n=0,T inf=1073741824){setN(n); INF=inf;}
    int setN(int N){
        inq.resize(N);
        source.resize(N);
        bottle.resize(N);
        cost.resize(N);
        G.clear(); G.resize(N);
        edg.clear();
        return n=N;
    }
    void addEdge(int u,int v,T cap,T cst){
        G[u].push_back(edg.size());
        edg.emplace_back(u,v,cap,cst);
        G[v].push_back(edg.size());
        edg.emplace_back(v,u,0,-cst);
    }
    pair<T,T> flow(int s,int t){
        T flow=0,cost=0;
        while(wolf(s,t,flow,cost));
        return pair<T,T>(flow,cost);
    }
};
