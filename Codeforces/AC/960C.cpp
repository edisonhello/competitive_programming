#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main(){
    vector<ll> ans;
    ll x,d=1000000007,k=1; cin>>x;
    while(x){
        int z=1;
        while((1<<(z+1))-1<=x)++z;
        x-=(1<<z)-1;
        for(int i=0;i<z;++i)ans.push_back(k*d);
        ++k;
    }
    if(ans.size()>10000)return cout<<-1<<endl,0;
    cout<<ans.size()<<endl;
    for(ll i:ans)cout<<i<<" ";
}
