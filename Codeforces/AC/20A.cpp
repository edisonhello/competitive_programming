#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    for(int i=0;i<s.length()-1;++i){
        if(s[i]=='/' && s[i+1]=='/'){
            s.erase(s.begin()+i+1);
            --i;
        }
    }
    if(s[s.length()-1]=='/')s=s.substr(0,s.length()-1);
    cout<<(s==""?"/":s)<<endl;
}
