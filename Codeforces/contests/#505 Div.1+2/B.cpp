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

vector<ll> tester;
vector<int> p;
bitset<30000> _p;

void init(){
    for(int i=2;i<30000;++i){
        if(_p[i])continue;
        p.push_back(i);
        for(int j=i*i;j<30000;j+=i)_p[j]=1;
    }
}

ll gcd(ll a,ll b){
    if(a<b)swap(a,b);
    while(b){
        a%=b;
        swap(a,b);
    } return a;
}

ll meow(ll b,ll n,ll m,ll a=0){
    while(n){
        if(n&1)a=(a+b),a>=m?a-=m:0;
        b=(b+b),b>=m?b-=m:0; n>>=1;
    } return a;
}

ll pw(ll b,ll n,ll m,ll a=1){
    while(n){
        if(n&1)a=meow(a,b,m);
        b=meow(b,b,m); n>>=1;
    } return a;
}

inline bool isprime(ll x){
    ll s=x-1,t=0;
    while(s%2==0)s/=2,++t;
    for(int i=0;i<tester.size();++i){
        ll test=tester[i]%x;
        if(test==0)continue;
        ll a=pw(test,s,x);
        if(a==1 || a==x-1)continue;
        for(int _=1;_<t;++_){
            a=meow(a,a,x);
            if(a==x-1)break;
        }
        if(a==x-1)continue;
        return 0;
    }
    return 1;
}

ll offset;
inline ll f(ll xx,ll x){return (meow(xx,xx,x)+offset)%x;}
inline ll ff(ll xx,ll x){return f(f(xx,x),x);}
ll rho(ll x,ll _offset=2){
    // cout<<"minprime "<<x<<endl;
    offset=_offset;
    if(x%2==0)return 2;
    if(isprime(x))return x;
    ll g;
    register ll a=2,b=2;
    // cout<<"start from "<<a<<" , offset: "<<offset<<endl;
    a=f(a,x),b=ff(b,x);
    for(;;a=f(a,x),b=ff(b,x)){
        // cout<<"a="<<a<<" , b="<<b<<endl;
        if((g=gcd(abs(a-b),x))!=1){
            // if(g==x)exit(7122);
            return g;
            // while(x%g==0)x/=g;
            // cout<<x<<" "<<g<<endl;
        }
    }
}

ll bf(ll x){
    for(int i=0;i<p.size() && p[i]*p[i]<=x;++i){
        if(x%p[i]==0)return p[i];
    }
    return x;
}

ll minprime(ll x,ll i=1){
    if(x<=900000000)return bf(x);
    if(isprime(x))return x;
    ll d=x;
    while(d==x)d=rho(x,++i);
    return min(minprime(d,i),minprime(x/d,i));
}

void _init(){
    init();
    tester.push_back(2);
    tester.push_back(325);
    tester.push_back(9375);
    tester.push_back(28178);
    tester.push_back(450775);
    tester.push_back(9780504);
    tester.push_back(1795265022);
    // ll ptr=18014398509481920ll;
}

ll a[200000];

int main(){
    CPPinput;
    _init();
    int n; cin>>n;
    for(int i=0;i<n;++i){
        ll x,y; cin>>x>>y;
        a[i]=x*y;
    }
    ll g=0;
    for(int i=0;i<n;++i)g=__gcd(g,a[i]);
    if(g==1)JIZZ("-1");
    if(isprime(g))exit((cout<<g<<endl,0));
    for(int i:p)if(g%i==0)exit((cout<<i<<endl,0));
    cout<<minprime(g)<<endl;
}
