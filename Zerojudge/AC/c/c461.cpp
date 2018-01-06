#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d=0; cin>>a>>b>>c;
    if(bool((!!a)&(!!b))==c)cout<<"AND"<<endl,++d;
    if(bool((!!a)|(!!b))==c)cout<<"OR"<<endl,++d;
    if(bool((!!a)^(!!b))==c)cout<<"XOR"<<endl,++d;
    if(!d)cout<<"IMPOSSIBLE"<<endl;
}
