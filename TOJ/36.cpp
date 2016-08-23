#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define sf(x) scanf(x)
#define pf(x) printf(x)
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x)
#define X first
#define Y second

ll _pow(ll a,ll b,ll c){
    ll ans=1;
    while(b){
        if(b&1){
            ans*=a;
            ans%=c;
        }
        a*=a;
        b>>=1;
        a%=c;
    }
    return ans;
}

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    a %= c;

    cout<<_pow(a,b,c)<<endl;
}
