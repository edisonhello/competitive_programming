#include<bits/stdc++.h>
using namespace std;

int main(){
#define int long long
    int a,b; cin>>a>>b;
    int x,y,z; cin>>x>>y>>z;
    int aa=2*x+y;
    int bb=y+3*z;
    cout<<max(0ll,aa-a)+max(0ll,bb-b)<<endl;
}
