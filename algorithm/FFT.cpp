
struct cplx{
    double r,i;
    cplx(double r=0,double i=0):r(r),i(i){}
    void exp(double ang){ r=cos(ang); i=sin(ang); }
};
cplx operator+(const cplx &a,const cplx &b){ return cplx(a.r+b.r,a.i+b.i); }
cplx operator-(const cplx &a,const cplx &b){ return cplx(a.r-b.r,a.i-b.i); }
cplx operator*(const cplx &a,const cplx &b){ return cplx(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r); }
cplx& operator*=(cplx &a,const double x){ a.r*=x; a.i*=x; return a; }
cplx& operator*=(cplx &a,const cplx &b){ double tmp=a.r*b.r-a.i*b.i; a.i=a.r*b.i+a.i*b.r; a.r=tmp; return a; }
cplx operator/(const cplx &a,const double x){ return cplx(a.r/x,a.i/x); }
cplx& operator/=(cplx &a,const double x){ a.r/=x; a.i/=x; return a; }

cplx a[131072],b[131072],res[131072],omg[131072];
int N=131072,base;

void init(){
    while(N!=lowbit(N))N+=lowbit(N);
    while((1<<base)<N)++base;
    for(int i=0;i<N;++i)omg[i]=exp(i*2*PI/N*cplx(0,1));
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
