// POJ 2187 (c++98)
#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define int long long
int n;
struct pnt{
    int x,y;
    pnt():x(0),y(0){};
    pnt(int xx,int yy):x(xx),y(yy){};
} p[54321];
pnt operator-(const pnt &a,const pnt &b){return pnt(b.x-a.x,b.y-a.y);}
int operator^(const pnt &a,const pnt &b){return a.x*b.y-a.y*b.x;} //cross
int operator*(const pnt &a,const pnt &b){return (a-b).x*(a-b).x+(a-b).y*(a-b).y;} // distance
int tb[54321],tbz,rsd;

int dist(int n1,int n2){
    return p[n1]*p[n2];
}
int cross(int t1,int t2,int n1){
    return (p[t2]-p[t1])^(p[n1]-p[t1]);
}
bool cmpx(const pnt &a,const pnt &b){return a.x==b.x?a.y<b.y:a.x<b.x;}

signed main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>p[i].x>>p[i].y;
    sort(p,p+n,cmpx);
    for(int i=0;i<n;++i){
        while(tbz>1 && cross(tb[tbz-2],tb[tbz-1],i)<=0)--tbz;
        tb[tbz++]=i;
    }
    rsd=tbz-1;
    for(int i=n-2;i>=0;--i){
        while(tbz>rsd+1 && cross(tb[tbz-2],tb[tbz-1],i)<=0)--tbz;
        tb[tbz++]=i;
    }
    --tbz;
    int lpr=0,rpr=rsd,mx=0;
    mx=max(mx,dist(tb[lpr],tb[rpr]));
    while(lpr<rsd || rpr<tbz-1){
        if(lpr<rsd && rpr<tbz-1){
            pnt rvt=p[tb[rpr+1]]-p[tb[rpr]];
            pnt lvt=p[tb[lpr+1]]-p[tb[lpr]];
            if((lvt^rvt)<0)++lpr;
            else ++rpr;
        }
        else if(lpr==rsd)++rpr;
        else ++lpr;
        mx=max(mx,dist(tb[lpr],tb[rpr]));
    }
    cout<<mx<<endl;
}
