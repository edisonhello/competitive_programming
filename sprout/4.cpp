#include<bits/stdc++.h>

using namespace std;

int sv[3165];


inline bool isprime(int a){
    for(int i=0;sv[i]*sv[i]<=a;i++){
        if(a%sv[i]==0){
            return 0;
        }
    }
    return 1;
}

inline void make(){
    sv[0]=2;
    sv[1]=3;
    sv[2]=5;
    sv[3]=7;
    int n=4;
    for(int i=11;i*i<10000100 && n<3165;i+=10){
        if(isprime(i)){sv[n++]=i;}
        if(isprime(i+2)){sv[n++]=i+2;}
        if(isprime(i+6)){sv[n++]=i+6;}
        if(isprime(i+8)){sv[n++]=i+8;}
    }
}


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


int main(){
    make();

    int n=rit();  //  cout<<n;
    while(n--){
        int tmp=rit();
        if(isprime(tmp) && tmp!=1){
            printf("yes\n");
        }
        else{
            printf("no\n");
        }
    }


}
