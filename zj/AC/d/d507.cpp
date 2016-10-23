#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[3];cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])cout<<"acute triangle\n";
    if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])cout<<"right triangle\n";
    if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])cout<<"obtuse triangle\n";

}
