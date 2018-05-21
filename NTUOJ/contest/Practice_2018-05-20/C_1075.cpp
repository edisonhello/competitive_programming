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

int n,m,a[1004][1004];
pair<int,int> djs[1004][1004];
vector<pair<int,int>> ev[1000006];
bitset<1004> app[1004];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int ans[1000006];
vector<int> Q[1000006];
int nans;

pair<int,int> F(int x,int y){
    if(djs[x][y]==make_pair(x,y))return make_pair(x,y);
    return djs[x][y]=F(djs[x][y].first,djs[x][y].second);
}

bool U(int x1,int y1,int x2,int y2){
    tie(x1,y1)=F(x1,y1);
    tie(x2,y2)=F(x2,y2);
    if(tie(x1,y1)==tie(x2,y2))return 0;
    djs[x1][y1]=make_pair(x2,y2);
    return 1;
}

void addland(pair<int,int> &p){
    ++nans;
    int x=p.first,y=p.second;
    app[x][y]=1;
    for(int d=0;d<4;++d){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx>=0 && nx<n && ny>=0 && ny<m); else continue;
        if(app[nx][ny]){
            if(U(x,y,nx,ny))--nans;
        }
    }
}

void addland(vector<pair<int,int>> &pos){
    for(auto p:pos)addland(p);
}

int ganz(){
    return nans;
}

int main(){
    CPPinput;
    int ts; cin>>ts; while(ts--){
        for(int i=0;i<1000006;++i)ev[i].clear();
        for(int i=0;i<1000006;++i)Q[i].clear();
        for(int i=0;i<1004;++i)app[i].reset();
        cin>>n>>m;
        nans=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
                ev[a[i][j]].emplace_back(i,j);
                djs[i][j]=pair<int,int>(i,j);
            }
        }
        int q; cin>>q; 
        for(int i=0;i<q;++i){
            int t; cin>>t;
            Q[t].push_back(i);
        }
        for(int i=1000000;i>=0;--i){
            addland(ev[i+1]);
            for(int z:Q[i])ans[z]=ganz();
        }
        for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
    }
}
