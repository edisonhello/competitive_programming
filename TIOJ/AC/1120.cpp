#include<stdio.h>
using namespace std;

int main(){
    int t;
    while(scanf("%d",&t)!=EOF){
        t=t*6%40;
        if(t<=5){
            printf("(%d,5)\n",t+10);
        }
        else if(t<=15){
            printf("(15,%d)\n",t);
        }
        else if(t<=25){
            printf("(%d,15)\n",30-t);
        }
        else if(t<=35){
            printf("(5,%d)\n",40-t);
        }
        else if(t<=40){
            printf("(%d,5)\n",t-30);
        }
    }
}
