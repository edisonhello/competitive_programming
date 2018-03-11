#include<bits/stdc++.h>
using namespace std;

int a[100006];

int main(){
    int n; cin>>n;
    int mx=0,ans=0;
    for(int i=0;i<n;++i)cin>>a[i];
    ans=a[0]-a[1]; mx=a[0];
    for(int i=1;i<n;++i){
        if(a[i]>mx)mx=a[i];
        else ans=max(ans,mx-a[i]);
    }
    cout<<ans<<endl;
}
