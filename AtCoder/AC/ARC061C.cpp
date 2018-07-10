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

vector<pair<int,int>> edg[1000006],G[3000006];

int djs[100005];
int F(int x){ return djs[x]==x?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }
int nnid[100005];
bitset<3000005> v;
int d[3000005];

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)djs[i]=i;
    while(m--){
        int u,v,c; cin>>u>>v>>c;
        edg[c].eb(u,v);
        U(u,v);
    }
    if(F(1)!=F(n))exit((cout<<-1<<endl,0));
    for(int i=1;i<=n;++i)djs[i]=i;
    int zz=200000;
    
    for(int i=1;i<=1000000;++i){
        for(auto &p:edg[i])U(p.first,p.second);
        for(auto &p:edg[i]){
            int to=F(p.first);
            int id=(nnid[to]?nnid[to]:nnid[to]=++zz);
            G[p.first].eb(id,1);
            G[p.second].eb(id,1);
            G[id].eb(p.first,0);
            G[id].eb(p.second,0);
            // cout<<"link "<<p.first<<" and "<<p.second<<" to "<<id<<endl;
        }
        for(auto &p:edg[i])nnid[F(p.first)]=0;
        for(auto &p:edg[i])djs[p.first]=p.first,djs[p.second]=p.second;
    }

    PQ<pii,vector<pii>,greater<pii>> pq;
    MS(d,0x3f); d[1]=0;
    pq.emplace(0,1);
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        v[now]=1;
        for(auto &p:G[now]){
            if(d[p.first]>d[now]+p.second){
                d[p.first]=d[now]+p.second;
                pq.emplace(d[p.first],p.first);
            }
        }
    }
    cout<<d[n]<<endl;
}
