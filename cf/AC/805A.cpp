#include<bits/stdc++.h>
using namespace std;

int main(){
int l,r;cin>>l>>r;
if(l==r)return cout<<l<<endl,0;
if(r==l+1)return cout<<r<<endl,0;
int d2=r/2-(l-1)/2,d3=r/3-(l-1)/3;
if(d3>=d2)return cout<<3<<endl,0;
cout<<2<<endl;
}
