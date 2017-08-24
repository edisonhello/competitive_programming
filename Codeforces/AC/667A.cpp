#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    double d,h,v,e;
    cin>>d>>h>>v>>e;
    double a = (d/2)*(d/2)*(double)3.1415926535897932384626;
    if(v<a*e){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        cout<<"YES"<<endl;
        printf("%.9lf\n",h/((v-a*e)/a));
    }
}
