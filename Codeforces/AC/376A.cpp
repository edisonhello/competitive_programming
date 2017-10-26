#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define X first
#define Y second
#define PDE1(x) cout<<#x<<" : "<<x<<endl
#define PDE2(a,b) cout<<#a<<" : "<<a<<" , ", PDE1(b)
#define iosbase ios_base::sync_with_stdio(0); cin.tie(0);

void JIZZ(string s=""){cout<<s<<endl; exit(0);}

int main(){
    string s; cin>>s;
    ll up=0,wei=0;
    for(int i=0;i<s.size();++i)if(s[i]=='^')up=i;
    for(int i=0;i<s.size();++i)if(s[i]>='0' && s[i]<='9'){
        wei+=(s[i]-'0')*(i-up);
    }
    if(wei>0)JIZZ("right");
    else if(wei<0)JIZZ("left");
    else JIZZ("balance");
}
