#include<assert.h>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
#define m ((l+r)>>1)

struct rect{int x,d,u;int t;} a[200005];
bool cmp_x(const rect &a,const rect &b){return a.x<b.x;}

struct node{int v,tg;} sg[4000005];
int modify(int id,int l,int r,int &ml,int &mr,int &v){
    if(r<ml || mr<l)return sg[id].tg?r-l+1:sg[id].v;
    if(ml<=l&&r<=mr){
        sg[id].tg+=v;
        return sg[id].tg?r-l+1:sg[id].v;
    }
    sg[id].v=modify(id*2,l,m,ml,mr,v)+modify(id*2+1,m+1,r,ml,mr,v);
    return sg[id].tg?r-l+1:sg[id].v;
}

int main(){
    int n; scanf("%d",&n);
    for(int i=0,l,r,d,u;i<n;++i){
        scanf("%d%d%d%d",&l,&r,&d,&u);
        a[2*i]={l,d,u-1,1};
        a[2*i+1]={r,d,u-1,-1};
    }
    sort(a,a+2*n,cmp_x);
    ll totArea=0;int b4; b4=modify(1,0,1000000,a[0].d,a[0].u,a[0].t);
    for(int i=1;i<(n<<1);++i){
        totArea += (ll)(a[i].x-a[i-1].x)*b4;
        b4=modify(1,0,1000000,a[i].d,a[i].u,a[i].t);
    }
    printf("%lld\n",totArea);
}
