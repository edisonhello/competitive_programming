#include<bits/stdc++.h>
#define ld long double
using namespace std;
int main(){
    ld x,y,r;
    while(cin>>x>>y>>r){
        if(y<=-r){
            cout<<"0.00\n";
            continue;
        }
        if(y==0){
            printf("%.2llf\n",r*r*0.5*acos(-1.0));
            continue;
        }
        if(y>=r){
            printf("%.2llf\n",r*r*acos(-1.0));
            continue;
        }
        if(y>0){
            printf("%.2llf\n",
                r*r*0.5*(2*acos(-1.0)-2*acos(y/r))+
                sqrt(r*r-y*y)*y
            );
        }
        if(y<0){
            printf("%.2llf\n",
                r*r*0.5*2*acos(y/r)-
                sqrt(r*r-y*y)*y
            );
        }
    }
}
