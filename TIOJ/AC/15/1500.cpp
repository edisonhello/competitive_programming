#include<cstdio>
#include<algorithm>
#include<cmath>
#define m ((l+r)>>1)
#define ld long double
using namespace std;

struct pnt{int x,y;} a[50005];
bool cmp_x(const pnt &a,const pnt &b){return a.x<b.x;}

ld d(int i,int j){
    return sqrt(((ld)a[i].x-(ld)a[j].x)*((ld)a[i].x-(ld)a[j].x)+((ld)a[i].y-(ld)a[j].y)*((ld)a[i].y-(ld)a[j].y));
}
ld fj(int l,int r){
    if(l==r)return (ld)(9999999999999ll);
    ld mn=min({fj(l,m),fj(m+1,r)});
    int ll=m,rr=m+1;
    while(ll>l && (ld)(a[m].x-a[ll].x)<mn)--ll;
    while(rr<r && (ld)(a[rr].x-a[m+1].x)<mn)++rr;
    for(int i=ll;i<=m;++i){
        for(int j=m+1;j<=rr;++j){
            mn=min({mn,d(i,j)});
        }
    }
    return mn;
}

int main(){
    int n;while(~scanf("%d",&n)){
        for(int i=0;i<n;++i)scanf("%d%d",&a[i].x,&a[i].y);
        sort(a,a+n,cmp_x);
        printf("%.6llf\n",fj(0,n-1));
    }
}
