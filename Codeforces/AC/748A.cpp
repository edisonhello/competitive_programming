#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    cout<<((k-1)/(m*2)+1)<<" ";
    k%=(m*2);if(!k)k+=(m*2);
    cout<<((k-1)/(2)+1)<<" ";
    k%=2;
    cout<<(k?"L":"R")<<endl;
}
