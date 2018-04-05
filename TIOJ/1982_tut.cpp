#include<bits/stdc++.h>
using namespace std;

#define cplx complex<long double>

cplx gcd(cplx a,cplx b){
    while(abs(b)>1e-8){
        cplx c=a/b;
        c.real(round(c.real()));
        c.imag(round(c.imag()));
        a-=b*c;
        swap(a,b);
    }
    return a;
}

int main(){
    cplx ans;
    for(int i=0;i<6;++i){
        long double a,b; cin>>a>>b;
        cplx nw(a,b);
        if(i)ans=gcd(ans,nw);
        else ans=nw;
    }
    cout<<(long long)abs(round(ans.real()))+abs(round(ans.imag()))<<endl;
}
