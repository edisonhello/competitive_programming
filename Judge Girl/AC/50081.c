#include<stdio.h>

int main(){
    int n,m; scanf("%d%d",&n,&m);
    int x=0,y=0,c;
    printf("0\n0\n");
    while(scanf("%d",&c)==1){
        int go=0;
        switch(c%5){
            case 0: break;
            case 1: if(x+c<n)x+=c,go=1; break;
            case 2: if(x-c>=0)x-=c,go=1; break;
            case 3: if(y+c<m)y+=c,go=1; break;
            case 4: if(y-c>=0)y-=c,go=1; break;
        }
        if(go)printf("%d\n%d\n",x,y);
    }
}
