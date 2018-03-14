#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt=6; string s; cin>>s;
    int ptr=0;
    for(;ptr<s.size();++ptr)if(s[ptr]=='1')break;
    for(;ptr<s.size();++ptr)if(s[ptr]=='0')--cnt;
    if(cnt<=0)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}
