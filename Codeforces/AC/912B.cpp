#include<bits/stdc++.h>
using namespace std;

int main(){
    #define ll long long
    ll n,k; cin>>n>>k;
    if(k==1)cout<<n<<endl;
    else{
        #define lb(x) ((x)&-(x))
        do n+=lb(n); while(n!=lb(n));
        --n;
        cout<<n<<endl;
    }
}
