#include<bits/stdc++.h>
using namespace std;
int main(){int n;while(cin>>n){int cnt=0;for(int i=0,t;i<n;++i){cin>>t;cnt+=t;}if(cnt<=59*n)cout<<"yes\n";else cout<<"no\n";}}
