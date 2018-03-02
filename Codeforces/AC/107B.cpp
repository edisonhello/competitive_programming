#include<bits/stdc++.h>
using namespace std;
#define ld long double

ld C(int k,int n){
    if(k>n)return 0;
    ld rt=1;
    for(int i=n,j=1;j<=k;--i,++j)rt*=(ld)i/j;
    // for(int i=1;i<=k;++i)rt/=i;
    // for(int i=1;i<=k;++i)rt/=i;
    return rt;
}

int main(){
    int n,m,h; cin>>n>>m>>h; --n;
    int sum=0,me=-1;
    for(int i=1;i<=m;++i){
        int t; cin>>t;
        (i==h?me:sum)+=t;
    }
    ld ans=1.0-C(n,sum)/C(n,sum+me);
    // cout<<C(n,sum)<<" "<<C(n,sum+me)<<endl;
    if(n>sum+me)cout<<"-1"<<endl;
    else cout<<fixed<<setprecision(10)<<ans<<endl;
}
