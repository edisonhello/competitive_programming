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
const ll mod=998244353;

struct node{
    node *l,*r;
    ll val,tagm,tagy;
    node():l(0),r(0),val(0),tagm(1),tagy(0){}
} *root;

#define mid ((l+r)>>1)
void push(node *now,int l,int r){
    (now->l->val*=now->tagm)%=mod;
    (now->r->val*=now->tagm)%=mod;
    (now->l->tagm*=now->tagm)%=mod;
    (now->r->tagm*=now->tagm)%=mod;
    (now->l->tagy*=now->tagm)%=mod;
    (now->r->tagy*=now->tagm)%=mod;
    now->tagm=1;
    (now->l->val+=now->tagy*(mid-l+1))%=mod;
    (now->r->val+=now->tagy*(r-mid))%=mod;
    (now->l->tagy+=now->tagy)%=mod;
    (now->r->tagy+=now->tagy)%=mod;
    now->tagy=0;
}
void pull(node *now){
    now->val=now->l->val+now->r->val;
}

void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    pull(now);
}
void mdouble(node *now,int l,int r,int ml,int mr){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->val=now->val*2%mod;
        now->tagm=now->tagm*2%mod;
        now->tagy=now->tagy*2%mod;
        return;
    }
    push(now,l,r);
    mdouble(now->l,l,mid,ml,mr);
    mdouble(now->r,mid+1,r,ml,mr);
    pull(now);
}
void madd(node *now,int l,int r,int ml,int mr){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->val=(now->val+r-l+1)%mod;
        now->tagy=(now->tagy+1)%mod;
        return;
    }
    push(now,l,r);
    madd(now->l,l,mid,ml,mr);
    madd(now->r,mid+1,r,ml,mr);
    pull(now);
}
ll query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return now->val;
    push(now,l,r);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

struct item{
    int l,r,x;
};
bool operator<(const item &a,const item &b){return a.r<b.r;}

set<item> pos[200005];

int main(){
    CPPinput;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)pos[i].insert(item{1,n,0});
    build(root=new node(),1,n);
    while(q--){
        int t; cin>>t; 
        if(t==1){
            int l,r,x; cin>>l>>r>>x;
            auto it=pos[x].lower_bound(item{0,l,0});
            int L=l;
            while(l<=r){
                item z=*it;
                it=pos[x].erase(it);
                if(z.r>r){
                    item zz=z;
                    zz.l=r+1;
                    pos[x].insert(zz);
                    z.r=r;
                }
                if(z.l<l){
                    item zz=z;
                    zz.r=l-1;
                    pos[x].insert(zz);
                    z.l=l;
                }
                if(z.x==1){
                    PDE("double",z.l,z.r);
                    mdouble(root,1,n,z.l,z.r);
                }
                else{
                    PDE("add",z.l,z.r);
                    madd(root,1,n,z.l,z.r);
                }
                l=z.r+1;
            }
            pos[x].insert(item{L,r,1});
        }
        else{
            int l,r; cin>>l>>r;
            cout<<query(root,1,n,l,r)%mod<<endl;
        }
    }
}
