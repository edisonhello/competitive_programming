#include<iostream>
#include<cmath>
using namespace std;

bool isP(int n){
    for(int i=2;i*i<=n;++i){
        if(!(n%i))return 0;
    }
    return 1;
}

int main(){
    int n;cin>>n;
    for(int m=1;;++m){
        if(!isP(n*m+1)){
            cout<<m<<endl;
            return 0;
        }
    }
}
