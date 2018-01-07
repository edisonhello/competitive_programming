#include<bits/stdc++.h>
using namespace std;

bool _(int n){
    if(n%400==0)return 1;
    if(n%100==0)return 0;
    if(n%4==0)return 1;
    return 0;
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
    int t; cin>>t;
    cout<<"Case "<<i<<": ";
    if(_(t))cout<<"a leap year"<<endl;
    else cout<<"a normal year"<<endl;
}}
