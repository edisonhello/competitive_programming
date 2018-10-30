#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

const double eps=1e-9;
bool same(const double a,const double b){ return abs(a-b)<eps; }

struct Point{
    double x,y,z;
    Point():x(0),y(0),z(0){}
    Point(double x,double y,double z):x(x),y(y),z(z){}
};
Point operator+(const Point a,const Point b){ return Point(a.x+b.x,a.y+b.y,a.z+b.z); }
Point operator-(const Point a,const Point b){ return Point(a.x-b.x,a.y-b.y,a.z-b.z); }
Point operator*(const Point a,const double b){ return Point(a.x*b,a.y*b,a.z*b); }
double operator*(const Point a,const Point b){ return a.x*b.x+a.y*b.y+a.z*b.z; }
Point operator/(const Point a,const double b){ return Point(a.x/b,a.y/b,a.z/b); }
Point operator^(const Point a,const Point b){ return Point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x); }
double abs(const Point a){ return sqrt(a.x*a.x+a.y*a.y+a.z*a.z); }

double absvol(const Point a,const Point b,const Point c,const Point d){
    return abs(((b-a)^(c-a))*(d-a))/6;
}

struct convex3D{
static const int maxn=1010;
struct Triangle{
    int a,b,c;
    bool res;
    Triangle(){}
    Triangle(int a,int b,int c,bool res=1):a(a),b(b),c(c),res(res){}
};
int n,m;
Point p[maxn];
Triangle f[maxn*8];
int id[maxn][maxn];
bool on(Triangle &t,Point &pt){
    return ((p[t.c]-p[t.b])^(p[t.a]-p[t.b]))*(pt-p[t.a])>eps;
}
void deal(int pi,int a,int b){
    int f2=id[a][b];
    if(f[f2].res){
        if(on(f[f2],p[pi]))dfs(pi,f2);
        else{
            id[pi][b]=id[a][pi]=id[b][a]=m;
            f[m++]=Triangle(b,a,pi,1);
        }
    }
}
void dfs(int pi,int now){
    f[now].res=0;
    deal(pi,f[now].b,f[now].a);
    deal(pi,f[now].c,f[now].b);
    deal(pi,f[now].a,f[now].c);
}
void operator()(){
    if(n<4)return;
    if([&]()->int{
        for(int i=1;i<n;++i){
            if(abs(p[0]-p[i])>eps){
                swap(p[1],p[i]);
                return 0;
            }
        }
        return 1;
    }())return;
    if([&]()->int{
        for(int i=2;i<n;++i){
            if(abs((p[0]-p[i])^(p[1]-p[i]))>eps){
                swap(p[2],p[i]);
                return 0;
            }
        }
        return 1;
    }())return;
    if([&]()->int{
        for(int i=3;i<n;++i){
            if(abs(((p[1]-p[0])^(p[2]-p[0]))*(p[i]-p[0]))>eps){
                swap(p[3],p[i]);
                return 0;
            }
        }
        return 1;
    }())return;
    for(int i=0;i<4;++i){
        Triangle tmp((i+1)%4,(i+2)%4,(i+3)%4,1);
        if(on(tmp,p[i]))swap(tmp.b,tmp.c);
        id[tmp.a][tmp.b]=id[tmp.b][tmp.c]=id[tmp.c][tmp.a]=m;
        f[m++]=tmp;
    }
    for(int i=4;i<n;++i){
        for(int j=0;j<m;++j){
            if(f[j].res && on(f[j],p[i])){
                dfs(i,j);
                break;
            }
        }
    }
    int mm=m; m=0;
    for(int i=0;i<mm;++i){
        if(f[i].res)f[m++]=f[i];
    }
}
bool same(int i,int j){
    return !(absvol(p[f[i].a],p[f[i].b],p[f[i].c],p[f[j].a])>eps || absvol(p[f[i].a],p[f[i].b],p[f[i].c],p[f[j].b])>eps || absvol(p[f[i].a],p[f[i].b],p[f[i].c],p[f[j].c])>eps);
}
int faces(){
    int rt=0;
    for(int i=0;i<m;++i){
        int iden=1;
        for(int j=0;j<i;++j){
            if(same(i,j))iden=0;
        }
        rt+=iden;
    }
    return rt;
}
} tb;

int main(){
    while(cin>>tb.n){
        tb.m=0;
        for(int i=0;i<tb.n;++i)cin>>tb.p[i].x>>tb.p[i].y>>tb.p[i].z;
        tb();
        cout<<tb.faces()<<endl;
    }
}
