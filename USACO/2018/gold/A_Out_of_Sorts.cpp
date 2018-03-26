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

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

struct node{
    node *l,*r,*pa;
    int sz,val,pri;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    node(int v=0):l(0),r(0),pa(0),sz(1),val(v),pri(rand()){}
} *root;

void pull(node *now){
    if(!now)return;
    if(now->l)now->l->pa=now;
    if(now->r)now->r->pa=now;
    now->sz=now->lz()+now->rz()+1;
    // now->mn=min(now->mn,min(l?now->l->mn:1<<30,r?now->r->mn:1<<30));
    // now->mx=max(now->mx,max(l?now->l->mx:0,r?now->r->mx:0));
}
node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        pull(a);
        return a;
    }
    else{
        b->l=merge(a,b->l);
        pull(b);
        return b;
    }
}
#define split split_sz
void split(node *now,int sz,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        pull(b);
        return;
    }
    else{
        a=now;
        split(now->r,sz-1-now->lz(),a->r,b);
        pull(a);
        return;
    }
}

int gsz(node *now){
    node *prv=now;
    int rt=now->lz();
    while(now->pa){
        now=now->pa;
        if(now->r==prv){
            rt+=now->lz()+1;
        }
        prv=now;
    }
    return rt;
}

int rest(node *now){
    PDE(now);
    if(now->r)return rest(now->r);
    return now->val;
}
int lest(node *now){
    if(now->l)return lest(now->l);
    return now->val;
}

void ptree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

node *rec[100005];
int a[100005];
vector<pair<int,int>> vv;

int main(){
    // freopen("sort.in","r",stdin);
    // freopen("sort.out","w",stdout);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        vv.emplace_back(a[i],i);
    }
    sort(vv.begin(),vv.end());
    for(int i=1;i<=n;++i){
        a[i]=lower_bound(vv.begin(),vv.end(),pair<int,int>{a[i],i})-vv.begin()+1;
    }
    for(int i=1;i<=n;++i){
        int t=a[i];
        rec[t]=new node(t);
        root=merge(root,rec[t]);
    }
    for(int i=1;i<=n;++i)PDE(i,a[i]);
    int ans=0,l=1,r=n;
    while(root){
        // ptree(root);cout<<endl;
        ++ans;
        PDE("loop");
        PDE(root->sz);
        while(root && rest(root)==r){
            PDE(root->sz);
            node *a,*b;
            split_sz(root,root->sz-1,a,b);
            root=a;
            --r;
        }
        if(!root)break;
        int gz=gsz(rec[r]);
        PDE(gz);
        node *a,*b,*c,*d;
        split_sz(root,gz,a,d);
        split_sz(d,1,b,c);
        PDE(a,b,c);
        root=merge(a,c); --r;
        PDE(root->sz);
        while(root && rest(root)==r){
            node *a,*b;
            split_sz(root,root->sz-1,a,b);
            root=a;
            --r;
        }
        if(!root)break;
        PDE("half: ",root->sz);
        // ptree(root);cout<<endl;
        while(root && lest(root)==l){
            node *a,*b;
            split_sz(root,1,a,b);
            root=b;
            ++l;
        }
        if(!root)break;
        gz=gsz(rec[l]);
        PDE(gz);
        split_sz(root,gz,a,d);
        split_sz(d,1,b,c);
        root=merge(a,c); ++l;
        while(root && lest(root)==l){
            node *a,*b;
            split_sz(root,1,a,b);
            root=b;
            ++l;
        }
    }
    cout<<ans<<endl;
}
