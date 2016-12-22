#include<stdio.h>
using namespace std;

int a[105];

int main(){
    int n,i,t;
    scanf("%d",&n);
    for(i=0;i<n;++i){
        scanf("%d",&t);
        a[t]++;
    }
    for(i=0;i<102;++i){
        if(!a[i])continue;
        do{
            printf("%d ",i);
        }while(--a[i]);
    }
}
