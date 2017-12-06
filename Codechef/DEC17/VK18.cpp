#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int rec[2000006];
int meow(int n){
    if(~rec[n])return rec[n];
    int nn=n; rec[n]=0;
    while(n){
        rec[nn]+=(n&1?1:-1)*(n%10);
        n/=10; 
    }
    return rec[nn]=abs(rec[nn]);
}
 
int main(){
    for(int i=0;i<2000006;++i)rec[i]=-1;
    int t; cin>>t; while(t--){
        int n,ptr=2,eptr=2; cin>>n;
        ll sum=0,ans=0;
        for(int i=0;i<n;++i,++ptr){
            sum+=meow(ptr);
        }
        for(int i=0;i<n;++i,++ptr,++eptr){
            ans+=sum;
            sum+=meow(ptr)-meow(eptr);
        }
        cout<<ans<<endl;
    }
}
// WA 350
// TLE 380
