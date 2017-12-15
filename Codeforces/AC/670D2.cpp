#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll k,a[100005],b[100005];

bool can(ll cnt,ll kk=k){
    for(int i=1;i<=n;++i){
        if(b[i]>=a[i]*cnt);
        else{
            kk-=a[i]*cnt-b[i];
            if(kk<0)return 0;
        }
    } return 1;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    ll L=0,R=2000000009;
    while(R>L){
        ll M=(L+R+1)>>1;
        if(can(M))L=M;
        else R=M-1;
    }
    cout<<L<<endl;
}
