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

struct edge{
    int v,c,w;
};

vector<edge> G[100005];
vector<pair<ll,int>> d[100005];
set<pair<int,int>> v;

int main(){
    CPPinput;
    int n,m,c; cin>>n>>m>>c;
    while(m--){
        int u,v,w,c; cin>>u>>v>>w>>c;
        G[u].push_back({v,c,w});
    }
    int s,q; cin>>s>>q;
    [&](int s){
        for(int i=1;i<=n;++i)d[i].resize(2,pair<ll,int>(1e18,-1));
        d[s].clear();
        d[s].resize(2,pair<ll,int>(0,-1));
        PDE(d[s],d[2]);
        priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>> pq;
        pq.push(make_pair(0,make_pair(s,-1)));
        while(pq.size()){
            while(pq.size() && v.find(pq.top().second)!=v.end())pq.pop();
            if(pq.empty())break;
            auto now=pq.top();
            PDE(now);
            pq.pop();
            v.insert(now.second);
            for(edge &e:G[now.second.first]){
                PDE(e.v,e.c,e.w);
                ll nd=(e.c==d[now.second.first][0].second?d[now.second.first][1].first:d[now.second.first][0].first)+e.w;
                PDE(nd);
                PDE(d[e.v]);
                if(nd>=d[e.v][1].first)continue;
                PDE("not continue");
                d[e.v].push_back(make_pair(nd,e.c));
                sort(d[e.v].begin(),d[e.v].end());
                unique(d[e.v].begin(),d[e.v].end(),[](const pair<ll,int> &a,const pair<ll,int> &b){return a.second==b.second;});
                d[e.v].resize(2);
                pq.push(make_pair(nd,make_pair(e.v,e.c)));
            }
        }
    }(s);
    while(q--){
        int t; cin>>t;
        if(d[t][0].first>1e17)d[t][0].first=-1;
        cout<<d[t][0].first<<'\n';
    }
}
