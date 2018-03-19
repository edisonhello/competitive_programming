#include<bits/stdc++.h>
using namespace std;
#define ld long double
const ld pi=3.1415926535897932384626433854877122878787878787878787;

#define cout cout<<fixed<<setprecision(10)

int main(){
    ld x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    if(r1>r2)swap(r1,r2);
    if(abs(x1-x2)<1e-7 && abs(y1-y2)<1e-7 && abs(r1-r2)<1e-7){
        cout<<r2*r2*pi<<endl;
        exit(0);
    }
    if(sqrt(pow(x2-x1,2)+pow(y2-y1,2))>r1+r2){
        cout<<0<<endl;
        exit(0);
    }
    if(sqrt(pow(x2-x1,2)+pow(y2-y1,2))+r1<r2){
        cout<<r1*r1*pi<<endl;
        exit(0);
    }
    ld d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    ld crr=(r1*r1+r2*r2-d*d)/2/r1/r2;
    ld srr=sqrt(1-crr*crr);
    ld arr2=r1*r2*srr;
    ld hh=arr2/d;
    ld h=hh*2;
    if(r2*r2-r1*r1-d*d<0){
        ld cs1=(r1*r1+r1*r1-h*h)/2/r1/r1;
        ld cs2=(r2*r2+r2*r2-h*h)/2/r2/r2;
        ld ag1=acos(cs1);
        ld ag2=acos(cs2);
        ld ar1=r1*r1*ag1/2-r1*r1*sqrt(1-cs1*cs1)/2;
        ld ar2=r2*r2*ag2/2-r2*r2*sqrt(1-cs2*cs2)/2;
        cout<<ar1+ar2<<endl;
    }
    else{
        ld cs1=(r1*r1+r1*r1-h*h)/2/r1/r1;
        ld cs2=(r2*r2+r2*r2-h*h)/2/r2/r2;
        ld ag1=acos(cs1);
        ld ag2=acos(cs2);
        ld ar1=r1*r1*ag1/2-r1*r1*sqrt(1-cs1*cs1)/2;
        ld ar2=r2*r2*ag2/2-r2*r2*sqrt(1-cs2*cs2)/2;
        cout<<r1*r1*pi-ar1+ar2<<endl;
    }
}
