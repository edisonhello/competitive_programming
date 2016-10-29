#include<cmath>
#include<iostream>
using namespace std;
struct p{int x,y;}a[10005];
int n,tb[10005],ctb;
bool cmp_x(const p &a,const p &b){
    return a.x<b.x;
}
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n,cmp_x);
}
