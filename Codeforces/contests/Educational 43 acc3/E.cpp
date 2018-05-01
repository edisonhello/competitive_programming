#pragma GCC optimize("no-stack-protector")
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
    int sz,pri;
    ll val,tot;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void pull(){
        sz=lz()+rz()+1;
        tot=val+(l?l->tot:0)+(r?r->tot:0);
    }
    node(ll v=0):l(0),r(0),sz(1),pri(rand()),val(v),tot(v){}
} *root,pool[600005];
int ptr=-1;

inline node *gnode(ll v){
    node *rt=&pool[++ptr];
    rt->val=rt->tot=v;
    return rt;
}
node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split(node *now,ll v,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->val<=v){
        a=now;
        split(now->r,v,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split(now->l,v,a,b->l);
        b->pull();
    }
}
void splitz(node *now,int sz,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->lz()>=sz){
        b=now;
        splitz(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        splitz(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}

ll hp[200005],dmg[200005];

void insert(ll v){
    if(v<=0)return;
    node *a,*b;
    split(root,v,a,b);
    root=merge(a,merge(gnode(v),b));
}
void erase(ll v){
    // cout<<"erase "<<v<<endl;
    if(v<=0)return;
    node *a,*b,*c,*d;
    split(root,v-1,a,d);
    // cout<<"d: "<<d->tot<<endl;
    splitz(d,1,b,c);
    
    root=merge(a,c);
}

void ptree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<now->val<<","<<now->tot;
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

ll get(int u){
    if(!root)return 0;
    u=min(u,root->sz);
    int no=root->sz-u;
    PDE(no);
    node *a,*b;
    splitz(root,no,a,b);
    // ptree(a); cout<<endl;
    // ptree(b); cout<<endl;
    ll rt=(b?b->tot:0ll);
    root=merge(a,b);
    PDE(rt);
    return rt;
}


int main(){
    srand(clock());
    CPPinput;
    int n,a,b; cin>>n>>a>>b;
    // int n=200000,a=20,b=100000;
    ll ans=0,tot=0;
    for(int i=1;i<=n;++i)cin>>hp[i]>>dmg[i],tot+=dmg[i];
    // for(int i=1;i<=n;++i)hp[i]=rand()%1000000000+1,dmg[i]=rand()%1000000000+1,tot+=dmg[i];
    // for(int i=1;i<=n;++i)PDE(i,hp[i],dmg[i]);
    ans=tot;
    for(int i=1;i<=n;++i){
        PDE(i,hp[i]-dmg[i]);
        insert(hp[i]-dmg[i]);
    }
    // ptree(root); cout<<endl;
    for(int i=1;i<=n;++i){
        erase(hp[i]-dmg[i]);
        hp[i]<<=a;
        insert(hp[i]-dmg[i]);
        // ptree(root); cout<<endl;
        ans=max(ans,tot+get(b));
        erase(hp[i]-dmg[i]);
        hp[i]>>=a;
        insert(hp[i]-dmg[i]);
        // ptree(root); cout<<endl;
    }
    cout<<ans<<endl;
}

