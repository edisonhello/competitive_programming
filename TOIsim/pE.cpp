#include<iostream>
#include<algorithm>
#include<assert.h>
using namespace std;
#define ll long long
int main(){
    ll m,n;cin>>m>>n;
    ll g=__gcd(m,n);
    ll l=m*n/g;
    ll M=m/g,N=n/g;
    if((M&1) && (N&1)){
        cout<<"B\n";
    }
    else if(M&1){
        cout<<"A\n";
    }
    else if(N&1){
        cout<<"C\n";
    }
    else{
        assert(1==0);
    }
    cout<<l/m+l/n-2<<endl;
    cout<<l<<endl;
    // cout<<m<<" "<<n<<" "<<g<<" "<<l<<" "<<M<<" "<<N<<endl;
}
/* 1 submit 1 AC */
