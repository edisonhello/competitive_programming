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

int main(){
    CPPinput;
    int t,k=0; cin>>t; while(t--){
        int n,q; cin>>n>>q;
        string s; cin>>s;
        struct node{
            node *l,*r;
            struct data{
                int t,c;
                data operator+(const data &b)const{
                    if(t==b.t)return data(t,c+b.c);
                    else return t<b.t?*this:b;
                }
                data(int t=0,int c=0):t(t),c(c){}
            } v;
            node():l(0),r(0),v(){}
        } *root=new node();
        #define mid ((l+r)>>1)
        function<void(node*,int,int)> build=[&build,&s](node *now,int l,int r){
            if(l==r){ now->v=node::data(s[l],1); }
            else build(now->l=new node(),l,mid),build(now->r=new node(),mid+1,r),now->v=now->l->v+now->r->v;
        };
        function<node::data(node*,int,int,int,int)> query=[&query](node *now,int l,int r,int ql,int qr){
            if(qr<l || r<ql)return node::data(1e9,0);
            if(ql<=l&&r<=qr)return now->v;
            return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
        };
        function<void(node*)> del=[&del](node *now){
            if(!now)return;
            del(now->l); del(now->r);
            delete now;
        };
        build(root,0,n-1);
        cout<<"Case #"<<(++k)<<":\n";
        while(q--){
            int l,r; cin>>l>>r;
            cout<<query(root,0,n-1,l-1,r-1).c<<'\n';
        }
        del(root);
    }
}
