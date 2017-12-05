#include<cstdio>
#include<vector>
using namespace std;

const long long mod=1000000007;
const long long inv2=500000004;

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
        if(x==1)setI();
        else if(x==0)setO();
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

// pre(Fi^2)=Fi*F(i+1), pre(Fi)=F(i+1)-1

#define norm(x) ((x%mod+mod)%mod)

mat<long long,2> fib(0);

#define F(x) pw(fib,(x)-1)[0][0]

inline long long get(long long x){
    if(x==0)return 0;
    return ((F(x)*F(x+1)%mod-(F(x+2)-1))%mod+mod)*inv2%mod;
}

int main(){
    fib[0][0]=fib[0][1]=fib[1][0]=1;
    scanf("%*s"); long long s,t; while(~scanf("%lld%lld",&s,&t)){
        printf("%d\n",norm(get(t)-get(s-1)));
    }
}
