#include<cstdio>
#include<vector>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1005;
const int MOD=1e9+7;
const double EPS=1e-10;
int sign(double x) {  //三态函数，减少精度问题
    return abs(x) < EPS ? 0 : x < 0 ? -1 : 1;
}
struct Point { //点的定义
    double x, y;
    Point(double x=0.0, double y=0.0) : x(x), y(y) {}
    Point operator + (const Point &rhs) const {  //向量加法
        return Point(x + rhs.x, y + rhs.y);
    }
    Point operator - (const Point &rhs) const {  //向量减法
        return Point(x - rhs.x, y - rhs.y);
    }
    Point operator * (double p) const {  //向量乘以标量
        return Point(x * p, y * p);
    }
    Point operator / (double p) const {  //向量除以标量
        return Point(x / p, y / p);
    }
    bool operator < (const Point &rhs) const {  //点的坐标排序
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
    bool operator == (const Point &rhs) const {  //判断同一个点
        return sign(x - rhs.x) == 0 && sign(y - rhs.y) == 0;
    }
};
struct Circle {  //圆的定义
    Point c;  //圆心
    double r;  //半径
    Circle() {}
    Circle(Point c, double r) : c(c), r(r) {}
    Point point(double a) {  //圆上的一点
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);
    }
};
typedef Point Vector;
Point p[N];
 
double dot(Vector A,Vector B){
    return A.x*B.x+A.y*B.y;
}
double length(Vector A){
    return sqrt(dot(A,A));
}
double cross(Vector A,Vector B){
    return A.x*B.y-A.y*B.x;
}
double Angle(Vector A,Vector B){
    double t=dot(A,B)/length(A)/length(B);
    return acos(t);
}
bool on_seg(Point p, Point a, Point b) {  //判断点在线段上（不包含端点），两点式
    return sign(cross(a-p, b-p)) == 0 && sign(dot(a-p, b-p)) <= 0;  //点p是否在线段ab上
}
 
double CulArea( Point A, Point B,Circle C)
{
    Vector OA = A-C.c, OB = B-C.c;
    Vector BA = A-B, BC = C.c-B;
    Vector AB = B-A, AC = C.c-A;
    double DOA = length(OA), DOB = length(OB),DAB = length(AB), r = C.r;
    if(sign(cross(OA,OB)) == 0) return 0;
    if(sign(DOA-C.r) < 0 && sign(DOB-C.r) < 0) return cross(OA,OB)*0.5;
    else if(DOB < r && DOA >= r) {
 
        double x = (dot(BA,BC) + sqrt(r*r*DAB*DAB-cross(BA,BC)*cross(BA,BC)))/DAB;
        double TS = cross(OA,OB)*0.5;
        return asin(TS*(1-x/DAB)*2/r/DOA)*r*r*0.5+TS*x/DAB;
    }
    else if(DOB >= r && DOA < r) {
        double y = (dot(AB,AC)+sqrt(r*r*DAB*DAB-cross(AB,AC)*cross(AB,AC)))/DAB;
        double TS = cross(OA,OB)*0.5;
        return asin(TS*(1-y/DAB)*2/r/DOB)*r*r*0.5+TS*y/DAB;
    }
    else if(fabs(cross(OA,OB)) >= r*DAB || dot(AB,AC) <= 0 || dot(BA,BC) <= 0) {
        if(dot(OA,OB) < 0){
            if(cross(OA,OB) < 0) return (-acos(-1.0)-asin(cross(OA,OB)/DOA/DOB))*r*r*0.5;
            else return ( acos(-1.0)-asin(cross(OA,OB)/DOA/DOB))*r*r*0.5;
        }
        else return asin(cross(OA,OB)/DOA/DOB)*r*r*0.5;
    }
    else {
        double x = (dot(BA,BC)+sqrt(r*r*DAB*DAB-cross(BA,BC)*cross(BA,BC)))/DAB;
        double y = (dot(AB,AC)+sqrt(r*r*DAB*DAB-cross(AB,AC)*cross(AB,AC)))/DAB;
        double TS = cross(OA,OB)*0.5;
        return(asin(TS*(1-x/DAB)*2/r/DOA)+asin(TS*(1-y/DAB)*2/r/DOB))*r*r*0.5 + TS*((x+y)/DAB-1);
    }
}
 
int main(void){
    double x1,y1,x2,y2,x3,y3,x4,y4,R;
    while((scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4,&R))==9){
        Circle C1=Circle({x4,y4},R);//圆
//cout <<"go"<<endl;
        int n=3;
//        scanf("%d",&n);
        double ans=0.0;
        p[0].x=x1,p[0].y=y1;
        p[1].x=x2,p[1].y=y2;
        p[2].x=x3,p[2].y=y3;
//        for(int i=0;i<n;i++){
//            double x,y;
//            scanf("%lf%lf",&x,&y);
//            p[i]={x,y};
//        }
 
        for(int i=0;i<n;i++)    ans+=CulArea(p[i],p[(i+1)%n],C1);
        if(ans<0)   ans=-ans;
        printf("%.2f\n",ans);
    }
 
    return 0;
}
