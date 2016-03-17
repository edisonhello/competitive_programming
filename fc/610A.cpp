#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n%2==1){printf("0\n");return 0;}
    n/=2;
    n--;
    n/=2;

    printf("%d\n",n);


}
