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
    int mx;
    node():l(0),r(0),mx(-(1<<30)){}
} *root,pool[100000];
int pptr=-1;

int a[20005],pre[20005],dp[53][20005];

node *nnode(){
    ++pptr;
    pool[pptr].l=pool[pptr].r=0;
    pool[pptr].mx=-(1<<30);
    return &pool[pptr];
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=nnode(),l,mid);
    build(now->r=nnode(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->mx=max(now->mx,v);
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->mx=max(now->l->mx,now->r->mx);
}
int query(node *now,int l,int r,int ql,int qr){
    PDE("query",now,ql,qr);
    if(qr<l || r<ql)return -(1<<30);
    if(ql<=l&&r<=qr)return now->mx;
    return max(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    CPPinput;
    int n,k,p; cin>>n>>k>>p;
    for(int i=1;i<=n;++i)cin>>a[i],a[i]%=p;
    for(int i=1;i<=n;++i)pre[i]=(pre[i-1]+a[i])%p;
    for(int i=1;i<=n;++i)dp[0][i]=-(1<<30);
    for(int i=1;i<=k;++i){
        pptr=-1;
        build(root=nnode(),0,p-1);
        modify(root,0,p-1,0,0);
        for(int j=1;j<=n;++j){
            dp[i][j]=pre[j]+query(root,0,p-1,0,pre[j]);
            if(pre[j]!=p-1)dp[i][j]=max(dp[i][j],pre[j]+query(root,0,p-1,pre[j]+1,p-1)+p);
            modify(root,0,p-1,pre[j],-pre[j]+dp[i-1][j]);
            PDE(i,j,dp[i][j]);
        }
    }
    cout<<dp[k][n]<<endl;
}
