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
    int u,v,w;
};
vector<edge> R,G,B;

vector<int> djs;
void I(int n){ for(int i=1;i<=n;++i)djs[i]=i; }
int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }
bool C(int x,int y){ return F(x)==F(y); }

int ans[111];

int main(){
    CPPinput;
    djs.resize(111,0);
    int t,k=0; cin>>t; while(t--){
        cout<<"Case #"<<(++k)<<":\n";
        memset(ans,0xff,sizeof(ans));
        int n,m; cin>>n>>m;
        I(n);
        while(m--){
            int u,v,w; char c; cin>>u>>v>>w>>c;
            if(c=='R')R.push_back({u,v,w});
            if(c=='G')G.push_back({u,v,w});
            if(c=='B')B.push_back({u,v,w});
        }
        sort(R.begin(),R.end(),[](const edge &a,const edge &b){ return a.w<b.w; });
        sort(G.begin(),G.end(),[](const edge &a,const edge &b){ return a.w<b.w; });
        sort(B.begin(),B.end(),[](const edge &a,const edge &b){ return a.w<b.w; });
        int co=0,totou=0;
        vector<edge> nowG;
        for(edge &e:G){ if(C(e.u,e.v))continue; U(e.u,e.v); co+=e.w; ++totou; nowG.push_back(e); }
        auto backup=djs;
        for(edge &e:R){ if(C(e.u,e.v))continue; U(e.u,e.v); co+=e.w; ++totou; }
        djs=backup;
        for(edge &e:B){ if(C(e.u,e.v))continue; U(e.u,e.v); co+=e.w; ++totou; }
        bool same=1;
        for(int i=2;i<=n;++i)if(!C(i-1,i))same=0;
        if(!same){ for(int i=1;i<=m;++i)cout<<-1<<'\n'; continue; }
        ans[totou]=co;

        while(nowG.size()){
            int minans=1e9,delid=-1;
            for(int i=0;i<nowG.size();++i){
                I(n);
                for(int j=0;j<nowG.size();++j){
                    if(i==j)continue;
                    
                }
            }
        }
    }
}
