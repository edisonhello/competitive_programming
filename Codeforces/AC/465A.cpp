#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t; cin>>t>>s; t=s;
    ++s[0];
    for(int i=0;i<s.size()-1;++i){
        if(s[i]=='2')s[i]='0',s[i+1]++;
    }
    if(s[s.size()-1]=='2')s[s.size()-1]='0';
    int a=0;
    for(int i=0;i<s.size();++i){
        if(s[i]!=t[i])++a;
    } cout<<a;
}
