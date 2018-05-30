#include<bits/stdc++.h>
using namespace std;
#define ld double

int n;
ld mx[100005],mn[100005];
ld ap[100005],bp[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n==1){ exit((cout<<"1\n1\n",0)); }
    for(int i=1;i<=n;++i)cin>>mx[i];
    for(int i=1;i<=n;++i)mx[i]+=mx[i-1];
    for(int i=1;i<=n;++i)cin>>mn[i];
    for(int i=1;i<=n;++i)mn[i]+=mn[i-1];
    for(int i=1;i<=n;++i){
        ld u=mx[i],v=mn[i];
        ld wsq=max((u+v)*(u+v)-4*u,.0);
        ld a=(u+v+sqrt(wsq))/2;
        ld b=(u+v-sqrt(wsq))/2;
        ap[i]=a; bp[i]=b;
    }
    for(int i=1;i<=n;++i)cout<<ap[i]-ap[i-1]<<" "; cout<<endl;
    for(int i=1;i<=n;++i)cout<<bp[i]-bp[i-1]<<" "; cout<<endl;
}
