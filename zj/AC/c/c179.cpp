#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;
ll a[200006],mxa;

bool meow(ll v){
    int used=1;
    ll now=0;
    for(int i=0;i<n;++i){
        if(now+a[i]>v){
            now=a[i];
            ++used;
            if(used>k)return 0;
        }
        else now+=a[i];
    }
    return 1;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i],mxa=max(mxa,a[i]);
    ll L=mxa,R=2000000000ll;
    while(R>L){
        ll mid=L+R>>1;
        if(meow(mid))R=mid;
        else L=mid+1;
    }
    cout<<L<<endl;
}
