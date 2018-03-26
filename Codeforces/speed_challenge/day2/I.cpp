#include<bits/stdc++.h>
using namespace std;

int p(int n){
    stringstream ss; ss<<n;
    string s; ss>>s;
    string sss;
    for(char c:s)if(c!='0')sss+=c;
    stringstream zz(sss);
    int t; zz>>t;
    return t;
}

int main(){
    int a,b; cin>>a>>b;
    int c=a+b;
    if(p(a)+p(b)==p(c))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
