#include<bits/stdc++.h>
using namespace std;
#define cplx complex<double>

const int N=524288;
cplx a[524288],b[524288],r[524288],o[524288];
const double PI=acos(-1);
int base;

void fft(cplx *x){
    int mask=(N>>1)-1,size=0;
    for(int i=base-1;i>=0;--i,mask>>=1,size=size*2+1){
        for(int j=0;j<N;++j){
            int front=j>>i,back=j&mask;
            int a=(front&size)<<1,b=a+1;
            r[j]=x[(a<<i)|back]+x[(b<<i)|back]*o[front<<i];
        }
        for(int j=0;j<N;++j)x[j]=r[j];
    }
}

void ifft(cplx *x){
    fft(x);
    reverse(x+1,x+N);
    for(int i=0;i<N;++i)x[i]/=N;
}

int main(){
    while((1<<base)<N)++base;
    for(int i=0;i<N;++i)o[i]=exp(2*PI*i/N*cplx(0,1));
    string s,t; cin>>s>>t;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    for(int i=0;i<s.size();++i)a[i]=cplx(s[i]-'0',0);
    for(int i=0;i<t.size();++i)b[i]=cplx(t[i]-'0',0);
    fft(a); fft(b);
    for(int i=0;i<N;++i)a[i]*=b[i];
    ifft(a);
    int jin=0;
    stack<int> an;
    for(int i=0;i<N;++i){
        int t=int(real(a[i])+0.5);
        t+=jin;
        jin=t/10;
        an.push(t%10);
    }
    while(an.top()==0)an.pop();
    while(an.size()){
        cout<<an.top();
        an.pop();
    }
    cout<<endl;
}
