#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define u unsigned

int main(){
  ll a[3];
  cin>>a[0]>>a[1]>>a[2];
  sort(a,a+3);
  reverse(a,a+3);
  ll ans=0;
  if(a[1]<a[0]-1){
    ans+=a[0]-a[1]-1;
  }
  if(a[2]<a[0]-1){
    ans+=a[0]-a[2]-1;
  }
  cout<<ans<<endl;
}
