#include<bits/stdc++.h>
using namespace std;

long long lcm(long long i,long long j,long long k){
    long long g=__gcd(i,j);
    j=i/g*j;
    g=__gcd(j,k);
    return j/g*k;
}

int main(){
    int n; while(cin>>n){
    if(n<=2){cout<<n<<endl,0; continue;}
    if(n==3){cout<<6<<endl,0; continue;}
    long long ans=0;
    for(int i=n-3;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int k=j+1;k<=n;++k){
                ans=max(ans,lcm(i,j,k));
            }
        }
    }
    cout<<ans<<endl;
}}
