#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<cassert>
using namespace std;
#define sq(x) ((x)*(x))

struct Point{
    double x,y,z;
    int i;
    Point(double x=0,double y=0,double z=0,int i=0):x(x),y(y),z(z),i(i){}
};
Point operator+(const Point &a,const Point &b){ return Point(a.x+b.x,a.y+b.y,a.z+b.z); }
Point operator-(const Point &a,const Point &b){ return Point(a.x-b.x,a.y-b.y,a.z-b.z); }
Point operator*(const Point &a,const double &b){ return Point(a.x*b,a.y*b,a.z*b); }
Point operator/(const Point &a,const double &b){ return Point(a.x/b,a.y/b,a.z/b); }
double operator*(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
Point operator^(const Point &a,const Point &b){ return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x); }
double abs(const Point &a){ return sqrt(sq(a.x)+sq(a.y)+sq(a.z)); }
// ostream& operator<<(ostream &o,const Point &p){ o<<"("<<p.x<<","<<p.y<<","<<p.z<<")"; return o; }

struct Face{
    Point p[3];
    Face(Point pa,Point pb,Point pc){ p[0]=pa; p[1]=pb; p[2]=pc; }
    bool ontop(Point np){
        // cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<np<<endl;
        // cout<<"vol : "<<(((p[1]-p[0])^(p[2]-p[0]))*(np-p[0]))<<endl;
        return (((p[1]-p[0])^(p[2]-p[0]))*(np-p[0]))>=0;
    }
};

bitset<1231> v[1231];

vector<Face> convex3d(vector<Point> &ps){
    vector<Face> rt;
    rt.push_back(Face(ps[0],ps[1],ps[2]));
    rt.push_back(Face(ps[2],ps[1],ps[0]));
    for(int i=3;i<int(ps.size());++i){
        if(rt[0].ontop(ps[i]) && rt[1].ontop(ps[i]));
        else swap(ps[i],ps[3]);
    }
    for(int i=0;i<int(ps.size());++i)ps[i].i=i;
    // for(auto &p:ps)cout<<p<<" "; cout<<endl;
    for(int i=3;i<int(ps.size());++i){
        // cout<<"-----------------------------"<<endl;
        // cout<<"meow i: "<<i<<" , p: "<<ps[i]<<endl;
        for(int j=0;j<int(ps.size());++j)v[j].reset();
        vector<Face> nrt;
        for(int j=0;j<int(rt.size());++j){
            // cout<<"face j: "<<j<<" : "<<rt[j].p[0]<<rt[j].p[1]<<rt[j].p[2]<<endl;
            if(rt[j].ontop(ps[i])){
                for(int k=0;k<3;++k){
                    v[rt[j].p[k].i][rt[j].p[k==2?0:k+1].i]=1;
                    // cout<<rt[j].p[k]<<" to "<<rt[j].p[k==2?0:k+1]<<" is empty"<<endl;
                }
                // cout<<"on top"<<endl;
            }
            else nrt.push_back(rt[j]);
        }
        for(int j=0;j<int(rt.size());++j){
            for(int k=0;k<3;++k){
                int z1=rt[j].p[k].i,z2=rt[j].p[k==2?0:k+1].i;
                if(v[z1][z2] && !v[z2][z1]){
                    // cout<<"match "<<rt[j].p[k]<<" to "<<rt[j].p[k==2?0:k+1]<<", add face "<<ps[z2]<<ps[z1]<<ps[i]<<endl;
                    nrt.push_back(Face(ps[z1],ps[z2],ps[i]));
                }
            }
        }
        nrt.swap(rt);
        // cout<<"rt.size(): "<<rt.size()<<endl;
    }
    return rt;
}

bitset<1231> killl;

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(scanf("%d",&n)==1){
        if(n<=3)assert(0);
        vector<Point> pts(n);
        for(int i=0;i<n;++i){
            scanf("%lf%lf%lf",&pts[i].x,&pts[i].y,&pts[i].z);
            pts[i].i=i;
        }
        // for(auto &p:pts)cout<<p<<" "; cout<<endl;
        vector<Face> rt=convex3d(pts);
        // cout<<"this is output -> ";
        /* for(Face &f:rt){
            cout<<"["<<f.p[0]<<f.p[1]<<f.p[2]<<"]";
        } cout<<endl; */
        killl.reset();
        for(int i=0;i<int(rt.size());++i){
            for(int j=0;j<i;++j){
                int c=0;
                for(int k=0;k<3;++k){
                    if(rt[i].ontop(rt[j].p[k]))++c;
                }
                if(c==3){
                    killl[j]=1;
                    // cout<<i<<" killed "<<j<<endl;
                }
            }
        }
        printf("%d\n",rt.size()-killl.count());
    }
}
