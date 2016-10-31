#include<stdio.h>
#define ll long long
using namespace std;
int n,m,q,l;
ll a[155][155],ans[155][155],tmp[155][155];
const ll M=1000000009;
inline void __(int type){
    if(type==1){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                tmp[i][j]=0;
                for(int k=0;k<n;++k){
                    tmp[i][j]+=a[i][k]*ans[k][j];
                    while(tmp[i][j]>M)tmp[i][j]%=M;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                ans[i][j]=tmp[i][j];
            }
        }
    }
    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                tmp[i][j]=0;
                for(int k=0;k<n;++k){
                    tmp[i][j]+=a[i][k]*a[k][j];
                    while(tmp[i][j]>M)tmp[i][j]%=M;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                a[i][j]=tmp[i][j];
            }
        }
    }
}
int _t;char _c;
inline int rit(){
    _t=0;
    do{
        _c=getchar();
    }while(_c<'0'||_c>'9');
    do{
        _t=_t*10+_c-'0';
        _c=getchar();
    }while(_c<='9'&&_c>='0');
    return _t;
}
int main(){
    n=rit(),m=rit(),q=rit(),l=rit();
    int s,e;
    do{
        s=rit(),e=rit();
        ++a[s][e];
    }while(--m);
    for(int i=0;i<n;++i){
        ans[i][i]=1;
    }
    while(l){
        if(l&1)__(1);
        __(2);
        l>>=1;
    }
    do{
        s=rit(),e=rit();
        printf("%lld\n",ans[s][e]);
    }while(--q);
}
