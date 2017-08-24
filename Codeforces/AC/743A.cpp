#include<iostream>
using namespace std;
int main(){
    int n,a,b;cin>>n>>a>>b;
    if(a>b){a^=b;b^=a;a^=b;}
    string s;cin>>s;
    --a,--b;
    if(s[a]==s[b]){cout<<0<<endl;}
    else cout<<1<<endl;
}
