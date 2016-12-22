#include<cstdio>
#include<iostream>
#define int long long
using namespace std;

const int Z=1e9+7;

int m,n;

struct mat{
    int a[105][105];
    mat(){
        for(int i=0;i<m;++i)a[i][i]=1;
    }
    mat& operator=(const mat &a){
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j)
                this->a[i][j]=a.a[i][j];
        return *this;
    }
    mat operator*(const mat &a)const{
        mat tmp;
        for(int i=0;i<m;++i){
            for(int j=0;j<m;++j){
                tmp.a[i][j]=0;
                for(int k=0;k<m;++k){
                    tmp.a[i][j]+=this->a[i][k]*a.a[k][j];
                    if(tmp.a[i][j]>=Z)tmp.a[i][j]%=Z;
                }
            }
        }
        return tmp;
    }
};

mat _pow(mat a,int n){
    mat rt;
    while(n){
        if(n&1)rt=rt*a;
        a=a*a;
        n>>=1;
    }
    return rt;
}

signed main(){
    mat tr,li;
    cin>>n>>m;
    if(n<=m){cout<<1<<endl;return 0;}
    for(int i=0;i<m;++i){
        li.a[i][0]=1;
        if(i)tr.a[i][i-1]=1;
        cin>>tr.a[0][i];
    }
    n-=m;
    tr=_pow(tr,n);
    mat ans=tr*li;
    cout<<ans.a[0][0]<<endl;
}
