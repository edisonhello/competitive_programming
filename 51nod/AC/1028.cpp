#include<bits/stdc++.h>
using namespace std;
#define cplx complex<double>

const int N=262144;

int base;
cplx omg[N+1],a[N],b[N],res[N];
long long val[N];

void fft(cplx *x){
    int sz=0,mask=(N>>1)-1;
    for(int i=base-1;i>=0;--i,sz=(sz<<1)|1,mask>>=1){
        for(int j=0;j<N;++j){
            int front=j>>i,back=j&mask;
            int a=(front&sz)<<1,b=a+1;
            res[j]=x[(a<<i)|back]+x[(b<<i)|back]*omg[front<<i];
        }
        for(int j=0;j<N;++j)x[j]=res[j];
    }
}

int main(){
    while((1<<base)<N)++base;
    for(int i=0;i<=N;++i)omg[i]=exp(2*acos(-1)*i/N*cplx(0,1));

    string s,t; cin>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();++i){
        a[i]=cplx(s[i]-'0',0);
    }
    for(int i=0;i<t.size();++i){
        b[i]=cplx(t[i]-'0',0);
    }
    fft(a); fft(b);
    for(int i=0;i<N;++i)a[i]=a[i]*b[i];
    fft(a);
    reverse(a+1,a+N);
    for(int i=0;i<N;++i)a[i]/=N;
    for(int i=0;i<N;++i){
        val[i]=round(a[i].real());
    }
    for(int i=0;i<N;++i){
        if(val[i]>9){
            val[i+1]+=val[i]/10;
            val[i]%=10;
        }
    }
    bool print=0;
    for(int i=N-1;i>=0;--i){
        if(val[i])print=1;
        if(print)cout<<val[i];
    }
    cout<<endl;
}
