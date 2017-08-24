#include<iostream>
using namespace std;

int a[5005],n,b;

int main(){
    cin>>n;
    for(int i=2;i<=n;++i){
        cout<<"? 1 "<<i<<endl;
        cin>>a[i];
    }
    cout<<"? 2 3"<<endl;
    cin>>b;
    a[1]=(a[2]+a[3]-b)>>1;
    cout<<"! "<<a[1];
    for(int i=2;i<=n;++i){
        cout<<" "<<a[i]-a[1];
    }
    cout<<endl;
}
