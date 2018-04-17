#include<bits/stdc++.h>
using namespace std;

struct pnt{
    double x,y;
    int i,type;
} a[20004];

int match[10004];
int proc[10004];

const double PI=acos(-1);

inline double grad(const pnt &a,const pnt &b){return atan2(a.y-b.y,a.x-b.x);}

void solve(int l,int r){
    if(l>r)return;
    if(r-l==1){
        if(a[l].type==a[r].type)exit(1123);
        if(a[l].type==1)match[a[l].i]=a[r].i;
        else match[a[r].i]=a[l].i;
        return;
    }
    // cout<<"solve "<<l<<" "<<r<<" : ";
    // for(int i=l;i<=r;++i)cout<<"("<<a[i].type<<":"<<a[i].i<<")";
    // cout<<endl;
    /* double theta=(double)rand()/RAND_MAX*2*PI;
    double ct=cos(theta),st=sin(theta);
    for(int i=l;i<=r;++i)tie(a[i].x,a[i].y)=make_pair(a[i].x*ct+a[i].y*st,-a[i].x*st+a[i].y*ct); */
    double lowest=1e10;
    for(int i=l;i<=r;++i)lowest=min(lowest,a[i].y);
    for(int i=l+1;i<=r;++i)if(lowest==a[i].y){swap(a[i],a[l]); break;}
    sort(a+l+1,a+r+1,[&](const pnt &x,const pnt &y){return (x.x-a[l].x)*(y.y-a[l].y)-(x.y-a[l].y)*(y.x-a[l].x)>0;});
    // cout<<"solve "<<l<<" "<<r<<" : ";
    // for(int i=l;i<=r;++i)cout<<"("<<a[i].type<<":"<<a[i].i<<")";
    // cout<<endl;
    if(a[l].type!=a[l+1].type){
        solve(l,l+1);
        solve(l+2,r);
        return;
    }
    int start=max(l,(r+l)/3);
    int cut=r;
    int cnt=0;
    for(int i=l+1;i<=r;++i){
        if(a[i].type==a[l].type)++cnt;
        else --cnt;
        if(cnt==-1){
            cut=i;
            break;
        }
    }
    // cout<<"go solve, cut on "<<cut<<endl;
    swap(a[l+1],a[cut]);
    solve(l,l+1);
    solve(l+2,cut);
    solve(cut+1,r);
}

int main(){
    srand(time(0));
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y,a[i].i=i,a[i].type=1;
    for(int i=0;i<n;++i)cin>>a[i+n].x>>a[i+n].y,a[i+n].i=i,a[i+n].type=2;
    for(int i=0;i<2*n;++i)proc[i]=i;
    solve(0,2*n-1);
    for(int i=0;i<n;++i)cout<<match[i]+1<<'\n';
}
