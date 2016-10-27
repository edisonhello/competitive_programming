#include<cstdio>
#include<cmath>
#define ld long double
using namespace std;
ld x,y,r;
int main(){
    while(scanf("%llf%llf%llf",&x,&y,&r)!=EOF){
        if(y<=-r){
            printf("0.00\n");
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
            continue;
        }
        if(y<0){
            printf("%.2llf\n",
                r*r*0.5*2*acos(-y/r)+
                sqrt(r*r-y*y)*y
            );
        }
    }
}
