#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b; cin>>a>>b;
    int m=min(a,b);
    a-=m; b-=m;
    cout<<m<<" ";
    cout<<a/2+b/2<<endl;
}
