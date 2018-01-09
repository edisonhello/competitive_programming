#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll d; while(cin>>d){
    ll a=1,ans=1,dd=1;
    for(int i=2;i<=50;++i){
        a+=dd; dd+=d; ans+=a;
    }
    cout<<ans<<endl;
}}
