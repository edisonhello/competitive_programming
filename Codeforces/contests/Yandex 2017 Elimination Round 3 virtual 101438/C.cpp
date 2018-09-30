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
const ll mod1=1e9+7,mod2=1e9+123;

pair<ll,ll> hsh[2666],pp[2666];
ll a[2666];

pair<ll,ll> operator+(const pair<ll,ll> &a,const pair<ll,ll> &b){ return make_pair(a.first+b.first,a.second+b.second); }
pair<ll,ll> operator-(const pair<ll,ll> &a,const pair<ll,ll> &b){ return make_pair(a.first-b.first,a.second-b.second); }
pair<ll,ll> operator*(const pair<ll,ll> &a,const pair<ll,ll> &b){ return make_pair(a.first*b.first,a.second*b.second); }
pair<ll,ll> operator/(const pair<ll,ll> &a,const pair<ll,ll> &b){ return make_pair(a.first/b.first,a.second/b.second); }
pair<ll,ll> operator%(const pair<ll,ll> &a,const pair<ll,ll> &b){ return make_pair(a.first%b.first,a.second%b.second); }

int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    pp[0]=make_pair(1,1);
    for(int i=1;i<=n;++i)pp[i]=pp[i-1]*make_pair(47017ll,131ll)%make_pair(mod1,mod2);
    for(int i=1;i<=n;++i)hsh[i]=(hsh[i-1]+make_pair(a[i]+mod1,a[i]+mod2)*pp[i])%make_pair(mod1,mod2);
    if([&](){ for(int i=2;i<=n;++i)if(a[i]!=a[i-1])return 0; return 1; }())JIZZ("0\n");
    auto gethh=[&](int l,int r)->pair<ll,ll>{ return (hsh[r]-hsh[l-1]+make_pair(mod1,mod2))*pp[n-r]%make_pair(mod1,mod2); };
    for(int k=1;k<=n;++k){
        map<pair<ll,ll>,int> mp;
        bool ok=1;
        for(int i=k+1;i<=n;++i){
            auto hh=gethh(i-k,i-1);
            PDE(i,hh,a[i]);
            auto it=mp.find(hh);
            if(it==mp.end())mp[hh]=a[i];
            else if(it->second!=a[i]){ ok=0; break; }
        }
        if(ok){ cout<<k<<endl; exit(0); }
    }
}
