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

vector<int> G[100005];
int ans[100005],v[100005];

void up(pair<int,int> &a,pair<int,int> b){
    if(b.first>a.first)a=b;
    else if(b.first==a.first && b.second<a.second)a=b;
}

pair<map<int,int>*,pair<int,int>> dfs(int now){
    map<int,int> *rt=new map<int,int>;
    pair<int,int> rec(1,v[now]);
    rt->insert(pair<int,int>(v[now],1));
    for(int i:G[now]){
        map<int,int> *t;
        pair<int,int> rta;
        tie(t,rta)=dfs(i);
        up(rec,rta);
        if(t->size()>rt->size())swap(rt,t);
        for(auto &p:*t){
            int &ii=(*rt)[p.first];
            ii+=p.second;
            up(rec,make_pair(ii,p.first));
        }
        delete t;
    }
    ans[now]=rec.second;
    return make_pair(rt,rec);
}

void sol(){
    int n; cin>>n; 
    for(int i=0;i<=n;++i)G[i].clear();
    for(int i=1;i<=n;++i){
        int p; cin>>p;
        G[p].pb(i);
    }
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i:G[0])dfs(i);
    for(int i=1;i<=n;++i)cout<<ans[i]<<" \n"[i==n];
}

int main(){
    CPPinput;
    int ts; cin>>ts; while(ts--)sol();
}
