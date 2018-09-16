#include<bits/stdc++.h>
using namespace std;

int zeropre[3000007],a[3000007];
bitset<3000007> mns;
long double v[3000007];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)if(a[i]==0)++zeropre[i];
    for(int i=1;i<=n;++i)zeropre[i]+=zeropre[i-1];
    for(int i=1;i<=n;++i)if(a[i]<0)mns[i]=1;
    for(int i=1;i<=n;++i)if(mns[i-1])mns[i].flip();
    for(int i=1;i<=n;++i)if(a[i])v[i]=log10(abs(a[i]));
    for(int i=1;i<=n;++i)if(a[i])v[i]+=v[i-1];
    int l,r;
    while(q--){
        cin>>l>>r;
        if(zeropre[r]-zeropre[l])cout<<0<<'\n';
        else if(mns[r]!=mns[l])cout<<"-"<<setprecision(12)<<pow(10,v[r]-v[l])<<'\n';
        else cout<<setprecision(12)<<pow(10,v[r]-v[l])<<'\n';
    }
}

