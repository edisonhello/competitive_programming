#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a[15];
    while(cin>>n,n){
        for(int i=0;i<n;++i)cin>>a[i];
        long long ans=1;
        for(int i=1;i<n;++i){
            long long g=__gcd(a[i-1],a[i]);
            a[i]=a[i-1]*a[i]/g;
        }
        cout<<a[n-1]<<endl;
    }
}
