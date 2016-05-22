#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,tm;cin>>n>>tm;

    //min//
    ll avg = n/tm;
    ll lft = n%tm;

    ll mn = (avg+1)*avg*lft/2 + avg*(avg-1)*(tm-lft)/2;

    ll mx = (n-tm+1)*(n-tm)/2;

    cout<<mn<<" "<<mx<<endl;
}
