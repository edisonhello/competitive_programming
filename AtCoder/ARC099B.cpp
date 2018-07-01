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

ld density[10000007];
void test(){
    for(int i=1;i<10000007;++i){
        int x=i;
        int sum=0;
        while(x)sum+=x%10,x/=10;
        density[i]=(ld)i/sum;
        if(i<100)PDE(i,density[i]);
        // PDE(i,(ld)i/sum);
    }
    for(int i=1;i<10000007;++i){
        bool ok=1;
        for(int j=i+1;j<10000007;++j){
            if(density[j]<density[i]){ ok=0; break; }
        }
        if(ok)PDE(i);
    }
    exit(0);
}

int main(){
    CPPinput;
    // test();
    string s;
    vector<pair<ll,ld>> ans;
    while(s.size()<15){
        for(int i=1;i<=999;++i){
            string pre;
            int x=i;
            while(x)pre=""+string(1,char(x%10+'0'))+pre,x/=10;
            string ns=pre+s;
            if(ns.size()>15u)continue;
            PDE(ns);
            SS ss(ns);
            ll val;
            ss>>val;
            int sum=0;
            for(char c:ns)sum+=c-'0';
            ans.eb(val,(ld)val/sum);
        }
        s+='9';
    }
    sort(ans.begin(),ans.end());
    PDE(ans,ans.size());
    int k; cin>>k;
    for(int i=0;i<k;++i)cout<<ans[i]<<'\n';
}
