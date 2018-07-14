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

int rs[100005],le[6],c[64],cc[64];

int main(){
    CPPinput;
    int n;
    { string s; cin>>s; for(char c:s)++le[c-'a']; n=s.size(); }
    for(int i=0;i<n;++i)rs[i]=63;
    { int m; cin>>m; while(m--){
        int p; cin>>p; --p;
        int x=0;
        string s; cin>>s; for(char c:s)x^=1<<(c-'a');
        rs[p]=x;
    } }
    for(int i=0;i<n;++i)++c[rs[i]];
    for(int i=0;i<n;++i)PDE(i,rs[i]);
    for(int i=0;i<6;++i)PDE(i,le[i]);
    string ans;
    for(int i=0;i<n;++i){
        bool put=0;
        --c[rs[i]];
        for(int z=0;z<6;++z){
            if(!(rs[i]&(1<<z)))continue;
            if(!le[z])continue;
            if(put)continue;
            --le[z];
            if([&]()->bool{
                for(int i=0;i<64;++i)cc[i]=c[i];
                for(int i=0;i<64;++i)PDE(z,i,cc[i]);
                for(int z=63;z>=0;--z)for(int i=0;i<z;++i)if((z|i)==z)cc[z]+=cc[i];
                for(int i=0;i<64;++i)PDE(z,i,cc[i]);
                for(int z=0;z<64;++z){
                    int c=0;
                    for(int i=0;i<6;++i)if(z&(1<<i))c+=le[i];
                    if(c<cc[z])return 0;
                }
                return 1;
            }()){
                PDE("in");
                ans+=char(z+'a');
                put=1;
                break;
            }
            ++le[z];
        }
        if(!put)JIZZ("Impossible");
    }
    cout<<ans;
}
