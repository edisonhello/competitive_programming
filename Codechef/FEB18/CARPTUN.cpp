#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
    int t; cin>>t; while(t--){
        int n; cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int c,d,s; cin>>c>>d>>s;
        int mx=0;
        for(int i=1;i<=n;++i)mx=max(mx,a[i]);
        cout<<1ll*mx*(c-1)<<endl;
    }
}
