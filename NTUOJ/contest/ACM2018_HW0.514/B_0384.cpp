#include<bits/stdc++.h>
using namespace std;

#define y1 wehuirfwnsredf

int cnt[100005];
double u[100005],l[100005];
double x1,y1,x2,y2;

bool check(int i,double x,double y){
    double dx1=u[i]-l[i],dy1=y1-y2;
    double dx2=x-l[i],dy2=y-y2;
    if(dx1*dy2-dx2*dy1>0)return 1;
    return 0;
    /* double yd=y2-y1,xd=l[i]-u[i];
    if(yd<0)yd*=-1,xd*=-1;
    if(x*yd-y*xd<u[i]*yd-y1*xd)return 1;
    return 0; */
    /* int h=y-y1;
    double slope=(double)(l[i]-u[i])/hei;
    double xpos=xdelta+u[i]+h*slope;
    PDE(i,h,slope,xpos);
    if(x<xpos)return 1;
    return 0; */
}

int main(){
    int fi=1,n,m; while(cin>>n,n){
        cin>>m>>x1>>y1>>x2>>y2;
        if(!fi)cout<<endl; else fi=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;++i)cin>>u[i]>>l[i];
        while(m--){
            double x,y; cin>>x>>y;
            /* int L=1,R=n+1;
            while(L<R){
                int mid=(L+R)>>1;
                if(check(mid,x,y))R=mid;
                else L=mid+1;
            }
            ++cnt[L-1]; */
            int i;
            for(i=1;i<=n;++i)if(check(i,x,y))break;
            ++cnt[i-1];
        }
        for(int i=0;i<=n;++i){
            cout<<i<<": "<<cnt[i]<<'\n';
        }
    }
}
