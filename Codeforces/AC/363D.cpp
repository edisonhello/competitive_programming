#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll b[100005],p[100005];

bool can(int ren,ll a){
    for(int i=0;i<ren;++i){
        if(b[i]>p[ren-1-i]);
        else{
            a-=p[ren-1-i]-b[i];
        }
    } return a>=0;
}
ll get(int ren,ll a){
    ll tp=0;
    for(int i=0;i<ren;++i){
        tp+=p[ren-1-i];
    } return a-tp;
}

int main(){
    int n,m; ll a; cin>>n>>m>>a;
    for(int i=0;i<n;++i)cin>>b[i];
    for(int i=0;i<m;++i)cin>>p[i];
    sort(b,b+n,greater<ll>());
    sort(p,p+m);
    int L=0,R=min(n,m);
    while(R>L){
        int M=(L+R+1)>>1;
        if(can(M,a))L=M;
        else R=M-1;
    } cout<<L<<" "<<-min(0ll,get(L,a))<<endl;
}
