#include<bits/stdc++.h>
using namespace std;
#define cplx complex<double>

int base;
const int N=524288;
cplx a[524288],b[524288],r[524288],o[524288];

void fft(cplx *x){
    int size=0,mask=(1<<(base-1))-1;
    // int size=0,mask=(N>>1)-1;
    for(int i=base-1;i>=0;--i,size=(size<<1)|1,mask>>=1){
        for(int j=0;j<N;++j){
            int front=(j>>i),back=j&mask;
            int a=(front&size)<<1,b=a|1;
            r[j]=x[(a<<i)|back]+o[front<<i]*x[(b<<i)|back];
        }
        for(int j=0;j<N;++j)x[j]=r[j];
    }
}
void ifft(cplx *x){
    fft(x);
    reverse(x+1,x+N);
    for(int i=0;i<N;++i)x[i]/=N;
}

int cnt[550005],delta[550005];

int main(){
    double pi=acos(-1);
    for(int i=0;i<524288;++i)o[i]=exp(2*pi*i/N*cplx(0,1));
    while((1<<base)<N)++base;
    int sl,tl,k; cin>>sl>>tl>>k;
    string s,t; cin>>s>>t;
    reverse(t.begin(),t.end());
    vector<char> meow({'T','A','G','C'});
    // cout<<s<<" "<<t<<endl;
    for(char c:meow){
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<tl;++i)a[i]=cplx(t[i]==c,0);
        memset(delta,0,sizeof(delta));
        for(int i=0;i<sl;++i){
            if(s[i]==c)++delta[max(0,i-k)],--delta[i+k+1];
        }
        for(int i=1;i<N;++i)delta[i]+=delta[i-1];
        for(int i=0;i<N;++i)b[i]=cplx(!!delta[i],0);

        // cout<<"now a: "; for(int i=0;i<15;++i)cout<<a[i].real()<<" "; cout<<endl;
        // cout<<"now b: "; for(int i=0;i<15;++i)cout<<b[i].real()<<" "; cout<<endl;
        // cout<<"now d: "; for(int i=0;i<15;++i)cout<<delta[i]<<" "; cout<<endl;
        fft(a); fft(b);
        for(int i=0;i<N;++i)a[i]*=b[i];
        ifft(a);
        for(int i=0;i<N;++i)cnt[i]+=int(a[i].real()+0.5);
        // cout<<"now a: "; for(int i=0;i<15;++i)cout<<int(a[i].real()+0.5)<<" "; cout<<endl;
        // cout<<"now c: "; for(int i=0;i<15;++i)cout<<cnt[i]<<" "; cout<<endl;
    }
    int ans=0;
    for(int i=0;i<sl;++i)ans+=(cnt[i]==tl);
    cout<<ans<<endl;
}
