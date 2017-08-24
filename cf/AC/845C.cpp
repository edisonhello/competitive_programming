#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main(){
    int n; cin>>n;
    while(n--){
        int u,v; cin>>u>>v;
        mp[u]++, mp[v+1]--;
    }
    int now=0;
    for(pair<int,int> i:mp){
        now+=i.second;
        if(now>2)return cout<<"NO"<<endl,0;
    } cout<<"YES"<<endl;
}
