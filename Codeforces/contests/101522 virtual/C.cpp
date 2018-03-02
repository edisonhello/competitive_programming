#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int L=0,P=0;
    for(int i=0;i<s.size();++i){
        if(i+2<s.size()){
            if(s[i]=='L' && s[i+1]=='S' && s[i+2]=='C')++L;
        }
        if(i+3<s.size()){
            if(s[i]=='P' && s[i+1]=='C' && s[i+2]=='M' && s[i+3]=='S')++P;
            
        }
    }
    if(L>P)cout<<"LSC"<<endl;
    else if(L==P)cout<<"Tie"<<endl;
    else cout<<"PCMS"<<endl;
}
