#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n; 
ll a[1000006];
priority_queue<ll,vector<ll>,greater<ll>> dis;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    ll tot=0;
    for(int i=1;i<n;++i){
        tot+=abs(a[i]-a[i+1]);
        dis.push(max(abs(a[i]-a[i+1])-abs(a[i]+a[i+1]),0ll));
        while(dis.size()>2u)dis.pop();
    }
    while(dis.size()){
        tot-=dis.top();
        dis.pop();
    }
    cout<<tot<<endl;
}
