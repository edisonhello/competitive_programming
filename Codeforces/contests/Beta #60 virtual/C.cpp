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
const ld eps=1e-9;
const ll mod=1e9+7;

#define sq(x) ((x)*(x))

struct point{
    double x,y,z; 
} pt[10005];
ostream& operator<<(ostream &o,const point a){ o<<"("<<a.x<<","<<a.y<<","<<a.z<<")"; return o; }
point operator+(const point &a,const point &b){ return point{b.x+a.x,b.y+a.y,b.z+a.z}; }
point operator-(const point &a,const point &b){ return point{a.x-b.x,a.y-b.y,a.z-b.z}; }
point operator*(const point &a,double b){ return point{a.x*b,a.y*b,a.z*b}; }


int main(){
    CPPinput;
    int n; cin>>n;
    for(int i=0;i<=n;++i)cin>>pt[i].x>>pt[i].y>>pt[i].z;
    double mev,opv; cin>>mev>>opv;
    point me; cin>>me.x>>me.y>>me.z;
    double totaltime=0;
    auto dist=[&](point a,point b)->double{ return sqrt(sq(a.x-b.x)+sq(a.y-b.y)+sq(a.z-b.z)); };
    /* auto canreach=[&](point target,double able_time)->bool{
        return dist(target,me)/mev<=able_time+eps;
    }; */
    for(int i=0;i<n;++i){
        double linetime=dist(pt[i],pt[i+1])/opv;
        PDE(i,linetime);
        point vec=pt[i+1]-pt[i];
        point target;
        double met,opt;
        auto func=[&](double part)->double{
            target=pt[i]+vec*part;
            met=dist(target,me)/mev;
            opt=totaltime+linetime*part;
            PDE(part,target,met,opt);
            return met-opt;
        };
        double L=0,R=1;
        while(R-L>1e-13){
            double le=(R-L)/3;
            double M1=L+le,M2=R-le;
            double fM1=func(M1),fM2=func(M2);
            if(fM1>fM2)L=M1; else R=M2;
            // PDE(L,M1,M2,R);
        }
        if(func(L)>-1e-9){
            totaltime+=linetime;
            continue;
        }
        PDE(R);
        L=0;
        while(R-L>1e-13){
            double M=(L+R)/2;
            if(func(M)<0)R=M;
            else L=M;
        }
        cout<<"YES"<<endl;
        cout<<fixed<<setprecision(12)<<met<<endl;
        cout<<fixed<<setprecision(12)<<target.x<<" "<<target.y<<" "<<target.z<<endl;
        exit(0);
    }
    if(totaltime>=dist(me,pt[n])/mev-1e-9){
        cout<<"YES"<<endl;
        cout<<totaltime<<endl;
        cout<<pt[n].x<<" "<<pt[n].y<<" "<<pt[n].z<<endl;
        exit(0);
    }
    cout<<"NO"<<endl;
}
