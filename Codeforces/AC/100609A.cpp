#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("ate.in","r",stdin);
    freopen("ate.out","w",stdout);
    int n; cin>>n;
    int a=0;
    for(int i=0;i<=99;++i){
        if(n-i>=0 && n-i<=99)++a;
    }
    cout<<a<<endl;
}
