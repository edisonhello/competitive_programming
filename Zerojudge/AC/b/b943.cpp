#include<bits/stdc++.h>
using namespace std;
#define cplx complex<double>
#define ld double

int main(){
    int t; while(cin>>t,t){
        cout<<fixed<<setprecision(6);
        ld a,b,c,d; cin>>a>>b>>c>>d;
        cplx z(a,b),x(c,d);
        cplx q;
        if(t==1)q=pow(z,x);
        else q=log(x)/log(z);
        q.real(q.real()+1e-10);
        cout<<q.real()<<" "<<(q.imag()<-1e-7?"-":"+")<<" "<<abs(q.imag())<<"i"<<endl;
    }
}
