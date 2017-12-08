#include<bits/stdc++.h>
using namespace std;


int main(){
    string s; cin>>s;
    int cnt=1,i=1,j; bool all0=1;
    while(i<s.size() && s[i]=='0')++i;
    for(;i<s.size();i=j){
        for(j=i+1;j<s.size();++j){
            if(s[j]=='0')continue;
            else break;
        }
        // cout<<i<<" "<<j<<" "<<j-i<<endl;
        if(j-i>i || (j-i==i && (s[0]<s[i]))){
            cnt=1; all0=0;
        }
        else ++cnt,all0=0;
    }
    cout<<cnt<<endl;
}
