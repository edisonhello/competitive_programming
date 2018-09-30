#include<stdio.h>
#include<string.h>

char c[15];

int main(){
    int mx=0,now=0;
    char la=0;
    while(scanf("%s",c)==1){
        int l=strlen(c);
        if(l>mx)mx=l;
        if(c[0]!=la)now=l;
        else now+=l;
        if(now>mx)mx=now;
        la=c[l-1];
    }
    printf("%d\n",mx);
}
