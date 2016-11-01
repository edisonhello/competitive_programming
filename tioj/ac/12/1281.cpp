#include<iostream>
#include<algorithm>
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
        if(a[i].x>a[i-1].x||(a[i].x==a[i-1].x&&a[i].y>a[i-1].y))a[i].r=++r;
        else a[i].r=r;
    }
    for(int D=1;D<=n;D<<=1){
        sort(a,a+n,cN);
        for(int i=n-1;i>=0;--i){
            a[i].x=a[i].r;
            a[i].y=(i+D<n?a[i+D].x:0);
        }
        sort(a,a+n,cX);
        a[0].r=1;
        for(int i=1,r=1;i<n;++i){
            if(a[i].x>a[i-1].x||(a[i].x==a[i-1].x&&a[i].y>a[i-1].y))a[i].r=++r;
            else a[i].r=r;
        }
    }
    /*for(int i=0;i<n;++i){
        cout<<a[i].n<<endl;
    }*/
}
int pos[100005],lcpa[100005],lcpl,lcpx;
void lcp(){
    for(int i=0;i<n;++i){
        pos[a[i].n]=i;
    }
    for(int i=0;i<n;++i,--lcpl){
        if(pos[i]==0)continue;
        if(lcpl<0)lcpl=0;
        while(a[pos[i]].n+lcpl>=n||a[pos[i]-1].n+lcpl>=n)--lcpl;
        while(a[pos[i]].n+lcpl<n&&a[pos[i]-1].n+lcpl<n&&s[a[pos[i]].n+lcpl]==s[a[pos[i]-1].n+lcpl])++lcpl;
        lcpa[i]=lcpl;
        lcpx=max({lcpx,lcpl});
    }
    for(int i=0;i<n;++i){
        if(lcpa[i]==lcpx){
            for(int j=0;j<lcpx;++j){
                cout<<s[i+j];
            }
            cout<<endl;
            return;
        }
    }
}
int main(){
    getline(cin,s);
    n=(int)s.length();
    sa();
    lcp();
}
