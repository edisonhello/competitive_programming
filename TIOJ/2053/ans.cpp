#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mat vector<vector<long long>>

const ll mod=1000000007;

void open(mat &x){
    x.resize(2);
     x[0].resize(2); x[1].resize(2);
     x[0][0]=x[0][1]=x[1][1]=x[1][0]=0;
}

mat operator*(const mat &a,const mat &b){
    mat rt; open(rt);
    for(int i=0;i<2;++i){
        for(int j=0;j<2;++j){
            for(int k=0;k<2;++k){
                rt[i][j]=(rt[i][j]+a[i][k]*b[k][j]%mod)%mod;
            }
        }
    }
    return rt;
}

mat pw(mat b,int n){
    mat a; open(a); a[0][0]=a[1][1]=1;
    while(n){
        if(n&1)a=a*b;
        b=b*b; n>>=1;
    }
    return a;
}

void p(mat x){
    cout<<"["<<x[0][0]<<" "<<x[0][1]<<", "<<x[1][0]<<" "<<x[1][1]<<"]"<<endl;
}

int main(){
    mat trans;
    open(trans);
    ll x1,x2,a,b,n; cin>>x1>>x2>>a>>b>>n;
    trans[0][0]=b;
    trans[1][0]=a;
    trans[0][1]=1;
    n-=2;
    trans=pw(trans,n);
    // p(trans);
    cout<<(x2*trans[0][0]+x1*trans[1][0])%mod<<endl;
}
