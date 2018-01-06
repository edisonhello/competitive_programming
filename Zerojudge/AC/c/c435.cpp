#include<bits/stdc++.h>
using namespace std;

int a[10002];
int main(){
    int n; cin>>n;
    int ans=-1;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            ans=max(ans,a[i]-a[j]);
        }
    }
    cout<<ans<<endl;
}
