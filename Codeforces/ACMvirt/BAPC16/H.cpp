#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dig;
map<int,int> mp;
void dec(ll x,int b){
    for(int i=2;i<=b && i*i<=x;++i){
        if(x%i==0){
            ++mp[i];
            mp/=i;
        }
    }
    if(mp>b)exit((cout<<"impossible"<<endl,0));
    if(x!=1)++mp[x];
}

int main(){
    int b; 
    ll x; 
    cin>>b>>x;
    dec(x);
    while(mp.size()){
        auto it=mp.end(); --it;
        --it->second; if(it->second==0){
            mp.erase(it);
            dfs((ld)b/it->second);
        }
        else dfs((ld)b/it->second);
    }
}
