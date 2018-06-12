#include<bits/stdc++.h>
#include"lib1341.h"
using namespace std;
#define point pair<long long,long long>
#define X first
#define Y second

point operator+(const point &a,const point &b){ return point(a.X+b.X,a.Y+b.Y); }
point operator-(const point &a,const point &b){ return point(a.X-b.X,a.Y-b.Y); }
point operator*(const point &a,const int &x){ return point(a.X*x,a.Y*x); }
point operator/(const point &a,const int &x){ return point(a.X/x,a.Y/x); }

map<point,int> rec;

int n;
bool check(point p){
    if(p.X<=0 || p.Y<=0)return 0;
    if(p.X>n || p.Y>n)return 0;
    if(rec.find(p)!=rec.end())return rec[p];
    return rec[p]=Examine(p.X,p.Y);
}

point getLimit(point base,point side,point delta,point invdelta){
    while(base!=side){
        point mid=(base+side+invdelta)/2;
        bool move=0;
        if(check(mid)){
            point mid2=(base+mid)/2;
            if(check(mid2)){
                point mid3=(base+mid2)/2;
                if(check(mid3)){
                    base=mid;
                    move=1;
                }
            }
        }
        if(!move){
            side=mid+delta;
        }
    }
    return base;
}

int ext(point base,point delta){
    int cnt=0;
    while(check(base+delta+delta)){
        ++cnt;
        base=base+delta+delta;
    }
    return cnt;
}

int main(){
    int x,y;
    Init(&n,&x,&y);
    point p0(x,y);
    point p1=getLimit(p0,point(x,1),point(0,1),point(0,0)); // left
    point p2=getLimit(p0,point(x,n),point(0,-1),point(0,1)); // right
    point p3=getLimit(p0,point(1,y),point(1,0),point(0,0)); // up
    point p4=getLimit(p0,point(n,y),point(-1,0),point(1,0)); // down
    int m=(p2-p1).Y+1;
    // cout<<"[DEBUG] got m: "<<m<<endl;
    p0=point((p3+p4).X/2,(p1+p2).Y/2);
    int extr=ext(p0,point(0,m));
    int extl=ext(p0,point(0,-m));
    int extu=ext(p0,point(-m,0));
    int extd=ext(p0,point(m,0));
    if(extr+extl==1){
        if(extr)p0.Y+=m;
        else p0.Y-=m;
        if(extu)p0.X-=m;
        else p0.X+=m;
    }
    else{
        if(extr==2)p0.Y+=m*2;
        if(extl==2)p0.Y-=m*2;
        if(extu==2)p0.X-=m*2;
        if(extd==2)p0.X+=m*2;
    }
    Solution(p0.X,p0.Y);
}
