
#include<complex>
#define cplx complex<ld>

cplx a[131072],b[131072],res[131072],omg[131073];
int N=131072,base;

void init(){
    while(N!=lowbit(N))N+=lowbit(N); N<<=1;
    while((1<<base)<N)++base;
    for(int i=0;i<=N;++i)omg[i]=exp(i*2*PI/N*cplx(0,1));
}
void FFT(cplx *x){
    int size=0,mask=(N>>1)-1;
    for(int i=base-1;i>=0;--i,size=(size<<1)|1,mask>>=1){
        for(int j=0;j<N;++j){
            int front=j>>i,back=j&mask;
            int a=(front&size)<<1,b=a|1;
            res[j]=x[(a<<i)|back]+omg[front<<i]*x[(b<<i)|back];
        }
        for(int j=0;j<N;++j)x[j]=res[j];
    }
}
void IFFT(cplx *a){
    FFT(a);
    reverse(a+1,a+N);
    for(int i=0;i<N;++i)a[i]/=N;
}

void calc(){
    FFT(a), FFT(b);
    for(int i=0;i<N;++i)a[i]*=b[i];
    IFFT(a);
}
