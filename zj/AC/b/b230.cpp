#include<iostream>
#include<bitset>
using namespace std;
bitset<50000> cv;
int main(){
    for(int i=1;i<=100;++i){
        for(int j=i+1;j<=100;++j){
            for(int k=j+1;k<=100;++k){
                cv[i*j+j*k+k*i]=1;
            }
        }
    }
    int n,i,cn;cin>>n;
    for(cn=1,i=1;cn<=n;++i){
        if(!cv[i])++cn;
    }
    cout<<i-1<<endl;
}
