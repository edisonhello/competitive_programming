#include<bits/stdc++.h>
using namespace std;
#define int long long

int fib[55],per[55];

int32_t main(){
    int n,k; cin>>n>>k;
    fib[0]=fib[1]=1;
    for(int i=2;i<55;++i)fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=n;++i)per[i]=i;
    for(int i=1;i<=n;++i){
        if(fib[n-i]>=k)continue;
        swap(per[i],per[i+1]);
        k-=fib[n-i]; --i;
    }
    for(int i=1;i<=n;++i)cout<<per[i]<<" "; cout<<endl;
}
