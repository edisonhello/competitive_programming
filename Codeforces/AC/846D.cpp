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

/* int pre[548];

void add(int x){
    for(;x<548;x+=lowbit(x))++pre[x];
}
int query(int l,int r,int a=0){
    for(;r;r-=lowbit(r))a+=pre[r];
    for(--l;l;l-=lowbit(l))a-=pre[l];
    return a;
} */

int bit[505][505];
void add(int x,int y,int v){
    for(;x<505;x+=lowbit(x))for(int z=y;z<505;z+=lowbit(z))bit[x][z]+=v;
}
int query(int x,int y,int a=0){
    for(;x;x-=lowbit(x))for(int z=y;z;z-=lowbit(z))a+=bit[x][z];
    return a;
}

vector<pair<int,pair<int,int>>> v;
vector<int> ts;

int main(){
    CPPinput;
    int n,m,k,q; cin>>n>>m>>k>>q;
    if(q==0)JIZZ("-1\n");
    v.resize(q);
    for(auto &p:v)cin>>p.second.first>>p.second.second>>p.first;
    sort(v.begin(),v.end());
    for(auto &p:v)ts.pb(p.first);
    ts.resize(unique(ts.begin(),ts.end())-ts.begin());
    auto broke=[&](int T)->bool{
        memset(bit,0,sizeof(bit));
        for(auto &p:v){
            if(p.first>T)break;
            add(p.second.first,p.second.second,1);
        }
        for(int i=1;i<=n-k+1;++i)for(int j=1;j<=m-k+1;++j){
            if(query(i+k-1,j+k-1)-query(i+k-1,j-1)-query(i-1,j+k-1)+query(i-1,j-1)==k*k)return 1;
        }
        return 0;
    };
    int L=0,R=ts.size()-1;
    if(!broke(ts[R]))JIZZ("-1\n");
    while(R>L){
        int mid=(L+R)>>1;
        if(broke(ts[mid]))R=mid;
        else L=mid+1;
    }
    cout<<ts[L]<<endl;
}
