#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;cin>>a>>b;
    if(a>b)swap(a,b);
    if(!(b&1))++b;
    if(!(a&1))--a;
    cout<<(b-a)/2<<endl;
}
