#include<bits/stdc++.h>
using namespace std;

long long a[300005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    long long ans=0;
    for(int fdsa=2,i=0;i<n;++i,++fdsa){
        ans+=a[i]*min(fdsa,n);
    }
    cout<<ans<<endl;
}
