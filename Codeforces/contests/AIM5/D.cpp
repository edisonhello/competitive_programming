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


int main(){
    CPPinput;
    int n; cin>>n;
    ll ans=1;
    set<int> buy,mid,sell;
    while(n--){
        string s; int p; cin>>s>>p;
        if(s=="ADD"){
            if(sell.size() && p>*sell.begin())sell.insert(p);
            else if(buy.size() && p<*prev(buy.end()))buy.insert(p);
            else mid.insert(p);
        }
        else{
            if(sell.size() && p>*sell.begin())JIZZ("0");
            if(buy.size() && p<*prev(buy.end()))JIZZ("0");
            if(sell.size() && p==*sell.begin()){
                sell.erase(sell.begin());
                for(int i:mid)buy.insert(i);
                mid.clear();
            }
            else if(buy.size() && p==*prev(buy.end())){
                buy.erase(--buy.end());
                for(int i:mid)sell.insert(i);
                mid.clear();
            }
            else{
                auto it=mid.find(p);
                // assert(it!=mid.end());
                if(it==mid.end()){
                    if(DEBUG)cout<<"new! : ";
                    JIZZ("0");
                }
                for(auto zit=mid.begin();zit!=it;++zit)buy.insert(*zit);
                ++it;
                for(;it!=mid.end();++it)sell.insert(*it);
                mid.clear();
                ans*=2;
                if(ans>=mod)ans-=mod;
            }
        }
    }
    /* for(int z=0;z<mid.size();++z){
        ans<<=1;
        if(ans>=mod)ans-=mod;
    } */
    ans*=int(mid.size())+1;
    ans%=mod;
    cout<<ans<<endl;
}
