#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n,k; cin>>n>>k;
    ll buy=1,left=n,cnt=0;
    for(int i=1;i<=k;++i){
        ll c; cin>>c;
        if(n%c<left){
            cnt=n/c;
            buy=i;
            left=n%c;
        }
    }
    cout<<buy<<" "<<cnt<<endl;
}
