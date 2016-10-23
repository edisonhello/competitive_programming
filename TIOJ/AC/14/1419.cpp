#include<bits/stdc++.h>
using namespace std;
int n;
struct pnt{int x,y,h;} a[100005];
bool cmp_d(const pnt &a,const pnt &b){return a.x*a.x+a.y*a.y<b.x*b.x+b.y*b.y;}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x>>a[i].y>>a[i].h;
    }
    sort(a,a+n,cmp_d);
    int mxh=a[0].h,mx=0;
    for(int i=1;i<n;++i){
        mx=max(mx,mxh-a[i].h);
        mxh=max(mxh,a[i].h);
    }
    cout<<mx<<'\n';
}
