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

struct node{
    node *l,*r;
    long long val;
    int sz,pri;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void psz(){ sz=lz()+rz()+1; }
    node(long long v):l(0),r(0),val(v),sz(1),pri(rand()){}
} *root;

void split_val(node *now,long long val,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->val<=val){
        a=now;
        split_val(now->r,val,a->r,b);
        a->psz();
    }
    else{
        b=now;
        split_val(now->l,val,a,b->l);
        b->psz();
    }
}
node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}

int main(){
    CPPinput;
    int n; long long k; cin>>n>>k;
    long long pre=0,ans=0;
    for(int i=1;i<=n;++i){
        long long a; cin>>a;
        // if(a>=k)++ans;
        node *l,*r; split_val(root,pre-k*i+k,l,r);
        root=merge(l,merge(new node(pre-k*i+k),r));

        pre+=a;
        split_val(root,pre-k*i,l,r);
        ans+=(l?l->sz:0);
        root=merge(l,r);
        PDE(ans);
    }
    cout<<ans<<endl;
}
