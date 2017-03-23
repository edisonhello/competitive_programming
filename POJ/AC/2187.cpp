#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define int long long
int n;
struct pnt{int x,y;
pnt():x(0),y(0){};
pnt(int xx,int yy):x(xx),y(yy){};} p[54321];
pnt operator-(const pnt &a,const pnt &b){return pnt(b.x-a.x,b.y-a.y);}
int operator^(const pnt &a,const pnt &b){return a.x*b.y-a.y*b.x;} //cross
int operator*(const pnt &a,const pnt &b){return (a-b).x*(a-b).x+(a-b).y*(a-b).y;}
int tb[54321],tbz,rsd;

int dist(int n1,int n2){
    return p[n1]*p[n2];
}
int cross(int t1,int t2,int n1){
    return (p[t2]-p[t1])^(p[n1]-p[t1]);
}
bool cmpx(const pnt &a,const pnt &b){return a.x==b.x?a.y<b.y:a.x<b.x;}

int getBouLiAnswer(){
    int mx=0,mxi=-1,mxj=-1;
    for(int i=0;i<tbz;++i){
        for(int j=i+1;j<tbz;++j){
            if(p[tb[i]]*p[tb[j]]>mx){
                mx=p[tb[i]]*p[tb[j]];
                mxi=i, mxj=j;
            }
        }
    }
    // cout<<mxi<<" "<<mxj<<endl;
    return mx;
}

signed main(){
    // freopen("in","r",stdin);
    // freopen("out","w",stdout);
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
    // cout<<"tbz: "<<tbz<<endl;
    // for(int i=0;i<tbz;++i)cout<<p[tb[i]].x<<" "<<p[tb[i]].y<<endl;
    int lpr=0,rpr=rsd,mx=0;
    // cout<<"rsd: "<<rsd<<endl;
    mx=max(mx,dist(tb[lpr],tb[rpr]));
    while(lpr<rsd || rpr<tbz-1){
        // cout<<"lpr: "<<lpr<<" rpr: "<<rpr<<endl;
        if(lpr<rsd && rpr<tbz-1){
            pnt rvt=p[tb[rpr+1]]-p[tb[rpr]];
            pnt lvt=p[tb[lpr+1]]-p[tb[lpr]];
            // cout<<(lvt^rvt)<<endl;
            if((lvt^rvt)<0)++lpr;
            else ++rpr;
        }
        else if(lpr==rsd)++rpr;
        else ++lpr;
        mx=max(mx,dist(tb[lpr],tb[rpr]));
    }
    cout<<mx<<endl;
    // cout<<getBouLiAnswer()<<endl;
}
