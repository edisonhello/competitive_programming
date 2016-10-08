#include<stdio.h>
int main(){
    int n;
    int a[103];
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",a+i);
            for(int j=0;j<i;j++){
                if(a[j]>a[i])ans++;
            }
        }
        printf("%d\n",ans);
    }
}
