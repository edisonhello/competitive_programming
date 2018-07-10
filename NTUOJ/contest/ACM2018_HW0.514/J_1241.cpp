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

struct jizz{
    int state,ans,len;
    int lans,lest;
    int rans,rest;
    void change(){ state^=1; lest^=1; rest^=1; }
    jizz(int l):state(1),ans(1),len(l),lans(1),lest(1),rans(1),rest(1){}
};
jizz operator+(const jizz &a,const jizz &b){
    jizz rt(a.len+b.len);
    rt.ans=max(a.ans,b.ans);
    rt.lest=a.lest;
    rt.rest=b.rest;
    if(a.lans==a.len && a.rest!=b.lest)rt.lans=a.lans+b.lans;
    else rt.lans=a.lans;
    if(b.rans==b.len && b.lest!=a.rest)rt.rans=a.rans+b.rans;
    else rt.rans=b.rans;
    if(a.rest!=b.lest)rt.ans=max(rt.ans,a.rans+b.lans);
    rt.ans=max(rt.ans,max(rt.lans,rt.rans));
    return rt;
}

struct node{
    node *l,*r;
    jizz val;
    node(int l):l(0),r(0),val(l){}
} *root;

void clear(node *now){
    if(!now)return;
    clear(now->l);
    clear(now->r);
    delete now;
}

#define mid ((l+r)>>1)
void modify(node *now,int l,int r,int x){
    if(l==r){
        now->val.change();
        return;
    }
    if(!now->l)now->l=new node(mid-l+1);
    if(!now->r)now->r=new node(r-mid);
    if(x<=mid)modify(now->l,l,mid,x);
    else modify(now->r,mid+1,r,x);
    now->val=now->l->val+now->r->val;
}

int main(){
    CPPinput;
    int n,q; while(cin>>n>>q){
        clear(root); root=0;
        while(q--){
            int x; cin>>x;
            if(!root)root=new node(n);
            modify(root,1,n,x);
            cout<<root->val.ans<<'\n';
        }
    }
}
