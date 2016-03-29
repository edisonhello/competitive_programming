#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,w;cin>>k>>n>>w;
    int ans=w*(w+1)*k/2 - n;
    if(ans<0)cout<<0<<endl;
    else cout<<ans<<endl;
}
