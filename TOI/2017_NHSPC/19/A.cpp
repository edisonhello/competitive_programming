#include<bits/stdc++.h>
using namespace std;

int a[123],app[1234];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int mn=9999,mx=0;
    for(int i=1;i<=n;++i)app[a[i]]=1,mn=min(mn,a[i]),mx=max(mx,a[i]);
    if(mx-mn+1!=n)cout<<mn<<" "<<mx<<" no"<<endl;
    else cout<<mn<<" "<<mx<<" yes"<<endl;
}
