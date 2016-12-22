#include<iostream>
#include<algorithm>
#include<string>
#define ll long long

using namespace std;

string s;
ll ans;

int main(){
  ios_base::sync_with_stdio(0);
  while(cin>>s){
    if(s=="0"){
      break;
    }
    ans=0;
    for(char &c:s)if(c>'6')--c;
    ll cur=1;
    for(int pos=(int)s.length()-1;pos>=0;--pos,cur*=9){
      ans+=cur*(s[pos]-'0');
    }
    cout<<ans<<'\n';
  }
}
