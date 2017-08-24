#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
  ll k2,k3,k5,k6,ans=0;
  cin>>k2>>k3>>k5>>k6;
  ans+=256*min({k2,k5,k6});
  k2-=min({k2,k5,k6});
  ans+=32*min(k3,k2);
  cout<<ans<<endl;
}
