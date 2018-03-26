#include<bits/stdc++.h>
using namespace std;


int main(){
    int a,b; cin>>a>>b;
    int m=min(a,b);
    a=1;
    for(int i=2;i<=m;++i)a*=i;
    cout<<a<<endl;
}
