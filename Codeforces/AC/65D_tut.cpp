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

#define ei else if
set<vector<int>> st[2];

int main(){
    CPPinput;
    int n; cin>>n;
    string s; cin>>s;
    for(char &c:s){
        if(c=='?')c=10;
        ei(c=='G')c=0;
        ei(c=='H')c=1;
        ei(c=='R')c=2;
        ei(c=='S')c=3;
        else assert(0);
    }
    vint v(4,0);
    st[1].insert(v);
    for(int i=0;i<n;++i){
        st[i&1].clear();
        if(s[i]==10){
            for(auto v:st[(i&1)^1]){
                int mn=*min_element(v.begin(),v.end());
                for(int z=0;z<4;++z){
                    if(v[z]==mn){
                        ++v[z];
                        st[i&1].insert(v);
                        --v[z];
                    }
                }
            }
        }
        else{
            for(auto v:st[(i&1)^1]){
                ++v[s[i]];
                st[i&1].insert(v);
            }
        }
    }
    set<int> ok;
    for(auto v:st[(n-1)&1]){
        int mn=*min_element(v.begin(),v.end());
        for(int z=0;z<4;++z){
            if(v[z]==mn)ok.insert(z);
        }
    }
    for(int i:ok){
        if(i==0)cout<<"Gryffindor"<<endl;
        ei(i==1)cout<<"Hufflepuff"<<endl;
        ei(i==2)cout<<"Ravenclaw"<<endl;
        ei(i==3)cout<<"Slytherin"<<endl;
        else assert(0);
    }
}
