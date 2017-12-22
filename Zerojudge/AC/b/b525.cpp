#include<bits/stdc++.h>
using namespace std;

const long long mod=100000007;
template<typename T,int I>struct raw{
    vector<T> d;
    raw(){d.resize(I);}
    T& operator[](int id){return d[id];}
    const T& operator[](int id)const{return d[id];}
};
template<typename T,int I>struct mat{
    vector<raw<T,I>> r;
    mat(int x=0){
        r.resize(I);
        if(x)setI();
        else setO();
    }
    raw<T,I>& operator[](int id){return r[id];}
    const raw<T,I>& operator[](int id)const{return r[id];}
    void setI(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=(i==j);}
    void setO(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=0;}
};
template<typename T,int I>mat<T,I> operator*(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)for(int k=0;k<I;++k)rt[i][j]=(rt[i][j]+a[i][k]*b[k][j])%mod;
    return rt;
}
template<typename T,int I>mat<T,I> operator+(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)rt[i][j]=(a[i][j]+b[i][j])%mod;
    return rt;
}
template<typename T,int I>mat<T,I> pw(mat<T,I> b,long long n,mat<T,I> a=mat<T,I>(1)){
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } return a;
}
template<typename T,int I>ostream& operator<<(ostream &ostm,const raw<T,I> &r){ostm<<"["; for(int i=0;i<I;++i)ostm<<r[i]<<(i==I-1?"]":", "); return ostm;}
template<typename T,int I>ostream& operator<<(ostream &ostm,const mat<T,I> &m){ostm<<"\n["; for(int i=0;i<I;++i)ostm<<m[i]<<(i==I-1?"]\n":",\n "); return ostm;}

int main(){
    int m,f,k; while(cin>>m>>f>>k){
        // if(k==1){cout<<m+f<<endl; continue;}
        mat<long long,2> base; base[0][0]=base[0][1]=base[1][0]=1; base[1][1]=0;
        base=pw(base,k);
        cout<<((f*(base[0][0]+base[1][0])+m*(base[0][1]+base[1][1]))%mod)<<endl;
    }
}
