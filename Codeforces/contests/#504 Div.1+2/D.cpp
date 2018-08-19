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
#include<random>
#include<thread>

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

struct node{
    node *l,*r;
    int mn;
    node():l(0),r(0),mn(1e9){};
} *root;

int a[200005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->mn=a[l];
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->mn=min(now->l->mn,now->r->mn);
}
int query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 1e9;
    if(ql<=l&&r<=qr)return now->mn;
    return min(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int l[200005],r[200005];

int main(){
    CPPinput;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    bool found=0;
    for(int i=1;i<=n;++i)if(a[i]==q)found=1;
    if(!found){
        int empty=0;
        for(int i=1;i<=n;++i)if(a[i]==0)empty=i;
        if(empty==0){ NO; exit(0); }
        a[empty]=q;
    }

    for(int i=2;i<=n;++i)if(a[i]==0)a[i]=a[i-1];
    for(int i=n-1;i>=1;--i)if(a[i]==0)a[i]=a[i+1];
    if(a[1]==0)for(int i=1;i<=n;++i)a[i]=q;
    build(root=new node(),1,n);
    for(int i=1;i<=q;++i)l[i]=n+1;
    for(int i=1;i<=n;++i)r[a[i]]=i;
    for(int i=n;i>=1;--i)l[a[i]]=i;
    for(int i=2;i<=q;++i){
        if(l[i]>r[i])continue;
        if(query(root,1,n,l[i],r[i])<i){ NO; exit(0); }
    }
    YES;
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
}
