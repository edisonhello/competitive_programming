#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int len=s.length(),tot=0;
    for(int i=0;i<len/2;++i){
        if(s[i]!=s[len-1-i])++tot;
    }
    if(tot==1 || tot<=1 && len%2)cout<<"YES\n";
    else cout<<"NO\n";
}
