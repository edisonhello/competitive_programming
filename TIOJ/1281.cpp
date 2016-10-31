#include<iostream>
using namespace std;
struct _{int r,x,y,n;} a[100005];
bool cX(const _ &a,const _ &b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool cN(const _ &a,const _ &b){return a.n<b.n;}
int n;string s;
void sa(){
    for(int i=0;i<n;++i)a[i].n=i,a[i].x=s[i];
    sort(a,a+n,cX);
    a[0].r=1;
    for(int i=1,r=1;i<n;++i){
        if(a[i].x>a[i-1].x||(a[i].x==a[i-1].x&&a[i].y<a[i-1].y))a[i].r=++r;
        else a[i].r=r;
    }
    sort(a,a+n,cN);
    for(int i=0;i<n;++i){
        a[i].x=a[i].r;
    }
    for(int D=1;D<=n;D<<=1){
        
    }

}
void lcp(){

}
int main(){
    getline(cin,s);
    n=(int)s.length();
    sa();
    lcp();
}
