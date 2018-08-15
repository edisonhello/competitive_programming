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

ll clr[3][1003][510];

ll par(char c){
    if(c>='0' && c<='9')return 1ll<<(c-'0');
    if(c>='a' && c<='z')return 1ll<<(c-'a'+10);
    if(c>='A' && c<='Z')return 1ll<<(c-'A'+10+26);
}

int count(ll x){
    int r=0;
    while(x)r+=x&1,x>>=1;
    return r;
}

struct Q{
    int x,y,i;
};
vector<Q> qs[255];
int ans[300005];

void sol(){
    MS(clr,0);
    int L; cin>>L;
    for(int y=1;y<=L*2-1;++y){
        int row=L+min(y-1,L*2-1-y);
        string s; cin>>s;
        for(int x=1+abs(y-L),z=0;z<row;++z,x+=2){
            clr[1][x][y]|=par(s[z]);
        }
    }
    for(int i=1;i<=250;++i)qs[i].clear();
    int q; cin>>q; for(int i=0;i<q;++i){
        int x,y,l; cin>>x>>y>>l;
        x+=(l-1)*2;
        qs[l].pb({x,y,i});
        // cout<<count(clr[l][x][y])<<'\n';
    }
    for(int i=1;i<=L;++i){
        for(Q q:qs[i]){
            ans[q.i]=count(clr[i&1][q.x][q.y]);
        }
        for(int y=1;y<=L*2-1;++y){
            int row=L+min(y-1,L*2-1-y);
            for(int x=1+abs(y-L),z=0;z<row;++z,x+=2){
                clr[(i+1)&1][x][y]=clr[i&1][x-1][y-1]|clr[i&1][x+1][y-1]
                            |clr[i&1][x-2][y]|clr[i&1][x][y]|clr[i&1][x+2][y]
                                  |clr[i&1][x-1][y+1]|clr[i&1][x+1][y+1];
            }
        }
    }
    for(int i=0;i<q;++i){
        cout<<ans[i]<<'\n';
    }
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--)sol();
}
