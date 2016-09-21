#include<bits/stdc++.h>
#include"lib1617.h"
using namespace std;

int n;
int a[1522],Med[1534];

// int Med3(int a,int b,int c){
//     return 0;
// }
// int Get_Box(){
//     return 1;
// }
// void Report(int a){
//     return;
// }

bool comp(int i,int j){
    if(i==j)return 0;
    if(i==1 && j==2)return 0;
    if(i==2 && j==1)return 1;
    if(i==1){
        int m = Med[j];
        if(m==1)return 1;
        else return 0;
    }
    if(i==2){
        int m = Med[j];
        if(m==2)return 0;
        else return 1;
    }
    if(j==1){
        int m = Med[i];
        if(m==1)return 1;
        else return 0;
    }
    if(j==2){
        int m = Med[i];
        if(m==2)return 0;
        else return 1;
    }
    int mi = Med[i];
    int mj = Med[j];
    if(mi==1 && mj==1){
        int m = Med3(1,i,j);
        if(m==i)return 1;
        else return 0;
    }
    if(mi==1 && mj==2){
        return 0;
    }
    if(mi==1 && mj==j){
        return 0;
    }
    if(mi==2 && mj==1){
        return 1;
    }
    if(mi==2 && mj==2){
        int m = Med3(2,i,j);
        if(m==i)return 0;
        else return 1;
    }
    if(mi==2 && mj==j){
        return 1;
    }
    if(mi==i && mj==1){
        return 1;
    }
    if(mi==i && mj==2){
        return 0;
    }
    if(mi==i && mj==j){
        int m = Med3(1,i,j);
        if(m==i)return 0;
        else return 1;
    }
}

int main(){
    n=Get_Box();
    if(n==1)Report(1);
    if(n==3)Report(Med3(1,2,3));
    for(int i=1;i<=n;i++){
        a[i]=i;
        if(i>=3){
            Med[i]=Med3(1,2,i);
        }
    }
    nth_element(a+1,a+1+(n)/2,a+1+n,comp);
    Report(a[(n+1)/2]);
}
