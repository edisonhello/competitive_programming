#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    string a="a",b="b",at,bt;
    int m;cin>>m;
    for(int i=0;i<((int)(sqrt(2*m)));i++){
        at=a+b;
        bt=b+a;
        a=at;
        b=bt;
    }
    cout<<a<<'\n'<<b<<'\n';
}
