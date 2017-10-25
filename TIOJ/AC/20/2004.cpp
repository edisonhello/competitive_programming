#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;

int _C[2006][2006];
void init(){
    _C[0][0]=1;
    for(int i=1;i<2006;++i){
        for(int j=0;j<=i;++j){
            _C[i][j]=_C[i-1][j];
            if(j)_C[i][j]+=_C[i-1][j-1];
            _C[i][j]%=mod;
        }
    }
}
inline int C(int i,int j){
    // cout<<i<<" "<<j<<" "<<_C[i][j]<<endl;
    return _C[i][j];   
}
int add(int a,int b,int mod=mod){
    return (a+b)%mod;
}
int mul(int a,int b,int mod=mod){
    int rt=0;
    while(b){
        if(b&1)rt=add(rt,a);
        a=add(a,a); b>>=1;
    } return rt;
}
int pw(int b,int n,int mod=mod){
    int a=1;
    while(n){
        if(n&1)a=mul(a,b);
        b=mul(b,b); n>>=1;
    } return a;
}
int main(){
    init();
    int ts; cin>>ts; while(ts--){
        int n; cin>>n;
        cout<<pw(4,n-1)<<endl;
        continue;
        int ans=0;
        for(int i=0;i<=n-1;++i){
            ans=add(ans,mul(C(2*i,i),C(2*(n-i-1),n-i-1)));
        }
        cout<<ans<<endl;
    }
}
