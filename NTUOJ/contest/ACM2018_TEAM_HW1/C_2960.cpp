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

bool same(const double a,const double b){ return abs(a-b)<1e-9; }

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
    Line():a(0),b(0),c(0),angle(0),pa(),pb(){}
    Line(Point pa,Point pb):a(pa.y-pb.y),b(pb.x-pa.x),c(pa^pb),angle(atan2(-a,b)),pa(pa),pb(pb){}
};
ostream& operator<<(ostream &o,const Line a){ o<<"("<<a.a<<"x+"<<a.b<<"y+"<<a.c<<"=0, angle:"<<a.angle<<" , ref point: "<<a.pa<<" and "<<a.pb<<")\n"; return o; }

Point intersect(Line la,Line lb){
    if(same(la.a*lb.b,la.b*lb.a))return Point(7122,7122);
    double bot=-la.a*lb.b+la.b*lb.a;
    return Point(-la.b*lb.c+la.c*lb.b,la.a*lb.c-la.c*lb.a)/bot;
}

int calc(vector<Point> &v){
    vector<Point> tb;
    sort(v.begin(),v.end(),[&](const Point &a,const Point &b){ return a.x<b.x; });
    for(int i=0;i<v.size();++i){
        while(tb.size()>1u && ((v[i]-tb.back())^(tb[tb.size()-2]-tb.back()))>=0)tb.pop_back();
        tb.pb(v[i]);
    }
    int tmp=tb.size();
    for(int i=v.size()-2;i>=0;--i){
        while(tb.size()>tmp && ((v[i]-tb.back())^(tb[tb.size()-2]-tb.back()))>=0)tb.pop_back();
        tb.pb(v[i]);
    }
    return tb.size()-1;
}

int hr(){
    return rand()&32767;
}

int fr(){
    return ((hr()<<15)|(hr()));
}

double mr(){
    return (double)fr()/RAND_MAX;
}

Point tri[3];
double xmx=-1e9,xmn=1e9,ymx=-1e9,ymn=1e9;

double rmr(double l,double r){
    return mr()*(r-l)+l;
}

bool intri(double x,double y){
    Point p(x,y);
    double triarea=abs((tri[2]-tri[0])^(tri[1]-tri[0]));
    double area3=abs((tri[2]-p)^(tri[1]-p))+abs((tri[1]-p)^(tri[0]-p))+abs((tri[0]-p)^(tri[2]-p));
    // PDE(triarea,area3);
    return same(triarea,area3);
}

Point gnp(){
    double x,y;
    /* do{
        x=rmr(xmn,xmx),y=rmr(ymn,ymx);
    }while(!intri(x,y)); */
    x=mr(),y=mr();
    if(x+999*y>1000)x=1000-x,y=1-y;
    return {x,y};
}

double test(int n){
    auto startTime=clock();
    // double TL=0.95;
    int tt=200000000;
    // int tt=-1;
    int sum=0;
    // for(;(double)(clock()-startTime)/CLOCKS_PER_SEC<TL;++tt){
    for(int z=0;z<tt;++z){
        vector<Point> v;
        while(v.size()<n)v.eb(gnp());
        sum+=calc(v);
    }
    // PDE(tt);

    return (double)sum/tt;
}

int main(){
    srand(time(0));
    // CPPinput;
    /* for(int i=0;i<3;++i)cin>>tri[i];
    for(int i=0;i<3;++i)xmx=max(xmx,tri[i].x);
    for(int i=0;i<3;++i)ymx=max(ymx,tri[i].y);
    for(int i=0;i<3;++i)xmn=min(xmn,tri[i].x);
    for(int i=0;i<3;++i)ymn=min(ymn,tri[i].y); */
    // PDE(xmx,ymx,xmn,ymn);
    cout<<"double ans[]={0,0,0";
    if(DEBUG || 1){
        for(int i=3;i<=4;++i){
            // cout<<"ans of n = "<<i<<" is "<<test(i)<<endl;
            cout<<",";
            cout<<fixed<<setprecision(8)<<test(i);
        }
    }
    else{
        int n; cin>>n;
        cin>>n>>n>>n>>n>>n>>n;
        cout<<fixed<<setprecision(10)<<test(n)<<endl;
    }
    cout<<"};";
    // for(int i=4;i<=10;++i)test(i);
    // int n; cin>>n>>n>>n>>n>>n>>n>>n;
    // cout<<fixed<<setprecision(6)<<ans[n]<<endl;
}
