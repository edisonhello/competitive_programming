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

/* vint p;
bitset<33333> np;
void init(){
    for(int i=2;i<33333;++i){
        if(np[i])continue;
        p.pb(i);
        for(int j=i*i;j<33333;j+=i){
            np[j]=1;
        }
    }
    PDE(p.size());
} */

void sol(){
    auto getpw_3=[&](ll x)->int{
        ll xxx=pow(x,1.0/3);
        --xxx; --xxx; xxx=max(1ll,xxx);
        for(int z=5;z;--z,++xxx){
            if(xxx*xxx*xxx==x)return xxx;
        }
        return -1;
    };
    auto getpw_2=[&](ll x)->int{
        ll xxx=pow(x,1.0/2);
        --xxx; --xxx; xxx=max(1ll,xxx);
        for(int z=5;z;--z,++xxx){
            if(xxx*xxx==x)return xxx;
        }
        return -1;
    };

    int n; cin>>n;
    set<int> v;
    for(int i=0;i<n;++i){ int t; cin>>t; v.insert(t); }
    if(v.size()>4u){ cout<<-1<<'\n'; return; }
    if(DEBUG)cout<<"---------------- in sol ------------- "<<endl;
    // 1 1
    /* if([&]()->bool{ for(int i:v)if(i!=1)return 0; return 1; }()){ cout<<1<<" "<<1<<'\n'; return; }
    if(DEBUG)cout<<"fin 1 1"<<endl; */
    // 1 x
    int mx=*prev(v.end());
    int mx_3=getpw_3(mx);
    if(mx_3!=-1 && [&]()->bool{ for(int i:v)if(i!=1 && i!=mx_3 && i!=mx_3*mx_3 && i!=mx_3*mx_3*mx_3)return 0; return 1; }()){ cout<<1<<" "<<mx_3<<'\n'; return; }
    int mx_2=getpw_2(mx);
    if(mx_2!=-1 && [&]()->bool{ for(int i:v)if(i!=1 && i!=mx_2 && i!=mx_2*mx_2)return 0; return 1; }()){ cout<<1<<" "<<mx_2<<'\n'; return; }
    if(v.size()==2u && *v.begin()==1){ cout<<1<<" "<<mx<<'\n'; return; }
    if(DEBUG)cout<<"fin 1 x"<<endl;
    // x y
    pii ans(1e9,1e9);
    for(int i:v){
        int x=getpw_3(i);
        if(x==-1)continue;
        int y=-1;
        int ok=1;
        for(int i:v){
            int c=0;
            while(i%x==0)i/=x,++c;
            if(c==0){
                int yy=getpw_3(i);
                if(yy==-1){ ok=0; break; }
                else if(y!=-1 && y!=yy){ ok=0; break; }
                y=yy;
            }
            else if(c==1){
                int yy=getpw_2(i);
                if(yy==-1){ ok=0; break; }
                else if(y!=-1 && y!=yy){ ok=0; break; }
                y=yy;
            }
            else if(c==2){
                if(y!=-1 && y!=i){ ok=0; break; }
                y=i;
            }
        }
        if(ok)ans=min(ans,make_pair(min(x,y),max(x,y)));
    }
    if(v.size()==2u){
        int xy=getpw_3(1ll*(*v.begin())*(*prev(v.end())));
        if(xy!=-1){
            int x=*v.begin()/xy,y=*prev(v.end())/xy;
            ans=min(ans,make_pair(min(x,y),max(x,y)));
        }
    }
    if(ans.first<1e9)cout<<ans.first<<" "<<ans.second<<'\n';
    else cout<<-1<<'\n';
}

int main(){
    CPPinput;
    // init();
    int t; cin>>t; while(t--){
        sol();
        if(DEBUG)fflush(stdout);
    }
}

