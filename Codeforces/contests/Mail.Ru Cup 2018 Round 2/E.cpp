// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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

int a[1555],pre[1555];
pair<int,int> seg[1555];
int id[1555];
bitset<1555> use;

struct node{
    node *l,*r;
    int val,sz,pri;
    node(int v=0):l(0),r(0),val(v),sz(1),pri(rand()){}
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
} *root;

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

void split(node *now,int val,node *&a,node *&b){
    if(!now){ a=b=0;return; }
    if(now->val<=val){
        a=now;
        split(now->r,val,a->r,b);
    }
    else{
        b=now;
        split(now->l,val,a,b->l);
    }
    now->pull();
}

void del(node *&now){
    if(!now)return;
    del(now->l);
    del(now->r);
    delete now;
    now=0;
}

int main(){
    CPPinput;
    int n,s,m,k; cin>>n>>s>>m>>k; // k-th in m segs
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=s;++i)cin>>seg[i].first>>seg[i].second;
    /* int all=0;
    for(int i=1;i<=s;++i)all+=seg[i].second-seg[i].first+1;
    if(all<k)exit((cout<<-1<<endl,0)); */
    int L=1,R=1e9+4;
    auto check=[&](int x)->int{
        // memset(bit,0,sizeof(bit));
        del(root);
        for(int i=1;i<=n;++i)if(a[i]<=x)root=merge(root,new node(i));
        // for(int i=1;i<=s;++i)id[i]=i;
        // sort(id+1,id+1+s,[&](const int &x,const int &y){ return pre[seg[x].second]-pre[seg[x].first-1]>pre[seg[y].second]-pre[seg[y].first-1]; });
        int sum=0;
        // for(int i=1;i<=m;++i)sum+=pre[seg[id[i]].second]-pre[seg[id[i]].first-1];
        for(int i=1;i<=m;++i){
            int mx=0,id=-1;
            for(int j=1;j<=s;++j){
                node *a,*b,*c,*d;
                split(root,seg[j].first-1,a,d);
                split(d,seg[j].second,b,c);
                if(b){
                    if(b->sz>mx){
                        mx=b->sz;
                        id=j;
                    }
                }
                root=merge(merge(a,b),c);
            }
            if(id==-1)break;
            sum+=mx;
            int j=id;
            node *a,*b,*c,*d;
            split(root,seg[j].first-1,a,d);
            split(d,seg[j].second,b,c);
            del(b);
            root=merge(a,c);
        }
        return sum;
    };
    while(L<R){
        int M=(L+R)>>1;
        if(check(M)>=k)R=M;
        else L=M+1;
    }
    PDE(L,check(L));
    if(L>1e9)L=-1;
    cout<<L<<endl;
}
