#include<stdio.h>
#define M (L+R)>>1

long long a[]={1,4,67,890,1234,56789,1234567,890123456},N;

int lower_bound(int x){
    int L=1,R=N;
    while(R>L){
        if(a[M]>=x)R=M;
        else L=M;
    }
    return L;
}

int main(){
    N=sizeof(a)/sizeof(long long);
    long long q[]={1,2,4,67,891,1235,56765,1234567,890123456};
    int qN=sizeof(q)/sizeof(long long);

    for(int i=0;i<qN;++i){
        printf("lowerbound of %d: %d\n",q[i],lower_bound(q[i]));
    }
}
