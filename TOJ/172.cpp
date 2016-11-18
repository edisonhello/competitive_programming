#include<cmath>
#include<iostream>
#include<cstdio>
#include<iomanip>
#define ld long double
using namespace std;
int main(){
    int a[4];
    while(cin>>a[0]>>a[1]>>a[2]>>a[3]){
        sort(a,a+4);reverse(a,a+4);
        if(a[3]<0 || !a[0]){
            cout<<"Illegal Polygon -1\n";
            continue;
        }
        if(!a[1]&&!a[2]&&!a[3]){
            ld rd=(ld)a[0];
            ld r=ld/acos(-1);
            ld ara=r*r*acos(-1);
            cout<<"Circle "<<fixed<<setprecision(2)<<ara<<endl;
            continue;
        }
        if(!a[2]&&!a[3]){
            ld r=(ld)a[0];
            ld rd=(ld)a[1];
            ld ara=r*r/2*rd/2*acos(-1)*r;
            cout<<"Sector "<<fixed<<setprecision(2)<<ara<<endl;
        }
        if(!a[3]){
            if(a[2]+a[1]<=a[0]){cout<<"Illegal Triangle -1\n";continue;}
            if(a[2]*a[2]+a[1]*a[1]>a[0]*a[0])cout<<"Acute Triangle ";
            else if(a[2]*a[2]+a[1]*a[1]==a[0]*a[0])cout<<"Right Triangle ";
            else if(a[2]*a[2]+a[1]*a[1]<a[0]*a[0])cout<<"Obtuse Triangle ";
        }
    }
}
