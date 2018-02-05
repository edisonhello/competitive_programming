#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define pt pair<ld,ld>

int n;
pt pts[55];

ld dis(ld x1,ld y1,ld x2,ld y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
ld dis(pt a,pt b){return dis(a.first,a.second,b.first,b.second);}

struct circle{
    ld x,y,r;
    circle(pt a,pt b){
        r=dis(a,b)/2;
        x=(a.first+b.first)/2;
        y=(a.second+b.second)/2;
    }
    circle(pt a,ld r):x(a.first),y(a.second),r(r){}
};
struct line{
    ld a,b,c;
    line(ld a,ld b,ld c):a(a),b(b),c(c){}
};

line meow(pt a,pt b){
    pt mid((a.first+b.first)/2,(a.second+b.second)/2);
    ld dx=b.first-a.first,dy=b.second-a.second;
    return line(dx,dy,mid.first*dx+mid.second*dy);
}

pt inter(line l1,line l2){
    ld delta=l1.a*l2.b-l1.b*l2.a;
    ld deltax=l1.c*l2.b-l1.b*l2.c;
    ld deltay=l1.a*l2.c-l1.c*l2.a;
    return pt(deltax/delta,deltay/delta);
}

circle getcircle(pt a,pt b,pt c){
    line l1=meow(a,b),l2=meow(a,c);

    pt X=inter(l1,l2);
    return circle(X,dis(X,a));
}


bool circleok(circle &c){
    int cnt=0;
    for(int i=0;i<n;++i){
        if(dis(pts[i].first,pts[i].second,c.x,c.y)>c.r+1e-8)++cnt;
    }
    return cnt<=4;
}

// void debug(){
//     line l1=meow(pts[0],pts[1]);
// }

int main(){
    srand(time(0));
    int t; cin>>t; while(t--){
        cin>>n; 
        for(int i=0;i<n;++i)cin>>pts[i].first>>pts[i].second;
        // debug();
        ld nowx,nowy,nowr=1e20;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                circle c(pts[i],pts[j]);
                if(circleok(c) && c.r<nowr){
                    nowx=c.x;
                    nowy=c.y;
                    nowr=c.r;
                }
                for(int k=j+1;k<n;++k){
                    circle c=getcircle(pts[i],pts[j],pts[k]);
                    if(circleok(c) && c.r<nowr){
                        nowx=c.x;
                        nowy=c.y;
                        nowr=c.r;
                    }
                }
            }
        }
        cout<<fixed<<setprecision(10)<<nowx<<" "<<nowy<<" "<<nowr<<endl;
    }
}
