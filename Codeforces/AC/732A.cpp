#include<iostream>
using namespace std;
int main(){
    int k,kk,r,a=1;
    cin>>k>>r;
    kk=k;
    while(k%10!=r && k%10!=0){
        k+=kk;a++;
    }
    cout<<a<<endl;
}
