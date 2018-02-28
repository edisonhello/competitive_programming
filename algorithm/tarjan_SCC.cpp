
struct tarjan{
    const int maxn=100005;
    int n,sccs,low[maxn],in[maxn],bel[maxn];
    bitset<maxn> instack;
    stack<int> st;
    vector<int> member[maxn],G[maxn];

    inline void init(int _n=maxn){
        n=_n;
        for(int i=0;i<n;++i)member[i].clear(),G[i].clear();
    }
    inline void addedge(int u,int v){G[u].push_back(v);}
    inline void ae(int u,int v){addedge(u,v);}
    void tarjan(int now){
        low[now]=in[now]=++dfst;
        instack[now]=1; st.push(now);
        for(int i:G[now]){
            if(!in[i]){
                tarjan(i);
                low[now]=min(low[now],low[i]);
            }
            else if(instack[i])low[now]=min(low[now],in[i]);
        }
        if(low[now]==in[now]){
            int u=-1;
            while(u!=now){
                u=st.top(); st.pop();
                instack[u]=0;
                bel[u]=sccs;
                member[sccs].push_back(u);
            }
            ++sccs;
        }        
    }
    inline void SCC(){for(int i=0;i<n;++i)if(!in[i])tarjan(i);}
};
