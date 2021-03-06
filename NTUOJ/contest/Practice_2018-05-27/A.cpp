// same as SPOJ BWHEELER
#pragma GCC optimize("Ofast")
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
const ll mod=4000037;
const ll p=643;

#define next sfjeoi
int cnt[333],next[1003],prv[1003];

int main(){
    CPPinput;
    int r; while(cin>>r,r){
        string s; cin>>s;
        int n=s.size();
        if(n==1){
            cout<<s<<endl;
            continue;
        }
        vector<pair<char,int>> in,head;
        MS(cnt,0);
        for(char c:s){
            in.emplace_back(c,++cnt[c]);
        }
        head=in;
        sort(head.begin(),head.end());
        for(int i=0;i<n;++i){
            next[i]=lower_bound(head.begin(),head.end(),in[i])-head.begin();
        }
        for(int i=0;i<n;++i)prv[next[i]]=i;
        int now=r-1;
        for(int i=0;i<n;++i){
            cout<<head[now].first;
            now=prv[now];
        }
        /* for(int i=0;i<n;++i)mat[n-1][i]=s[i];
        for(int i=0;i<n;++i)backhsh[i]=s[i];
        vector<char> ccc;
        for(char c:s)ccc.pb(c);
        sort(ccc.begin(),ccc.end());
        for(int i=0;i<n;++i)mat[0][i]=ccc[i];
        for(int i=0;i<n;++i){for(int j=0;j<n;++j)cout<<mat[i][j]; cout<<endl;} cout<<endl;
        // unordered_map<ll,char> mp;
        for(int i=0;i<n-1;++i){
            for(int j=0;j<n;++j)Que.push(backhsh[j],mat[i][j]);
            for(int j=0;j<n;++j)fronthsh[j]=(fronthsh[j]+mat[i][j]*ppp[i])%mod;
            for(int j=0;j<n;++j)mat[i+1][j]=Que.pop(fronthsh[j]);
            for(int j=0;j<n;++j)backhsh[j]=(backhsh[j]+mat[i][j]*ppp[i+1])%mod;
            for(int i=0;i<n;++i){for(int j=0;j<n;++j)cout<<mat[i][j]; cout<<endl;} cout<<endl;
        }
        for(int i=0;i<n;++i)cout<<mat[i][r-1]; */
        cout<<endl;
    }
}
