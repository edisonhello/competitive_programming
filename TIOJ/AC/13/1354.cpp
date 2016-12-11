#include<iostream>
using namespace std;

int a[3005],b[3005],t,n;

int main(){
    a[0]=1;
    for(int i=1;i<=3000;++i){
        a[i]=3*b[i-1];
        b[i]=a[i-1]+2*b[i-1];
    }
    cin>>t;
    while(cin>>n){
        cout<<a[n]<<endl;
    }
}
