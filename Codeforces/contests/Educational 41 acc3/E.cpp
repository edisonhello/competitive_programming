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

int a[200005];
vector<pair<int,int>> qs[200005];

struct node{
    node *l,*r;
    int sz,pri,val;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=lz()+rz()+1;}
    node(int v=0):l(0),r(0),sz(1),pri(rand()),val(v){}
} *root;

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

void split(node *s,int val,node *&a,node *&b){
    if(!s){a=b=0; return;}
    if(s->val<=val){
        a=s;
        split(s->r,val,a->r,b);
        a->psz();
    }
    else{
        b=s;
        split(s->l,val,a,b->l);
        b->psz();
    }
}

int main(){
    srand(time(0));
    CPPinput;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll ans=0;
    multiset<int> st;
    for(int i=1;i<=n;++i)st.insert(a[i]);
    for(int i=1;i<=n;++i){
        if(a[i]<=i)continue;
        qs[i].eb(i,-1);
        qs[a[i]>n?n:a[i]].eb(i,1);
    }
    for(int i=1;i<=n;++i){
        node *z,*x;
        split(root,a[i],z,x);
        root=merge(merge(z,new node(a[i])),x);
        for(auto &p:qs[i]){
            PDE(i,p);
            node *z,*x;
            // PDE(root);
            split(root,p.first-1,z,x);
            ans+=(x?x->sz:0)*p.second;
            root=merge(z,x);
        }
    }
    cout<<ans<<endl;
}
