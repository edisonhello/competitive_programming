#include<bits/stdc++.h>
using namespace std;

bitset<1000006> p;
int main(){
    p[0]=p[1]=1;
    for(int i=2;i<=1000000;++i){
        if(!p[i])for(long long j=i*1ll*i;j<=1000000;j+=i)p[j]=1;
    }
    long long n; cin>>n; while(cin>>n){
        (long long)(round(sqrt(n))*round(sqrt(n)))==n && !p[round(sqrt(n))]?cout<<"YES\n":cout<<"NO\n";
    }
}
