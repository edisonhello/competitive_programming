#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define imnot guagua
using namespace std;

inline int rit(){
    int t=0,key=1;
    char j;
    do{
        j=getchar();
        if(j=='-')key=-1;
    }while((j<'0' || j>'9'));
    do{
        t = t*10+j-'0';
        j=getchar();

    }while((j>='0' && j<='9'));
    return t*key;
}

int main(){
    int n=rit(),m=rit(),k=rit();

    int mp[n]/*|*/[m]/*-*/;
    memset(mp,0,sizeof(mp));

    for(int i=0;i<k;i++){
        int com=rit();
        if(com==1){
            int r=rit(),a=rit();
            for(int i=0;i<m;i++){
                mp[r-1][i]=a;
            }
        }if(com==2){
            int c=rit(),a=rit();
            for(int i=0;i<n;i++){
                mp[i][c-1]=a;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d",mp[i][j]);
            if(j!=m-1)printf(" ");
        }
        printf("\n");
    }
}
