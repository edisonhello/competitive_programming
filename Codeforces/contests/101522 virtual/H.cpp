#include<bits/stdc++.h>
using namespace std;
#define ld long double

ld med(ld l,ld r,ld a,ld b){
    return l*b/(a+b)+r*a/(a+b);
}

int main(){
    ld x1,y1,r1,x2,y2,r2; cin>>x1>>y1>>r1>>x2>>y2>>r2;
    cout<<fixed<<setprecision(12)<<med(x1,x2,r1,r2)<<" "<<med(y1,y2,r1,r2)<<endl;
}
