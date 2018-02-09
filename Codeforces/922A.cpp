#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll x,y; cin>>y>>x;
    if(x==0)return cout<<"No"<<endl,0;
    ll xadd=x-1;
    if(xadd>y)return cout<<"No"<<endl,0;
    if(!xadd && y)return cout<<"No"<<endl,0;
    if((y-xadd)&1)return cout<<"No"<<endl,0;
    cout<<"Yes"<<endl;
}
