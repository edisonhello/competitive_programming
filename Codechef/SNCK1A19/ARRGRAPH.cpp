// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC target("sse4.2,arch=core-avx2,tune=core-avx2")
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

int djs[55];
int sz[55];
int F(int x){ return djs[x]==x?x:djs[x]=F(djs[x]); }
void U(int x,int y){ djs[F(x)]=F(y); }
int a[55];

int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

int main(){
    CPPinput;
    int t; cin>>t; while(t--){
        int n; cin>>n; 
        for(int i=1;i<=n;++i)djs[i]=i;
        for(int i=1;i<=n;++i)sz[i]=0;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)for(int j=1;j<i;++j){
            if(__gcd(a[i],a[j])==1)U(i,j);
        }
        set<int> st;
        for(int i=1;i<=n;++i)st.insert(F(i));
        if(st.size()==1u){
            cout<<0<<'\n';
            for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
            continue;
        }
        for(int i=1;i<=n;++i)sz[F(i)]++;
        int bigg=1;
        for(int i=2;i<=n;++i)if(sz[F(i)]>sz[F(bigg)])bigg=i;
        set<int> plist;
        for(int i=1;i<=n;++i)if(F(i)==F(bigg)){
            for(int z=0;z<15;++z)if(a[i]%p[z]==0)plist.insert(p[z]);
        }
        int lone=-1;
        for(int i=0;i<15;++i)if(plist.find(p[i])==plist.end())lone=p[i];
        int another=0;
        for(int i=1;i<=n;++i)if(F(i)!=F(bigg))another=i;
        a[another]=lone;
        cout<<1<<'\n';
        for(int i=1;i<=n;++i)cout<<a[i]<<" \n"[i==n];
    }
}
