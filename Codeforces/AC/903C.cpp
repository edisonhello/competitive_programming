#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,mx=0,cnt=0; cin>>n;
    map<int,int> mp;
    while(n--){
        cin>>t; ++mp[t];
    }
    for(auto i:mp)cnt=max(cnt,i.second);
    cout<<cnt<<endl;
}
