#include<stdio.h>

int a[100][100];
int main(){
    int r,c; scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)for(int j=0;j<c;++j)scanf("%d",&a[i][j]);
    for(int j=0;j<c;++j){
        int s=0;
        for(int i=0;i<r;++i){
            s+=a[i][j];
        }
        printf("%d\n",s/r);
    }
}
