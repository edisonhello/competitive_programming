#include<iostream>
using namespace std;
int a,b,c;
bool _,__;
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>a>>b>>c;
    if(a+c==b+b)_=1;
    if(a*c==b*b && a && b && c)__=1;
    if(_&&__)cout<<"both\n";
    else if(_)cout<<"arithmetic\n";
    else if(__)cout<<"geometric\n";
    else cout<<"normal\n";
}
