#include<bits/stdc++.h>
using namespace std;
#define ll long long

map<int,ll> x,y;
map<pair<int,int>,ll> xy;

int main(){
    int n; cin>>n;
    while(n--){
        int xx,yy;
        cin>>xx>>yy;
        x[xx]++;
        y[yy]++;
        xy[make_pair(xx,yy)]++;
    }
    ll ans=0;
    for(auto i:x){
        ans+=i.second*(i.second-1)/2;
    }
    for(auto i:y){
        ans+=i.second*(i.second-1)/2;
    }
    for(auto i:xy){
        ans-=i.second*(i.second-1)/2;
    }
    cout<<ans<<endl;
}
