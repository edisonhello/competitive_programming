#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[44];

int main(){
    int n,mod; cin>>n>>mod;
    for(int i=0;i<n;++i)cin>>a[i],a[i]%=mod;
    set<int> nums;
    nums.insert(0);
    int n1=(n+1)/2,n2=n-n1;
    for(int i=1;i<(1<<n1);++i){
        int t=0;
        for(int j=0;j<n1;++j){
            if(i&(1<<j)){
                t+=a[j];
                if(t>=mod)t-=mod;
            }
        }
        nums.insert(t);
    }
    int mx=0;
    for(int i=0;i<(1<<n2);++i){
        int t=0;
        for(int j=0;j<n2;++j){
            if(i&(1<<j)){
                t+=a[j+n1];
                if(t>=mod)t-=mod;
            }
        }
        auto it=nums.lower_bound(mod-t); --it;
        mx=max(mx,t+*it);
    }
    cout<<mx<<endl;
}
