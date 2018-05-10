#include<bits/stdc++.h>
using namespace std;


int main(){
    string s; cin>>s>>s;
    map<string,int> mp;
    for(int i=1;i<s.size();++i){
        mp[s.substr(i-1,2)]++;
    }
    int mx=0;
    for(auto i:mp)mx=max(mx,i.second);
    for(auto i:mp)if(i.second==mx){
        cout<<i.first<<endl;
        exit(0);
    }
}
