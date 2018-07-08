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
#define pii pair<long long,int>
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

vector<pair<int,int>> ga[100005],gb[100005];
long long da[100005],db[100005];
bitset<100005> v;

int main(){
    CPPinput;
    int n,m,s,t; cin>>n>>m>>s>>t;
    while(m--){
        int u,v,a,b; cin>>u>>v>>a>>b;
        ga[u].eb(v,a);
        ga[v].eb(u,a);
        gb[u].eb(v,b);
        gb[v].eb(u,b);
    }
    MS(da,0x3f);
    MS(db,0x3f);
    PQ<pii,vector<pii>,greater<pii>> pq;
    pq.emplace(0,s); da[s]=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        PDE("a", now);
        v[now]=1;
        for(auto p:ga[now]){
            if(da[p.first]>da[now]+p.second){
                da[p.first]=da[now]+p.second;
                pq.emplace(da[p.first],p.first);
            }
        }
    }
    v.reset();
    pq.emplace(0,t); db[t]=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        int now=pq.top().second; pq.pop();
        v[now]=1;
        for(auto p:gb[now]){
            if(db[p.first]>db[now]+p.second){
                db[p.first]=db[now]+p.second;
                pq.emplace(db[p.first],p.first);
            }
        }
    }
    stack<long long> ans;
    long long mn=LLONG_MAX;
    for(int i=n;i>=1;--i){
        mn=min(mn,da[i]+db[i]);
        ans.push(mn);
        PDE(i,da[i],db[i]);
    }
    while(ans.size()){
        cout<<1000000000000000-ans.top()<<'\n';
        ans.pop();
    }
}
