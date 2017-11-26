#include<bits/stdc++.h>
using namespace std;

int a[200005],b[200005];
int main(){
    int n,i=0; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0,t;i<n;++i)cin>>t,b[t]=i;
    for(int i=0;i<n;++i)a[i]=b[a[i]];
    for(i=1;i<n;++i)if(a[i]<a[i-1])break;
    cout<<n-i<<endl;
}
