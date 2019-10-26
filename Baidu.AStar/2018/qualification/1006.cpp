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
    int u,v,w; char c;
};
vector<edge> RG,BG;

vector<int> djs;
void I(int n){ for(int i=1;i<=n;++i)djs[i]=i; }
int F(int x){ return x==djs[x]?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }
bool C(int x,int y){ return F(x)==F(y); }

int ans[1111];

int main(){
    CPPinput;
    djs.resize(1111,0);
    int t,k=0; cin>>t; while(t--){
        cout<<"Case #"<<(++k)<<":\n";
        memset(ans,0x3f,sizeof(ans));
        RG.clear(), BG.clear();
        int n,m; cin>>n>>m;
        for(int i=1;i<=m;++i){
            int u,v,w; char c; cin>>u>>v>>w>>c;
            if(c=='R')RG.push_back({u,v,w,c});
            if(c=='B')BG.push_back({u,v,w,c});
            if(c=='G')RG.push_back({u,v,w,c});
            if(c=='G')BG.push_back({u,v,w,c});
        }
        sort(RG.begin(),RG.end(),[](const edge &a,const edge &b){ return a.w<b.w; });
        sort(BG.begin(),BG.end(),[](const edge &a,const edge &b){ return a.w<b.w; });
        
        { I(n); vector<int> trash; int co=0;
        for(edge &e:RG)if(!C(e.u,e.v))U(e.u,e.v),co+=e.w; else trash.push_back(e.w);
        for(edge &e:BG)if(e.c=='B')trash.push_back(e.w); sort(trash.begin(),trash.end());
        PDE(trash);
        if([&](){ for(int i=2;i<=n;++i)if(!C(i-1,i))return 0; return 1; }()){ ans[n-1]=min(ans[n-1],co);
            for(int z=0;z<trash.size();++z)co+=trash[z],ans[n+z]=min(ans[n+z],co);
        } }
        { I(n); vector<int> trash; int co=0;
        for(edge &e:BG)if(!C(e.u,e.v))U(e.u,e.v),co+=e.w; else trash.push_back(e.w);
        for(edge &e:RG)if(e.c=='R')trash.push_back(e.w); sort(trash.begin(),trash.end());
        if([&](){ for(int i=2;i<=n;++i)if(!C(i-1,i))return 0; return 1; }()){ ans[n-1]=min(ans[n-1],co);
            for(int z=0;z<trash.size();++z)co+=trash[z],ans[n+z]=min(ans[n+z],co);
        } }
        for(int i=1;i<=m;++i)cout<<(ans[i]>1e9?-1:ans[i])<<'\n';
    }
}
