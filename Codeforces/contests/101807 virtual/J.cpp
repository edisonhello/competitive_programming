#pragma GCC optimize("no-stack-protector")
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int dep[500005],in[500005],out[500005],inv[500005],dt;
ll d[500005];
vector<pair<pair<int,int>,int>> edge;
vector<int> G[500005];

void dfs(int now,int pa,int Dep){
    in[now]=++dt;
    dep[now]=Dep;
    for(int i:G[now]){
        int to=edge[i].first.first==now?edge[i].first.second:edge[i].first.first;
        if(to!=pa)d[to]=d[now]+edge[i].second,dfs(to,now,Dep+1);
    }
    out[now]=dt;
}

struct node{
    node *l,*r;
    ll val,tag;
    void push(){ l->val+=tag, l->tag+=tag; r->val+=tag, r->tag+=tag; tag=0; }
    node():l(0),r(0),val(0),tag(0){}
} *root,pool[500005*3];

inline node *gnode(){
    static int ptr=-1;
    return &pool[++ptr];
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->val=d[inv[l]];
        return;
    }
    build(now->l=gnode(),l,mid);
    build(now->r=gnode(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,ll v){
    if(ml<=l&&r<=mr){
        now->tag+=v;
        now->val+=v;
        return;
    }
    if(r<ml || mr<l)return;
    now->push();
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
}
ll query(node *now,int l,int r,int x){
    if(l==r)return now->val;
    now->push();
    if(x<=mid)return query(now->l,l,mid,x);
    else return query(now->r,mid+1,r,x);
}

int main(){
    int n; rit(n);
    for(int i=1,u,v,w;i<n;++i){
        rit(u,v,w);
        G[u].pb(edge.size());
        G[v].pb(edge.size());
        edge.eb(make_pair(u,v),w);
    }
    dfs(1,1,1);
    // for(int i=1;i<=n;++i)PDE(d[i],dep[i]);
    for(int i=1;i<=n;++i)inv[in[i]]=i;
    build(root=gnode(),1,n);
    int q,c,x,y; rit(q); while(q--){
        rit(c,x,y);
        if(c==1){
            ll len=query(root,1,n,in[x])+query(root,1,n,in[y]);
            PDE(query(root,1,n,in[x]),query(root,1,n,in[y]));
            if(len&1)cout<<"WE NEED BLACK PANDA"<<'\n';
            else cout<<"JAKANDA FOREVER"<<'\n';
        }
        else{
            --x;
            ll ol=edge[x].second;
            ll dl=y-ol;
            ll lw=(dep[edge[x].first.first]<dep[edge[x].first.second]?edge[x].first.second:edge[x].first.first);
            PDE(x,y,edge[x],lw,dl);
            modify(root,1,n,in[lw],out[lw],dl);
            edge[x].second=y;
        }
    }
}
