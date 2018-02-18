#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[56],b[65];

main(){
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    int mn=2e18;
    for(int i=0;i<n;++i){
        int mx=-2e18;
        for(int j=0;j<n;++j){
            if(i==j)continue;
            for(int k=0;k<m;++k){
                mx=max(mx,a[j]*b[k]);
            }
        }
        mn=min(mn,mx);
    }
    cout<<mn<<endl;
}
