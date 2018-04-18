#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll b[200005],c[200005],a[200005],sum;
int cb[35];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>b[i],sum+=b[i];
    for(int i=1;i<=n;++i)cin>>c[i],sum+=c[i];
    sum>>=1; sum/=n;
    for(int i=1;i<=n;++i)a[i]=(b[i]+c[i]-sum)/n;
    // for(int i=1;i<=n;++i)cout<<a[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i)for(int z=0;z<31;++z)if(a[i]&(1<<z))++cb[z];
    // for(int i=0;i<=30;++i)cout<<cb[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i){
        ll bb=0,cc=0;
        for(int z=0;z<31;++z)if(a[i]&(1<<z))bb+=(1ll<<z)*cb[z];
        for(int z=0;z<31;++z)if(a[i]&(1<<z))cc+=(1ll<<z)*n; else cc+=(1ll<<z)*cb[z];
        // cout<<bb<<" "<<cc<<endl;
        if(bb!=b[i] || cc!=c[i])exit((cout<<-1<<endl,0));
    }
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
}
