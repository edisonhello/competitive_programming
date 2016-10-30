#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct p{int x,y;}a[10005];
int n,tb[10005],ctb;
bool cmp_x(const p &a,const p &b){
    return a.x<b.x;
}
int cross(int i,int j,int k){
    return (a[i].x-a[j].x)*(a[i].y-a[k].y)-(a[i].x-a[k].x)*(a[i].y-a[j].y);
}
int ca(int i,int j){
    return a[i].x*a[j].y-a[i].y*a[j].x;
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n,cmp_x);
    // cout<<endl;
    // for(int i=0;i<n;++i){
    //     cout<<a[i].x<<" "<<a[i].y<<endl;
    // }cout<<endl;
    for(int i=0;i<n;++i){
        while(ctb>1 && cross(tb[ctb-1],i,tb[ctb-2])>0)--ctb;
        tb[ctb++]=i;
    }
    for(int i=n-2,t=ctb;i>=0;--i){
        while(ctb>t && cross(tb[ctb-1],i,tb[ctb-2])>0)--ctb;
        tb[ctb++]=i;
    }
    // for(int i=0;i<ctb;++i){
    //     cout<<tb[i]<< ' ';
    // }cout<<endl;
    // cout<<ctb<<endl;
    int area=0;
    for(int i=1;i<ctb;++i){
        area+=ca(tb[i],tb[i-1]);
    }
    cout<<((area+1)>>1)<<endl;
}
