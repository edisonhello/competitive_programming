// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

struct value{
    double act;
    int nz;
    value(double v1,int v2):act(v1),nz(v2){}
    value(long long v):act(v),nz((v%mod+mod)%mod){}
};
bool operator<(const value &a,const value &b){ return a.act<b.act; }
bool operator>(const value &a,const value &b){ return a.act>b.act; }
value operator+(const value &a,const value &b){ return value(a.act+b.act,a.nz+b.nz>=mod?a.nz+b.nz-mod:a.nz+b.nz); }
value operator-(const value &a,const value &b){ return value(a.act-b.act,a.nz-b.nz<0?a.nz-b.nz+mod:a.nz-b.nz); }
value operator*(const value &a,const value &b){ return value(a.act*b.act,1ll*a.nz*b.nz%mod); }
ostream& operator<<(ostream &o,const value &v){ o<<"("<<v.act<<", "<<v.nz<<")"; return o; }

struct func{
    value a,b; // ax+b
    func(value a=0,value b=0):a(a),b(b){}
    value get(value x){ return a*x+b; }
};
func operator+(const func &a,const func &b){ return func(a.a+b.a,a.b+b.b); }
func operator-(const func &a,const func &b){ return func(a.a-b.a,a.b-b.b); }
ostream& operator<<(ostream &o,const func &f){ o<<f.a<<"x + "<<f.b; return o; }

int pos[200005],w[200005];
func pre[200005],suf[200005];
func lipre[200005],lisuf[200005];

int main(){
    CPPinput;
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>pos[i];
    for(int i=1;i<=n;++i)cin>>w[i];
    for(int i=1;i<=n;++i){
        func prefunc(value(w[i]),value(-1ll*w[i]*pos[i]));
        func suffunc(value(-w[i]),value(1ll*w[i]*pos[i]));
        for(int x=i;x<200005;x+=lowbit(x))pre[x]=pre[x]+prefunc;
        for(int x=i;x;x-=lowbit(x))suf[x]=suf[x]+suffunc;
        func liprefunc(value(w[i]),value(-1ll*w[i]*i));
        func lisuffunc(value(-w[i]),value(1ll*w[i]*i));
        for(int x=i;x<200005;x+=lowbit(x))lipre[x]=lipre[x]+liprefunc;
        for(int x=i;x;x-=lowbit(x))lisuf[x]=lisuf[x]+lisuffunc;
    }
    while(q--){
        int x,y; cin>>x>>y;
        if(x<0){
            x*=-1;
            #define nw y
            func prechafunc(value(nw-w[x]),value(-1ll*(nw-w[x])*pos[x]));
            // func prefunc(value(w[x]),value(-1ll*w[x]*pos[x]));
            func sufchafunc(value(-nw+w[x]),value(1ll*(nw-w[x])*pos[x]));
            // func suffunc(value(-w[x]),value(1ll*w[x]*pos[x]));
            for(int xx=x;xx<200005;xx+=lowbit(xx))pre[xx]=pre[xx]+prechafunc;
            // for(int xx=x;xx<200005;xx+=lowbit(xx))pre[xx]=pre[xx]-prefunc;
            for(int xx=x;xx;xx-=lowbit(xx))suf[xx]=suf[xx]+sufchafunc;
            // for(int xx=x;xx;xx-=lowbit(xx))suf[xx]=suf[xx]-suffunc;
            func liprechafunc(value(nw-w[x]),value(-1ll*(nw-w[x])*x));
            // func liprefunc(value(w[x]),value(-1ll*w[x]*x));
            func lisufchafunc(value(-nw+w[x]),value(1ll*(nw-w[x])*x));
            // func lisuffunc(value(-w[x]),value(1ll*w[x]*x));
            for(int xx=x;xx<200005;xx+=lowbit(xx))lipre[xx]=lipre[xx]+liprechafunc;
            // for(int xx=x;xx<200005;xx+=lowbit(xx))lipre[xx]=lipre[xx]-liprefunc;
            for(int xx=x;xx;xx-=lowbit(xx))lisuf[xx]=lisuf[xx]+lisufchafunc;
            // for(int xx=x;xx;xx-=lowbit(xx))lisuf[xx]=lisuf[xx]-lisuffunc;
            w[x]=nw;
            /* prefunc=func(value(w[x]),value(-1ll*w[x]*pos[x]));
            suffunc=func(value(-w[x]),value(1ll*w[x]*pos[x]));
            for(int xx=x;xx<200005;xx+=lowbit(xx))pre[xx]=pre[xx]+prefunc;
            for(int xx=x;xx;xx-=lowbit(xx))suf[xx]=suf[xx]+suffunc;
            liprefunc=func(value(w[x]),value(-1ll*w[x]*x));
            lisuffunc=func(value(-w[x]),value(1ll*w[x]*x));
            for(int xx=x;xx<200005;xx+=lowbit(xx))lipre[xx]=lipre[xx]+liprefunc;
            for(int xx=x;xx;xx-=lowbit(xx))lisuf[xx]=lisuf[xx]+lisuffunc; */
            #undef nw
        }
        else{
            #define l x
            #define r y
            int L=l,R=r;
            auto getfunc=[&](int mid)->func{
                func f;
                for(int xx=mid-1;xx;xx-=lowbit(xx))f=f+pre[xx];
                for(int xx=l-1;xx;xx-=lowbit(xx))f=f-pre[xx];
                for(int xx=mid+1;xx<200005;xx+=lowbit(xx))f=f+suf[xx];
                for(int xx=r+1;xx<200005;xx+=lowbit(xx))f=f-suf[xx];
                PDE("getfunc",mid,f);
                return f;
            };
            auto getlifunc=[&](int mid)->func{
                func f;
                for(int xx=mid-1;xx;xx-=lowbit(xx))f=f+lipre[xx];
                for(int xx=l-1;xx;xx-=lowbit(xx))f=f-lipre[xx];
                for(int xx=mid+1;xx<200005;xx+=lowbit(xx))f=f+lisuf[xx];
                for(int xx=r+1;xx<200005;xx+=lowbit(xx))f=f-lisuf[xx];
                PDE("getlifunc",mid,f);
                return f;
            };
            value ans(0); ans.act=1e30;
            while(R-L>2){
                int dis=(R-L)/3;
                int M1=L+dis,M2=R-dis;
                value ans1=getfunc(M1).get(value(pos[M1]))-getlifunc(M1).get(value(M1)),ans2=getfunc(M2).get(value(pos[M2]))-getlifunc(M2).get(value(M2));
                PDE(M1,ans1,M2,ans2);
                ans=min(ans,min(ans1,ans2));
                if(ans1<ans2)R=M2;
                else L=M1;
            }
            PDE(l,r,L,R);
            for(int M=L;M<=R;++M){
                ans=min(ans,getfunc(M).get(value(pos[M]))-getlifunc(M).get(value(M)));
            }
            cout<<ans.nz<<'\n';
            PDE(ans.nz);
        }
    }
}
