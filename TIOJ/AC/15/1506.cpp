#include<bits/stdc++.h>
using namespace std;
int main(){
    double a1,b1,a2,b2;
    cin>>a1>>a2>>b1>>b2;
                         //a1x-y=-b1
                         //a2x-y=-b2
    double delta=-a1+a2;
    double dx=b1-b2;
    double dy=-a1*b2+a2*b1;
    printf("%.2lf\n%.2lf\n",dx/delta,dy/delta);
}
