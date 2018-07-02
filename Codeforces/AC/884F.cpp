// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
// #pragma GCC diagnostic ignored "-W"

#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define exp expexpexpexp
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

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
        PDE(u,v,cap,cst);
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
    void printEdge(){
        for(edge &e:edg){
            PDE(e.u,e.v,e.cap,e.cst);
        }
    }
} ;

minCostMaxFlow<int> solver(2005);

int b[111];

int main(){
    CPPinput;
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n;++i)cin>>b[i];
    int ans=0;
    for(int i=0;i<n;++i)ans+=b[i];
    int state_pointer=n+1;
    map<pair<int,char>,int> mp;
    for(int i=0;i<n;++i)solver.addEdge(0,i+1,1,0);
    for(int i=0;i<n;++i)solver.addEdge(1999-s[i]+'a',2000,1,0);
    for(int i=0;i<n/2;++i){
        for(int j='a';j<='z';++j){
            mp[make_pair(i,j)]=state_pointer;
            // solver.addEdge(state_pointer,2000,1,0);
            solver.addEdge(state_pointer,1999-j+'a',1,0);
            ++state_pointer;
        }
    }
    for(int i=0;i<n;++i){
        int to=min(i,n-1-i);
        for(int j='a';j<='z';++j){
            solver.addEdge(i+1,mp[make_pair(to,j)],1,j==s[i]?0:b[i]);
        }
    }
    auto rt=solver.flow(0,2000);
    solver.printEdge();
    PDE(rt);
    cout<<ans-rt.second<<endl;
}
