#include<string>
#include<iostream>
#include<algorithm>
#include<iomanip>
#include<assert.h>
#define int long long
#define GC(a,b) (((a)+(b)<n?s[(a)+(b)]:2))
using namespace std;
struct _{int x,y,n,r;} a[100005];
int n;string s;
bool cN(const _ &a,const _ &b){return a.n<b.n;}
bool cR(const _ &a,const _ &b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool operator!=(const _ &a,const _ &b){return a.x!=b.x||a.y!=b.y;}

void sa(){
    sort(a,a+n,cR);
    a[0].r=1;
    for(int i=1,r=1;i<n;++i){
        if(a[i]!=a[i-1])a[i].r=++r;
        else a[i].r=r;
    }
    for(int i=0;i<n;++i){
        a[i].x=a[i].r;
    }
    sort(a,a+n,cN);
    for(int D=1;D<=n;D<<=1){
        for(int i=0;i<n;++i){
            a[i].y=(i+D<n)?a[i+D].x:2;
        }
        // cout<<"tmpSA: ";for(int i=0;i<n;++i)cout<<"("<<a[i].x<<","<<a[i].y<<") ";cout<<endl;
        sort(a,a+n,cR);
        a[0].r=1;
        for(int i=1,r=1;i<n;++i){
            if(a[i]!=a[i-1])a[i].r=++r;
            else a[i].r=r;
        }
        sort(a,a+n,cN);
    }
    sort(a,a+n,cR);
    for(int i=0;i<n;++i){cout<<a[i].n<<endl;}
    // cout<<"SA: \n";for(int i=0;i<n;++i){cout<<setw(2)<<a[i].n<<" ";for(int j=0;a[i].n+j<n;++j)cout<<s[a[i].n+j];cout<<endl;}
}
int pos[100005],lcpa[100005],lcpl,lcpx;
void lcp(){
    for(int i=0;i<n;++i){
        pos[a[i].n]=i;
    }
    for(int i=0;i<n;++i,--lcpl){
        if(lcpl<0)lcpl=0;
        if(pos[i]==0){
            lcpa[i]=lcpl;
            continue;
        }
        while(a[pos[i]-1].n+lcpl>=n || i+lcpl>=n)--lcpl;
        while(GC(a[pos[i]-1].n,lcpl)==GC(i,lcpl))++lcpl;
        lcpa[i]=lcpl;
        //cout<<"lcpa["<<i<<"]="<<lcpa[i]<<endl;
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
signed main(){
    ios_base::sync_with_stdio(0);
    cin>>s;
    n=(int)s.length();
    for(int i=0;i<n;++i){
        a[i].n=i;
        a[i].x=GC(i,0);
    }
    sa();
    // lcp();
}
