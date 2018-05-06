#include<bits/stdc++.h>
using namespace std;
#define int long long

struct pt{
    int x,y;
    pt(int x,int y):x(x),y(y){}
};
pt operator+(const pt &a,const pt &b){
    return pt(a.x+b.x,a.y+b.y);
}
pt operator-(const pt &a,const pt &b){
    return pt(a.x-b.x,a.y-b.y);
}
int operator^(const pt &a,const pt &b){
    return a.x*b.y-a.y*b.x;
}
int sq(const int x){ return x*x; }
int sqd(const pt &a,const pt &b){
    return sq(a.x-b.x)+sq(a.y-b.y);
}

const double eps=1e-8;

int32_t main(){
    int ts; cin>>ts; while(ts--){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        pt p1(x1,y1),p2(x2,y2);
        int sd=sqd(p1,p2);
        double d=sqrt(sd);
        if(d+r2<r1-eps || d+r1<r2-eps)cout<<"I"<<endl;
        else if(abs(d+r2-r1)<eps || abs(d+r1-r2)<eps)cout<<"E"<<endl;
        else cout<<"O"<<endl;
    }
}
