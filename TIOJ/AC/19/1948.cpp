#include<cstdio>
#include<algorithm>
using namespace std;

struct st{
    int x,i;
} a[1000006];
bool cmp_x(const st &a,const st &b){return a.x<b.x;}

int main(){
    int n,l,goL=0,mxd=-1,d=-1,i=0,dir;scanf("%d%d",&n,&l);
    for(;i<n;++i){
        scanf("%d%d",&a[i].x,&dir);
        if(!dir)++goL;
        a[i].i=i;
        if(!dir){
            if(a[i].x>mxd){
                mxd=a[i].x;
                d=0;
            }
        }
        else{
            if(l-a[i].x>mxd){
                mxd=l-a[i].x;
                d=1;
            }
        }
    }
    sort(a,a+n,cmp_x);
    if(!d)printf("%d\n",a[goL-1].i);
    else printf("%d\n",a[goL].i);
}
