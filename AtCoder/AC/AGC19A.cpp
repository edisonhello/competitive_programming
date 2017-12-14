#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll q,h,s,d,n; cin>>q>>h>>s>>d>>n;
    h=min(h,2*q);
    s=min(s,2*h);
    d=min(d,2*s);
    cout<<n/2*d+n%2*s<<endl;
}
