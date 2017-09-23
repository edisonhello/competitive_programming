#include<bits/stdc++.h>
using namespace std;
int main(){
int ts,ks=0;cin>>ts;while(ts--){int l,r;cin>>l>>r;int ans=0;
for(int i=l;i<=r;++i){if((int)sqrt(i)*(int)sqrt(i)==i)ans+=i;}cout<<"Case "<<(++ks)<<": "<<ans<<endl;}
}
