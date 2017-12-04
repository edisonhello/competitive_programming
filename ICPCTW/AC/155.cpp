#include<bits/stdc++.h>
using namespace std;

const long long mod=998244353;
long long rec[100005];
int main(){
    int n; cin>>n;
    rec[0]=1;
    for(int i=1;i<=n;++i)cin>>rec[i],rec[i]=rec[i]*rec[i-1]%mod;
    long long ans=0;
    for(int i=1;i<=n;++i)ans=ans+rec[i];
    cout<<ans%mod<<endl;
}
