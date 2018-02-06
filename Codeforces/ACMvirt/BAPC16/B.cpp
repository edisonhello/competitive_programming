#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    for(int i=0;i<s.size();++i){
        if(i+2<s.size()){
            unordered_map<char,int> mp;
            ++mp[s[i]];
            ++mp[s[i+1]];
            ++mp[s[i+2]];
            if(mp['R'] && mp['B'] && mp['L']){
                cout<<"C";
                i+=2;
                continue;
            }
        }
        if(s[i]=='R')cout<<"S";
        if(s[i]=='B')cout<<"K";
        if(s[i]=='L')cout<<"H";
    }
    cout<<endl;
}
