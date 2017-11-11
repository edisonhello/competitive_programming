#include<bits/stdc++.h>
using namespace std;

bool mm[14];
long double a[14];
#define lg(x) abs(log(x))
#define _(x,z,c) {a[z]=x; if(c<0)mm[z]=1;}
#define __(x,y) case x: cout<<y<<endl; break;
int main(){
    long double x,y,z,mx=-1e20; cin>>x>>y>>z; int ans=0;
    _(z*log(y)+log(lg(x)),1,log(x))
    _(y*log(z)+log(lg(x)),2,log(x))
    _(log(y*z*lg(x)),3,y*z*log(x))
    _(z*log(x)+log(lg(y)),5,log(y))
    _(x*log(z)+log(lg(y)),6,log(y))
    _(log(x*z*lg(y)),7,x*z*log(y))
    _(y*log(x)+log(lg(z)),9,log(z))
    _(x*log(y)+log(lg(z)),10,log(z))
    _(log(x*y*lg(z)),11,x*y*log(z))
    // for(int i=1;i<=12;++i){
    //     if(i%4==0)continue;
    //     cout<<a[i]<<" "<<mm[i]<<endl;
    // }
    for(int i=1;i<=12;++i){
        if(i%4==0)continue;
        if(mm[i])continue;
        if(a[i]-1e-8>mx){
            mx=a[i];
            ans=i;
        }
    }
    if(!ans){
        mx=1e20;
        for(int i=1;i<=12;++i){
            if(i%4==0)continue;
            if(a[i]+1e-8<mx){
                mx=a[i];
                ans=i;
            }
        }
    }
    switch(ans){
        __(1,"x^y^z");
        __(2,"x^z^y");
        __(3,"(x^y)^z");
        __(5,"y^x^z");
        __(6,"y^z^x");
        __(7,"(y^x)^z");
        __(9,"z^x^y");
        __(10,"z^y^x");
        __(11,"(z^x)^y");
    }
}
