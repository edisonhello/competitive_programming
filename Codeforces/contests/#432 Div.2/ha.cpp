#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k,t; cin>>n>>k>>t;
    if(t<=n)cout<<min(k,t)<<endl;
    else cout<<(t%n)+1<<endl;
}
