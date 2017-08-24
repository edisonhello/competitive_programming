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

long long s;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>s;

    if(s<=2){
        cout<<"-1"<<endl;
        return 0;
    }
    if(s&1){
        ll i=(s-1)/2;
        cout<<2*i*i+2*i<<' '<<2*i*i+2*i+1<<endl;
    }
    else{
        ll i=s/2;
        cout<<i*i-1<<' '<<i*i+1<<endl;
    }
}
