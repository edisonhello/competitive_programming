#include<stdio.h>
char c1,c2;
int main(){
    int ts;scanf("%d ",&ts);
    while(ts--){
        scanf("%c%c",&c1,&c2);
        if(c1=='1' && c2=='\n')puts("0");
        else{
            while(c2!='\n')c2=getchar();
            puts("1");
        }
    }
}
