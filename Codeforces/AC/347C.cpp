#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int g=0,x=0;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        g=__gcd(g,t);
        x=max(x,t);
    }
    n=x/g-n;
    if(n&1)cout<<"Alice";
    else cout<<"Bob";
}
