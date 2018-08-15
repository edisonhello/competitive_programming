#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

const double eps=1e-9;
// #define double int
// const int eps=0;

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

bool jizz(Line l1,Line l2,Line l3){
    Point p=intersect(l2,l3);
    return ((l1.pb-l1.pa)^(p-l1.pa))<-eps;
}

bool cmp(const Line &a,const Line &b){
    return same(a.angle,b.angle)?(((b.pb-b.pa)^(a.pb-b.pa))>eps):a.angle<b.angle;
}

// availble area for Line l is (l.pb-l.pa)^(p-l.pa)>0
vector<Point> HPI(vector<Line> &ls){
    sort(ls.begin(),ls.end(),cmp);
    vector<Line> pls(1,ls[0]); 
    for(unsigned int i=0;i<ls.size();++i)if(!same(ls[i].angle,pls.back().angle))pls.push_back(ls[i]);
    // for(auto &l:pls)cout<<l;
    deque<int> dq; dq.push_back(0); dq.push_back(1);
    for(unsigned int i=2u;i<pls.size();++i){
        while(dq.size()>1u && jizz(pls[i],pls[dq.back()],pls[dq[dq.size()-2]]))dq.pop_back();
        while(dq.size()>1u && jizz(pls[i],pls[dq[0]],pls[dq[1]]))dq.pop_front();
        dq.push_back(i);
    }
    while(dq.size()>1u && jizz(pls[dq.front()],pls[dq.back()],pls[dq[dq.size()-2]]))dq.pop_back();
    while(dq.size()>1u && jizz(pls[dq.back()],pls[dq[0]],pls[dq[1]]))dq.pop_front();
    // cout<<dq.size()<<endl;
    if(dq.size()<3u)return vector<Point>(); // no solution or solution is not a convex
    vector<Point> rt;
    for(unsigned int i=0u;i<dq.size();++i)rt.push_back(intersect(pls[dq[i]],pls[dq[(i+1)%dq.size()]]));
    return rt;
}

int main(){
    int ts=0,n; while(cin>>n,n){
        cout<<"Floor #"<<(++ts)<<endl;
        cout<<"Surveillance is ";
        vector<Point> p(n);
        vector<Line> l(n);
        for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
        // p.push_back(p[0]);
        for(int i=0;i<n;++i){
            Point &pa=p[i],&pb=p[(i+1)%n];
            if(pa.x==pb.x){
                if(pa.y<pb.y)pa.x-=1e-1,pb.x-=1e-1;
                else pa.x+=1e-1,pb.x+=1e-1;
            }
            else{
                if(pa.x<pb.x)pa.y+=1e-1,pb.y+=1e-1;
                else pa.y-=1e-1,pb.y-=1e-1;
            }
        }
        // for(int i=0;i<n;++i)cout<<fixed<<setprecision(5)<<p[i].x<<" "<<p[(i+1)%n].y<<endl;
        reverse(p.begin(),p.end());
        for(int i=0;i<n;++i)l[i]=Line(p[i],p[(i+1)%n]);
        p=HPI(l);
        if(p.size()<3u)cout<<"impossible.\n\n";
        else cout<<"possible.\n\n";
    }
}
