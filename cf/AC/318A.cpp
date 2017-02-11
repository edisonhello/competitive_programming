#include<iostream>
#define ll long long
using namespace std;

int main(){
    ll n,k;cin>>n>>k;
    if(k<=(n/2)+(n&1)){
        cout<<k*2-1<<endl;
    }
    else{
        cout<<((k-n/2)-(n&1))*2<<endl;
    }
}
