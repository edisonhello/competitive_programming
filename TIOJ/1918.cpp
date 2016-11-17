#include<iostream>
#include<algorithm>
#define ull unsigned ll
#define ll long long
#define m (l+r)/2
using namespace std;
struct P{ll x,y,z;} a[100005];
bool cmpx(const P &lhs,const P &rhs){return lhs.x<rhs.x;}
ull dist(const int i,const int j){
    return (ull)((a[i].x-a[j].x)*(a[i].x-a[j].x))+(ull)((a[i].y-a[j].y)*(a[i].y-a[j].y))+(ull)((a[i].z-a[j].z)*(a[i].z-a[j].z));
}
ull distx(const int i,const int j){
    return (ull)((a[i].x-a[j].x)*(a[i].x-a[j].x));
}

int n;

ull DC(int l,int r){
    //cout<<"going DC "<<l<<" "<<r<<endl;
    if(l==r)return -1;
    if(r==l+1)return dist(l,r);
    ull aa=min(DC(l,m),DC(m+1,r));
    int lll=m,rrr=m+1;
    while(lll>=l && distx(m,lll)<aa){lll--;}lll++;
    while(rrr<=r && distx(m+1,rrr)<aa){rrr++;}rrr--;
    //cout<<lll<<" "<<rrr<<endl;
    for(int i=lll;i<=m;++i){
        for(int j=m+1;j<=rrr;++j){
            aa=min(aa,dist(i,j));
        }
    }
    return aa;
}
void sol(){
    cout<<DC(0,n-1)<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a,a+n,cmpx);
    sol();
}
