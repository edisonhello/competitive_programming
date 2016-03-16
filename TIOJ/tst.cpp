#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

inline int rit(){
    int t=0;
    char j;
    do{j=getchar();}while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t;
}
int a[5][5];

int main(){

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<a[i][j];
        }
    }
}
