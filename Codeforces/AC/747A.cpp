#include<iostream>
using namespace std;

int main(){
    int n,a;cin>>n;
    for(int i=1;i*i<=n;++i){
        if(n%i==0)a=i;
    }
    cout<<a<<" "<<n/a<<endl;
}
