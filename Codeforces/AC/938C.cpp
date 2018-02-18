#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t; cin>>t; while(t--){
        ll x; cin>>x;
        bool get=0;
        for(ll i=1;i*i<=x;++i){
            if(x%i==0 && (i+(x/i))%2==0){
                ll n=(i+x/i)/2,m=n-i;
                if(n && m && n/(n/m)==m){
                    cout<<n<<" "<<n/m<<endl;
                    get=1;
                    break;
                }
            }
        }
        if(x==0)cout<<1<<" "<<1<<endl,get=1;
        if(!get)cout<<-1<<endl;
    }
}
