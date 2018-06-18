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

int x[2][4],y[2][4];
set<pair<int,int>> pt;

int main(){
    CPPinput;
    for(int i=0;i<2;++i){
        for(int j=0;j<4;++j){
            cin>>x[i][j]>>y[i][j];
        }
    }
    int xmx=-111,xmn=111,ymx=-111,ymn=111;
    for(int i=0;i<4;++i){
        xmx=max(xmx,x[0][i]);
        xmn=min(xmn,x[0][i]);
        ymx=max(ymx,y[0][i]);
        ymn=min(ymn,y[0][i]);
    }
    for(int i=xmn;i<=xmx;++i){
        for(int j=ymn;j<=ymx;++j){
            pt.insert(make_pair(i,j));
        }
    }
    int xm=(x[1][0]+x[1][1]+x[1][2]+x[1][3])/4;
    int ym=(y[1][0]+y[1][1]+y[1][2]+y[1][3])/4;
    int d=abs(xm-x[1][0])+abs(xm-x[1][1]);
    for(int i=-100;i<=100;++i){
        for(int j=-100;j<=100;++j){
            if(abs(i-xm)+abs(j-ym)>d)continue;
            if(pt.find(make_pair(i,j))!=pt.end()){
                Yes;
                return 0;
            }
        }
    }
    No;
}
