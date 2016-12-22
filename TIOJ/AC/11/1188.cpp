#include<iostream>
#include<string>
using namespace std;
int a[105];
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  int n,m;string tmp;
  while(cin>>n>>m,n){
    for(int i=1;i<=n;++i)a[i]=i;
    getline(cin,tmp);
    while(m--){
      getline(cin,tmp);
      for(int i=1;i<=n;++i){
        if(tmp[(i-1)<<2]=='+'){
          swap(a[i],a[i+1]);
          ++i;
        }
      }
    }
    for(int i=1;i<=n;++i){
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
}
