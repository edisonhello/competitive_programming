#include<bits/stdc++.h>

int main(){
    int a,b,t;
    scanf("%d%d%d",&a,&b,&t);
    if(abs(a)+abs(b)<=t && (abs(a)+abs(b)-t)%2==0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}
