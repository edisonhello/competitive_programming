// redirect to POJ 3335
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
// #define pb push_back
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
const ld eps=1e-10;
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
// a1x+b1y+c1=0
// a2x+b2y+c2=0
// a1a2x+b1a2y+c1a2=0
// a1a2x+b2a1y+c2a1=0
// (b1a2-b2a1)y=c2a1-c1a2
// a1b2x+b1b2y+c1b2=0
// a2b1x+b1b2y+c2b1=0
// (a1b2-a2b1)x=c2b1-c1b2

bool jizz(Line l1,Line l2,Line l3){
    Point p=intersect(l2,l3);
    PDE(l1,l2,l3,p,(l1.pb-l1.pa)^(p-l1.pa));
    return ((l1.pb-l1.pa)^(p-l1.pa))<-eps;
}

bool cmp(const Line &a,const Line &b){
    return same(a.angle,b.angle)?(((b.pb-b.pa)^(a.pb-b.pa))>eps):a.angle<b.angle;
}
vector<Point> HPI(vector<Line> &ls){
    sort(ls.begin(),ls.end(),cmp);
    PDE(ls);
    vector<Line> pls(1,ls[0]); 
    for(unsigned int i=0;i<ls.size();++i)if(!same(ls[i].angle,pls.back().angle))pls.push_back(ls[i]);
    PDE(pls);
    deque<int> dq; dq.push_back(0); dq.push_back(1);
    for(unsigned int i=2u;i<pls.size();++i){
        // PDE(i);
        while(dq.size()>1u && jizz(pls[i],pls[dq.back()],pls[dq[dq.size()-2]]))dq.pop_back();
        while(dq.size()>1u && jizz(pls[i],pls[dq[0]],pls[dq[1]]))dq.pop_front();
        // if(dq.size()<=1u)return vector<Point>();
        dq.push_back(i);
    }
    while(dq.size()>1u && jizz(pls[dq.front()],pls[dq.back()],pls[dq[dq.size()-2]]))dq.pop_back();
    while(dq.size()>1u && jizz(pls[dq.back()],pls[dq[0]],pls[dq[1]]))dq.pop_front();
    // if(dq.size()<=1u)return vector<Point>();
    if(dq.size()<3u)return vector<Point>();
    PDE(dq);
    vector<Point> rt;
    for(unsigned int i=0u;i<dq.size();++i){
        rt.push_back(intersect(pls[dq[i]],pls[dq[(i+1)%dq.size()]]));
    }
    return rt;
}

void sol(){
    int n; cin>>n;
    vector<Point> v(n);
    for(int i=0;i<n;++i)cin>>v[i].x>>v[i].y;
    if(((v[1]-v[0])^(v[n-1]-v[0]))<0)reverse(v.begin()+1,v.end());
    vector<Line> ls(n);
    for(int i=0;i<n;++i)ls[i]=Line(v[i],v[(i+1)%n]);
    PDE(ls);
    vector<Point> ps=HPI(ls);
    PDE(ps);
    if(ps.size())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--)sol();
}
