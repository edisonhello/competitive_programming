#include<stdio.h>
int main(){
    int n;scanf("%d",&n);
    int a=1,i;for(i=2;i<=n;i++){
        a*=i;
    }
    printf("%d\n",a);
}
