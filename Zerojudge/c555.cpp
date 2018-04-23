#include<bits/stdc++.h>
using namespace std;
#define ld long double

ld a[20],b[20];

int main(){
    int n; while(cin>>n){
        for(int i=n;i>=0;--i)cin>>a[i];
        for(int i=n-1;i>=0;--i)b[i]=a[i+1]*(i+1);
        ld x=0,f;
        auto F=[&](ld x){
            ld rt=0,xx=1;
            for(int i=0;i<=n;++i,xx*=x)rt+=xx*a[i];
            return rt;
        };
        auto FF=[&](ld x){
            ld rt=0,xx=1;
            for(int i=0;i<n;++i,xx*=x)rt+=xx*b[i];
            return rt;
        };
        int cnt=0;
        while(abs(f=F(x))>1e-15){
            ++cnt;
            if(cnt>10000)break;
            ld slo=FF(x);
            ld dx=f/slo;
            // cout<<"now x: "<<x<<" "<<f<<" "<<slo<<" "<<dx<<endl;
            x-=dx;
        }
        if(cnt<=10000)cout<<fixed<<setprecision(15)<<x<<endl;
        else for(int i=0;i<=n;++i)cout<<a[i]<<" ";
    }
}
