#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

ll c[5555][5555];


int main(){
    c[0][0]=1;
    for(int i=1;i<5555;++i){
        for(int j=0;j<=i;++j){
            c[i][j]=(c[i-1][j]+(j?c[i-1][j-1]:0ll))%mod;
        }
    }
    int n,m,k; cin>>n>>m>>k;
    if(2*k>n-1 || 2*k>m-1)cout<<0<<endl;
    else cout<<c[n-1][k<<1]*c[m-1][k<<1]%mod<<endl;
}
