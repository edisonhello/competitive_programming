#include<bits/stdc++.h>
using namespace std;

int a[1000006],prv[1000006];

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    double ans=0;
    for(int i=1;i<=n;++i){
        long long fu=n+1-i;
        if(i>1)fu<<=1;
        ans+=i*fu;
    }
    ans/=(double)n*n;
    for(int i=1;i<=n;++i){
        if(prv[a[i]]){
            int pr=prv[a[i]];
            int nw=i;
            int le=pr;
            int ri=n+1-nw;
            ans-=(double)le*ri*2/n/n;
        }
        prv[a[i]]=i;
    }
    cout<<fixed<<setprecision(12)<<ans<<endl;
}
