#include<iostream>
#include<iomanip>
#include<cmath>
#define ld long double
using namespace std;
#include<algorithm>
#define m ((l+r)/2)

int n;
const ld eps=1e-11;
ld a[1005],x;

bool eat(ld l){
    ld lf=0;
    for(int i=0;i<n;++i){
        lf+=((a[i]-l)>0?a[i]-l:0);
    }
    if(lf>x)return 1;
    return 0;
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>x;
    ld l=0,r=1000;
    while(r-l>eps){
        if(eat(m))l=m;
        else r=m;
    }
    cout<<fixed<<setprecision(15)<<l<<endl;
}
