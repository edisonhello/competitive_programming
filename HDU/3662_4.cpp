#include<cstdio>
#include<vector>
#include<bitset>
#include<cmath>
#include<cassert>
#include<iostream>
using namespace std;
#define sq(x) ((x)*(x))

struct Point{
    double x,y,z;
    Point(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
};
Point operator+(const Point &a,const Point &b){ return Point(a.x+b.x,a.y+b.y,a.z+b.z); }
Point operator-(const Point &a,const Point &b){ return Point(a.x-b.x,a.y-b.y,a.z-b.z); }
Point operator*(const Point &a,const double &b){ return Point(a.x*b,a.y*b,a.z*b); }
Point operator/(const Point &a,const double &b){ return Point(a.x/b,a.y/b,a.z/b); }
double operator*(const Point &a,const Point &b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
Point operator^(const Point &a,const Point &b){ return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x); }
double abs(const Point &a){ return sqrt(sq(a.x)+sq(a.y)+sq(a.z)); }
// ostream& operator<<(ostream &o,const Point &p){ o<<"("<<p.x<<","<<p.y<<","<<p.z<<")"; return o; }

const int maxn=1010;
const double eps=1e-8;

bitset<maxn> v[maxn];
Point p[maxn];

struct Face{
    int pi[3];
    bool res;
    Face(int pa=0,int pb=0,int pc=0){ pi[0]=pa; pi[1]=pb; pi[2]=pc; res=1; }
    bool ontop(Point np){
        return (((p[pi[1]]-p[pi[0]])^(p[pi[2]]-p[pi[0]]))*(np-p[pi[0]]))>=0;
    }
};

Face f[maxn*maxn];

int convex3d(int n){
    // cout<<"in convex3d"<<endl;
    int m=0;
    for(int i=2;i<n;++i){
        if(abs(((p[i]-p[0])^(p[1]-p[0])))>eps){
            swap(p[i],p[2]);
        }
    }
    // cout<<"finish same line avoid"<<endl;
    f[m++]=Face(0,1,2);
    f[m++]=Face(2,1,0);
    // cout<<"inserted new 2 plane"<<endl;
    for(int i=3;i<n;++i){
        if(f[0].ontop(p[i]) && f[1].ontop(p[i]));
        else swap(p[i],p[3]);
    }
    // cout<<"finish same plane avoid"<<endl;
    for(int i=3;i<n;++i){
        // cout<<"doing i: "<<i<<endl;
        for(int j=0;j<n;++j)v[j].reset();
        // cout<<"reseted"<<endl;
        for(int j=0;j<m;++j){
            if(f[j].res && f[j].ontop(p[i])){
                f[j].res=0;
                for(int k=0;k<3;++k){
                    v[f[j].pi[k]][f[j].pi[k==2?0:k+1]]=1;
                }
            }
        }
        // cout<<"deleted"<<endl;
        int om=m;
        for(int j=0;j<om;++j){
            for(int k=0;k<3;++k){
                int z1=f[j].pi[k],z2=f[j].pi[k==2?0:k+1];
                // cout<<"z1, z2: "<<z1<<" "<<z2<<endl;
                if(v[z1][z2] && !v[z2][z1]){
                    f[m++]=Face(z1,z2,i);
                }
            }
        }
        // cout<<"created"<<endl;
    }
    int mm=0;
    for(int i=0;i<m;++i){
        if(f[i].res)f[mm++]=f[i];
    }
    return mm;
}

bitset<maxn> killl;

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n; while(scanf("%d",&n)==1){
        if(n<=3)assert(0);
        for(int i=0;i<n;++i){
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        }
        // cout<<"start convex"<<endl;
        int m=convex3d(n);
        // cout<<"fin convex"<<endl;
        killl.reset();
        for(int i=0;i<m;++i){
            for(int j=0;j<i;++j){
                int c=0;
                for(int k=0;k<3;++k){
                    if(f[i].ontop(p[f[j].pi[k]]))++c;
                }
                if(c==3){
                    killl[j]=1;
                }
            }
        }
        printf("%d\n",m-killl.count());
    }
}
