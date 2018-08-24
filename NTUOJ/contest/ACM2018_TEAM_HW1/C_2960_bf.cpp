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
#include<random>
#include<thread>
#include<future>

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

struct Point{
    double x,y;
    Point():x(0),y(0){}
    Point(double x,double y):x(x),y(y){}
};
Point operator+(const Point a,const Point b){ return Point(a.x+b.x,a.y+b.y); }
Point operator-(const Point a,const Point b){ return Point(a.x-b.x,a.y-b.y); }
Point operator*(const Point a,const double b){ return Point(a.x*b,a.y*b); }
Point operator/(const Point a,const double b){ return Point(a.x/b,a.y/b); }
double operator^(const Point a,const Point b){ return a.x*b.y-a.y*b.x; }
double abs(const Point a){ return sqrt(a.x*a.x+a.y*a.y); }
ostream& operator<<(ostream &o,const Point a){ o<<"("<<a.x<<", "<<a.y<<")"; return o; }
istream& operator>>(istream &i,Point &a){ i>>a.x>>a.y; return i; }


struct Line{
    // ax+by+c=0
    double a,b,c;
    double angle;
    Point pa,pb;
    Line():a(0),b(0),c(0),pa(),pb(){}
    Line(Point pa,Point pb):a(pa.y-pb.y),b(pb.x-pa.x),c(pa^pb),pa(pa),pb(pb){}
};

struct WorkerInfo{

bool same(const double a,const double b){ return abs(a-b)<1e-9; }


Point intersect(Line la,Line lb){
    if(same(la.a*lb.b,la.b*lb.a))return Point(7122,7122);
    double bot=-la.a*lb.b+la.b*lb.a;
    return Point(-la.b*lb.c+la.c*lb.b,la.a*lb.c-la.c*lb.a)/bot;
}

mt19937 generator;

double myRand(double l,double r){
    return l+(double)generator()/(((double)INT_MAX)+1)*(r-l);
}

vector<Point> convexHull(vector<Point> v){
    assert(v.size()>2u);
    sort(v.begin(),v.end(),[](const auto &a,const auto &b){ return a.x<b.x; });
    vector<Point> tb;
    for(auto i=0u;i<v.size();++i){
        while(tb.size()>1u && ((v[i]-tb.back())^(tb[tb.size()-2]-tb.back()))>=0)tb.pop_back();
        tb.push_back(v[i]);
    }
    auto tmp=tb.size();
    for(int i=int(v.size()-2);i>=0;--i){
        while(tb.size()>tmp && ((v[i]-tb.back())^(tb[tb.size()-2]-tb.back()))>=0)tb.pop_back();
        tb.push_back(v[i]);
    }
    tb.pop_back();
    return tb;
}

vector<Point> random_points(vector<Point> ps,int cnt){
    double xmn=1e9,xmx=-1e9,ymn=1e9,ymx=-1e9;
    for(auto p:ps)xmn=min(xmn,p.x),xmx=max(xmx,p.x),ymn=min(ymn,p.y),ymx=max(ymx,p.y);
    vector<Point> ans;
    while(cnt>0){
        double x=myRand(xmn,xmx),y=myRand(ymn,ymx);
        ps.push_back(Point(x,y));
        if(convexHull(ps).size()==3u)ans.emplace_back(x,y),--cnt;
        ps.pop_back();
    }
    return ans;
}


int n;
vector<Point> tri;
// double pointsum;

void init(int _n,vector<Point> _v){
    n=_n;
    tri=_v;
}

WorkerInfo():generator(mt19937(clock())){}

} worker[8];

void work(WorkerInfo *info,double *pointsum,int *zz){
    for(int i=0;i<8;++i){
        auto v=info->convexHull(info->random_points(info->tri,info->n));
        // PDE(v.size());
        (*pointsum)+=v.size();
    }
    (*zz)+=8;
    return;
}

int main(){
    CPPinput;
    int n; cin>>n;
    // int t; cin>>t;
    // cout<<"get triangle: "<<endl;
    // for(auto &p:tri)cin>>p.x>>p.y;
    vector<Point> tri(3);
    // tri[0]={4,7}; tri[1]={10,12}; tri[2]={8,3}; // 10: 5.56
    tri[0]={0,0}; tri[1]={10,0}; tri[2]={0,7}; // 10: 5.65, 1000: 14.969
    // tri[0]={0,0}; tri[1]={10000,0}; tri[2]={10000,1}; // 10: 5.4059, 1000: 11.963

    for(int i=0;i<8;++i)worker[i].init(n,tri);

    double pointsum=0;
    int zz=0;
    for(;;){
        double re0=0,re1=0,re2=0,re3=0,re4=0,re5=0,re6=0,re7=0;
        int zz0=0,zz1=0,zz2=0,zz3=0,zz4=0,zz5=0,zz6=0,zz7=0;
        thread t0(bind(&work,&worker[0],&re0,&zz0));
        thread t1(bind(&work,&worker[1],&re1,&zz1));
        thread t2(bind(&work,&worker[2],&re2,&zz2));
        thread t3(bind(&work,&worker[3],&re3,&zz3));
        thread t4(bind(&work,&worker[4],&re4,&zz4));
        thread t5(bind(&work,&worker[5],&re5,&zz5));
        thread t6(bind(&work,&worker[6],&re6,&zz6));
        thread t7(bind(&work,&worker[7],&re7,&zz7));

        t0.join();
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();

        // PDE(re0,re1,re2);
        // PDE(zz0,zz1,zz2);

        pointsum+=re0+re1+re2+re3+re4+re5+re6+re7;
        zz+=zz0+zz1+zz2+zz3+zz4+zz5+zz6+zz7;

        if((zz&65535)==0)PDE(zz,pointsum/zz);
        // if((zz&262143)==0)break;
    }
    // cout<<fixed<<setprecision(12)<<pointsum/t<<endl;

}
