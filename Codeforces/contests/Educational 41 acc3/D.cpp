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

struct line{
    ll a,b,c;
    bool on(ll x,ll y){
        return a*x+b*y==c;
    }
};

int n;
ll x[100005],y[100005];
bitset<100005> oli;

line gline(int p1,int p2){
    if(x[p1]==x[p2]){
        return (line){1,0,x[p1]};
    }
    else return (line){y[p2]-y[p1],x[p1]-x[p2],(y[p2]-y[p1])*x[p1]+(x[p1]-x[p2])*y[p1]};
}

int main(){
    auto clk=clock();
    srand(time(0));
    CPPinput;
    cin>>n;
    for(int i=0;i<n;++i)cin>>x[i]>>y[i];
    if(n<5){
        YES;
        exit(0);
    }
    do{
        int p1=0,p2=0;
        while(p1==p2)p1=abs(rand()*rand())%n,p2=abs(rand()*rand())%n;
        oli.set();
        oli[p1]=oli[p2]=0;
        line l1=gline(p1,p2);
        for(int i=0;i<n;++i){
            if(i==p1 || i==p2)continue;
            if(l1.on(x[i],y[i]))oli[i]=0;
        }
        vector<int> ot;
        for(int i=0;i<n;++i){
            if(oli[i])ot.pb(i);
        }
        if(ot.size()<3u){
            YES;
            exit(0);
        }
        line l2=gline(ot[0],ot[1]);
        bool ok=1;
        for(int i:ot){
            if(!l2.on(x[i],y[i])){
                ok=0;
                break;
            }
        }
        if(ok){
            YES;
            exit(0);
        }
    }while((double)(clock()-clk)/CLOCKS_PER_SEC<=1.95);
    NO;
}
