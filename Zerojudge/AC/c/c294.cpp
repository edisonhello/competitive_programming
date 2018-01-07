#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll a,b,c; cin>>a>>b>>c;
    sort(&a,&a+3);
    cout<<a<<" "<<b<<" "<<c<<endl;
    if(a+b<=c)return cout<<"No"<<endl,0;
    a=a*a,b=b*b,c=c*c;
    if(a+b<c)cout<<"Obtuse"<<endl;
    else if(a+b==c)cout<<"Right"<<endl;
    else cout<<"Acute"<<endl;
}
