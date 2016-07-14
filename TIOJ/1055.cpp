#include<iostream>

using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a>b){
        for(int i=a;i>=b;i--){
            for(int j=0;j<i;j++){
                putchar('*');
            }
            putchar('\n');
        }
    }
    else{
        for(int i=a;i<=b;i++){
            for(int j=0;j<i;j++){
                putchar('*');
            }
            putchar('\n');
        }
    }
}

