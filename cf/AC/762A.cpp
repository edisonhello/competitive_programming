#include<iostream>
using namespace std;
#define ll long long
#include<vector>

vector<ll> rec;

int main(){
    ll n,k;cin>>n>>k;
    ll cnt=0;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            ++cnt;
            if(cnt==k){
                cout<<i<<endl;
                return 0;
            }
            if(i*i!=n)rec.push_back(n/i);
        }
    }
    if((int)rec.size()>=(int)k-cnt){
        cout<<rec[rec.size()-k+cnt]<<endl;
    }
    else cout<<-1<<endl;
}
