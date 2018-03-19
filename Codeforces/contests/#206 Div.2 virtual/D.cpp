// #pragma GCC optimize("no-stack-protector")
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
#define pll pair<ll,ll>
#define vint vector<int>
#define vll vector<ll>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

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
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int n;
string mp[22];
pair<int,int> dp[22][22];
bitset<22> v[22];

pair<int,int> go(int x,int y){
    if(v[x][y])return dp[x][y];
    v[x][y]=1;
    pair<int,int> rt={0,0};
    int player=(x+y)&1;
    if(player==0){
        bool up=0;
        if(x+1<n){
            auto meow=go(x+1,y);
            rt=meow;
            up=1;
        }
        if(y+1<n){
            auto meow=go(x,y+1);
            if(meow.second-meow.first>rt.second-rt.first || !up)rt=meow;
        }
    }
    else{
        bool up=0;
        if(x+1<n){
            auto meow=go(x+1,y);
            rt=meow;
            up=1;
        }
        if(y+1<n){
            auto meow=go(x,y+1);
            if(meow.second-meow.first<rt.second-rt.first || !up)rt=meow;
        }
    }
    if(mp[x][y]=='a')++rt.first;
    else if(mp[x][y]=='b')++rt.second;
    return dp[x][y]=rt;
}

int main(){
    CPPinput;
    cin>>n;
    for(int i=0;i<n;++i)cin>>mp[i];
    auto ans=go(0,0);
    if(ans.first>ans.second)cout<<"FIRST"<<endl;
    else if(ans.first<ans.second)cout<<"SECOND"<<endl;
    else cout<<"DRAW"<<endl;
}
// fake solve
