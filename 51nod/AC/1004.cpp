#include<bits/stdc++.h>
using namespace std;
int pw(int b,int n,int m=10,int a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
int main(){
    int n; cin>>n;
    cout<<pw(n%10,n)<<endl;
}
