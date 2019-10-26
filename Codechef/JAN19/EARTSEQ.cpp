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

bitset<1000000> np;
vector<int> sieve(int n){
    vector<int> p;
    for(int i=2;i<=n;++i){
        if(np[i])continue;
        p.push_back(i);
        for(auto j=1ll*i*i;j<=n;j+=i){
            np[j]=1;
        }
    }
    return p;
}

void check(const vector<int> &v){
    int n=v.size();
    for(int i=0;i<n;++i){
        assert(__gcd(v[i],v[(i+1)%n])!=1);
        assert(__gcd(v[i],__gcd(v[(i+1)%n],v[(i+2)%n]))==1);
    }
}

int main(){
    vector<int> p=sieve(320000);
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    p.erase(p.begin());
    CPPinput;
    PDE(p,p.size());
    int t; cin>>t; while(t--){
        int n; cin>>n;
        vector<int> v(n,0);
        if(n&1){
            for(int i=0;i<n-3;i+=2){
                v[i]=v[i+1]=p[i>>1];
                if((i>>1)&1){
                    v[i]*=2;
                    v[i+1]*=3;
                }
                else{
                    v[i]*=3;
                    v[i+1]*=2;
                }
            }
            v.back()=15;
            v[n-2]=5*7;
            v[n-3]=7;
            if(v[(n-4+n)%n]%2==0)v[n-3]*=2; else v[n-3]*=3;
        }
        else{
            for(int i=0;i<n-4;i+=2){
                v[i]=v[i+1]=p[i>>1];
                if((i>>1)&1){
                    v[i]*=2;
                    v[i+1]*=3;
                }
                else{
                    v[i]*=3;
                    v[i+1]*=2;
                }
            }
            v.back()=15;
            v[n-2]=5*7;
            v[n-3]=7*11;
            v[n-4]=11;
            if(v[(n-5+n)%n]%2==0)v[n-4]*=2; else v[n-4]*=3;
        }
        for(int i:v)cout<<i<<" "; cout<<endl;
        check(v);
    }
}
