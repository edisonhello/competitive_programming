#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct pnt{ll x,y;} a[100005],tb[100005];
bool cmp_y(const pnt &a,const pnt &b){return a.y<b.y;}
inline ll crs(const pnt &o,const pnt &a,const pnt &b){return (o.x-a.x)*(o.y-b.y)-(o.y-a.y)*(o.x-b.x);}
int n;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n,cmp_y);
    int cnt=0;
    // int prv
    for(int i=0;i<n;++i){
        while(cnt>1 && crs(tb[cnt-1],a[i],tb[cnt-2])<=0)--cnt;
        tb[cnt++]=a[i];
    }
    for(int i=n-2,pvc=cnt;i>=0;--i){
        while(cnt>pvc && crs(tb[cnt-1],a[i],tb[cnt-2])<=0)--cnt;
        tb[cnt++]=a[i];
    }
    cout<<cnt-1<<'\n';
}
