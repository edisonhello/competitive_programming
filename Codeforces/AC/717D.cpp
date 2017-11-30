#include<bits/stdc++.h>
using namespace std;

template<typename T,int I>struct raw{
    vector<T> d;
    raw(){d.resize(I);}
    T& operator[](int id){return d[id];}
    const T& operator[](int id)const{return d[id];}
};
template<typename T,int I>struct mat{
    vector<raw<T,I>> r;
    mat(){r.resize(I);}
    raw<T,I>& operator[](int id){return r[id];}
    const raw<T,I>& operator[](int id)const{return r[id];}
    void setI(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=(i==j);}
    void setO(){for(int i=0;i<I;++i)for(int j=0;j<I;++j)r[i][j]=0;}
};
template<typename T,int I>mat<T,I> operator*(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)for(int k=0;k<I;++k)rt[i][j]+=a[i][k]*b[k][j];
    return rt;
}
template<typename T,int I>mat<T,I> operator+(const mat<T,I> &a,const mat<T,I> &b){
    mat<T,I> rt;
    for(int i=0;i<I;++i)for(int j=0;j<I;++j)rt[i][j]=a[i][j]+b[i][j];
    return rt;
}
template<typename T,int I>ostream& operator<<(ostream &ostm,const raw<T,I> &r){ostm<<"["; for(int i=0;i<I;++i)ostm<<r[i]<<(i==I-1?"]":", "); return ostm;}
template<typename T,int I>ostream& operator<<(ostream &ostm,const mat<T,I> &m){ostm<<"\n["; for(int i=0;i<I;++i)ostm<<m[i]<<(i==I-1?"]\n":",\n "); return ostm;}

template<typename T,int I>mat<T,I> pw(mat<T,I> b,int n){
    mat<T,I> a; a.setI(); while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    } return a;
}

long double poss[128];
int main(){
    mat<long double,128> trans;
    int n,x; cin>>n>>x;
    for(int i=0;i<=x;++i)cin>>poss[i];
    for(int i=0;i<128;++i){
        for(int j=0;j<128;++j){
            trans[i][j]=poss[i^j];
        }
    }
    trans=pw(trans,n);
    long double ans=0;
    for(int i=1;i<128;++i)ans+=trans[0][i];
    cout<<fixed<<setprecision(21)<<ans<<endl;
}
