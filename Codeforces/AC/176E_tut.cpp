// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

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
#define vpii vector<pair<int,int>>
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

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

ll w[18][100005],p[18][100005];
vector<pii> G[100005];
int in[100005],d[100005],dt;

void dfs(int now,int pa,int dep){
    in[now]=++dt;
    d[now]=dep;
    p[0][now]=pa;
    for(int i=1;i<18;++i)p[i][now]=p[i-1][p[i-1][now]],w[i][now]=w[i-1][now]+w[i-1][p[i-1][now]];
    for(auto p:G[now]){
        if(p.first==pa)continue;
        w[0][p.first]=p.second;
        dfs(p.first,now,dep+1);
    }
}

bool cmp(const int &a,const int &b){ return in[a]<in[b]; }
set<int,decltype(&cmp)> st(cmp);
ll ans;

ll dis(int pa,int pb){
    // cout<<"call dist "<<pa<<" "<<pb<<endl;
    if(d[pa]>d[pb])swap(pa,pb);
    ll rt=0;
    for(int i=17;i>=0;--i)if((d[pb]-d[pa])&(1<<i)){
        rt+=w[i][pb];
        pb=p[i][pb];
    }
    if(pa==pb)return rt;
    for(int i=17;i>=0;--i)if(p[i][pa]!=p[i][pb]){
        rt+=w[i][pa]+w[i][pb];
        pa=p[i][pa];
        pb=p[i][pb];
    }
    return rt+w[0][pa]+w[0][pb];
}

void add(int x){
    if(st.size()==0u){ st.insert(x); return; }
    // if(st.size()==1u){ ans+=dis(x,*st.begin())*2; st.insert(x); return; }
    auto it=st.lower_bound(x);
    int le=(it==st.begin()?*prev(st.end()):*prev(it));
    int ri=(it==st.end()?*st.begin():*it);
    ans-=dis(le,ri);
    ans+=dis(le,x);
    ans+=dis(x,ri);
    st.insert(x);
}
void rem(int x){
    st.erase(x);
    if(st.size()==0u)return;
    // if(st.size()==1u){ ans-=dis(x,*st.begin())*2; st.insert(x); return; }
    auto it=st.lower_bound(x);
    int le=(it==st.begin()?*prev(st.end()):*prev(it));
    int ri=(it==st.end()?*st.begin():*it);
    ans+=dis(le,ri);
    ans-=dis(le,x);
    ans-=dis(x,ri);
}

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v,w; cin>>u>>v>>w;
        G[u].eb(v,w);
        G[v].eb(u,w);
    }
    dfs(1,0,1);
    int q; cin>>q; while(q--){
        char c; cin>>c;
        int t;
        if(c=='+')cin>>t,add(t);
        if(c=='-')cin>>t,rem(t);
        if(c=='?')cout<<ans/2<<'\n';
    }
}
