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

int main(){
    CPPinput;
    srand(clock());
    int l,r; cin>>l>>r;
    auto inr=[l,r](int x)->bool{ return l<=x && x<=r; };
    if(inr(3))JIZZ("3\n1 2 3\n");
    if(inr(6))JIZZ("6\n1 2 4 8 16 32\n");
    if(inr(7))JIZZ("7\n1 2 4 8 16 32 64\n");
    for(int i=l;i<=r;++i){
        if((i&3)==2 || (i&3)==3){
            int n=i;
            cout<<n<<endl;
            while(n--)cout<<(rand()%1000000000+1)<<" \n"[n==0];
            exit(0);
            /* while(1){
                vector<int> v;
                while(v.size()<n)v.pb(rand()%100000000);
                vector<int> vv;
                for(int i=0;i<v.size();++i)for(int j=i+1;j<v.size();++j){
                    vv.pb(v[i]+v[j]);
                }
                sort(vv.begin(),vv.end());
                int x=vv[vv.size()>>1];
                int c=0;
                for(int i:vv)if(i==x)++c;
                if(c==1){
                    cout<<n<<endl;
                    for(int i:v)cout<<i<<" ";
                    cout<<endl;
                    exit(0);
                }
                else JIZZ("failed");
            } */
        }
    }
    /* vector<int> v;
    while(v.size()<1002u)v.pb(rand()%100000000);
    vector<int> vv;
    for(int i=0;i<v.size();++i)for(int j=i+1;j<v.size();++j){
        vv.pb(v[i]+v[j]);
    }
    sort(vv.begin(),vv.end());
    int x=vv[vv.size()>>1];
    int c=0;
    for(int i:vv)if(i==x)++c;
    PDE(x,c); */
}
