#include<stdio.h>
#define E else if
#define P printf
int main(){
    short n;
    while(scanf("%d",&n)!=EOF){
        n%=7;
        if(n==0)P("Friday\n");
        E(n==1)P("Saturday\n");
        E(n==2)P("Sunday\n");
        E(n==3)P("Monday\n");
        E(n==4)P("Tuesday\n");
        E(n==5)P("Wednesday\n");
        E(n==6)P("Thursday\n");
    }
}
