#include<iostream>
#include<string>
using namespace std;

int main(){
  int n;string s;int a=0,d=0;
  cin>>n>>s;
  for(char c:s){
    if(c=='A')++a;
    else ++d;
  }
  if(a>d)cout<<"Anton\n";
  else if(a<d)cout<<"Danik\n";
  else cout<<"Friendship\n";
}
