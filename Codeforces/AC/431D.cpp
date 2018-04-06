#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<222> ex[222];
long long C[222][222];

int main(){
    C[0][0]=1;
    for(int i=1;i<222;++i){
        for(int j=0;j<=i;++j){
            C[i][j]=C[i-1][j];
            if(j)C[i][j]+=C[i-1][j-1];
            if(C[i][j]>1000000000000000000ll || ex[i-1][j] || (j && ex[i-1][j-1]))ex[i][j]=1;
        }
    }

    ll m,k; cin>>m>>k;
    if(m==k && m==1)return cout<<1<<endl,0;
    ll val=0;
    --k;
    for(int i=62;i>=1;--i){
        if(ex[i-1][k] || C[i-1][k]>=m)continue;
        m-=C[i-1][k];
        val^=(1ll<<i);
        --k;
    }
    ++val; ++val;
    cout<<val/2<<endl;
}
