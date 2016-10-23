#include<bits/stdc++.h>
using namespace std;
int n,a[10005],ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a,a+1+n);
    for(int i=1;i<=n;++i){
        ans+=(a[i]-a[i-1])*(a[i]-a[i-1]);
    }
    cout<<ans<<'\n';
}
