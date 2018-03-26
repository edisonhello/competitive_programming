#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    map<string,int> mp;
    while(n--){
        string s; cin>>s;
        ++mp[s];
    }
    int mx=0;
    for(auto i:mp){
        mx=max(mx,i.second);
    }
    for(auto i:mp){
        if(i.second==mx)cout<<i.first;
    }
}
