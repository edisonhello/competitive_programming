#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

void solve(ll &a,ll &b,ll &c,int k){
  ll gcd=__gcd(c,(1ll<<k));
  if(gcd!=1 && (b-a+(1ll<<k))<<(32-k)){
    cout<<"FOREVER\n";return;
  }
  ll ans=0;

}


int main(){
  ll a,b,c;int k;
  int ts;cin>>ts;while(ts--){
    cin>>a>>b>>c>>k;
    solve(a,b,c,k);
  }
}
