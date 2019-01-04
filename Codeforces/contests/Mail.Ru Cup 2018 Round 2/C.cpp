// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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


/* ll doit(ll la,ll ra,ll ta,ll lb,ll rb,ll tb){
    ll delta=min(tb-rb,ta-ra);
    la+=delta, ra+=delta, lb+=delta, rb+=delta;


    ll le=lb;
    ll ri=rb;
    ll rl=ri-(ra-la);
    PDE(ri,ra,la,tb);
    // left go rl~le -> ans is ra-la
    // else max(0, (ra-la) - (rl-st))
    PDE("if la can go to ", rl, " to ", le);
    ll mov=__gcd(ta,tb);
    // st is now at la
    // + mov at once, check can go into rl~le
    // while(le<rl)le+=tb;
    if(rl>=le)return 0;
    PDE(rl,le);
    while(rl<la)rl+=tb;
    while(le<la)le+=tb;
    while(le<rl)le+=tb;
    PDE(mov, rl,le);
    if((rl-1-la)/mov != (le-la)/mov){
        PDE("get ans ",min(ra-la,rb-lb));
        return min(ra-la,rb-lb);
    }
    PDE(le-la);
    PDE("get ans ",(ra-la)-(rl-((le-la)/mov*mov+la)));
    return max(0ll,(ra-la)-(rl-((le-la)/mov*mov+la)));
} */

int main(){
    CPPinput;
    ll la,ra,ta,lb,rb,tb; cin>>la>>ra>>ta>>lb>>rb>>tb;
    // ++ra, ++rb;
    if(rb-lb<ra-la)swap(la,lb),swap(ra,rb),swap(ta,tb);
    ll g=__gcd(ta,tb);
    ll bgo=(tb-1-rb)/g*g;
    lb+=bgo; rb+=bgo;
    ll ago=la/g*g;
    la-=ago; ra-=ago;

    PDE(ago,bgo);

    ll lgo=(lb-la)/g*g;
    ll rgo=((rb-ra-1)/g+1)*g;
    PDE(lgo,rgo);
    if(rgo/g-lgo/g>1){ cout<<ra-la+1<<endl; exit(0); }
    ll L=max(lb,la+lgo),R=min(rb,ra+lgo);
    PDE(L,R);
    ll mx=R-L+1;
       L=max(lb,la+rgo),R=min(rb,ra+rgo);
    PDE(L,R);
    mx=max(mx,R-L+1);
    mx=max(mx,0ll);
    cout<<mx<<endl;


    // cout<<max(doit(la,ra,ta,lb,rb,tb),doit(ta-ra,ta-la,ta,tb-rb,tb-lb,tb))<<endl;
    // ll goft=__gcd(ta,tb);
    // ll offset=tb-goft;
    
}
