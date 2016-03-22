#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string a,b;cin>>a>>b;

    int ans=0;
    for(int i=0;i<n;i++){
        ans+= a[i]>b[i] ? min(a[i]-b[i],b[i]+10-a[i]) : min(b[i]-a[i],a[i]+10-b[i]);
    }
    cout<<ans<<endl;
}
