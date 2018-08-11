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

string s[2005];
map<int,int> rec[505][2005];
pii st[13][2005];

pii Q(int l,int r){
    PDE(l,r);
    if(l==r){ PDE(st[0][l]); return st[0][l]; }
    int dd=r-l+1;
    PDE(dd);
    int z=0; while(dd)dd>>=1,++z; --z;
    PDE(z);
    PDE(min(st[z][l],st[z][r-(1<<z)+1]));
    return min(st[z][l],st[z][r-(1<<z)+1]);
}

int go(int i,int l,int r){
    if(l>r)return 0;
    if(l==r && i)return 0;
    PDE("go",i,l,r);
    if(i==0)return 0;
    if(i>r-l+1)return 0;
    if(r==l+1 && i>=2)return Q(l+1,r).first;
    if(r==l+1)return 0;
    auto it=rec[i][l].find(r);
    if(it!=rec[i][l].end())return it->second;
    auto p=Q(l+1,r);
    // int mx=max(go(i,l+1,r),go(i,l,r-1));
    int mx=0;
    PDE(i,l,r,mx);
    // --i;
    for(int lz=0;lz<=i;++lz){
        mx=max(mx,lz*(i-lz)*p.first+go(lz,l,p.second-1)+go(i-lz,p.second,r));
        PDE(i,l,r,lz,mx);
    }
    PDE("og",i,l,r,mx);
    return rec[i][l][r]=mx;
}

int meow(string a,string b){
    int z=min(a.size(),b.size());
    for(int i=0;i<z;++i)if(a[i]!=b[i])return i;
    return z;
}

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>s[i];
    sort(s,s+n);
    for(int i=1;i<n;++i)st[0][i]=pii(meow(s[i-1],s[i]),i);
    for(int z=1;z<12;++z){
        for(int j=1;j<n;++j){
            st[z][j]=min(st[z-1][j],st[z-1][j+(1<<(z-1))]);
        }
    }
    for(int i=1;i<n;++i)PDE(st[0][i]);
    PDE(st[1][2]);
    cout<<go(k,0,n-1)<<endl;
}
