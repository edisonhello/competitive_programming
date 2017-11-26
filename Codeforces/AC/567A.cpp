#include<bits/stdc++.h>
using namespace std;

int a[100005];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        if(i==1)cout<<a[2]-a[1];
        else if(i==n)cout<<a[n]-a[n-1];
        else cout<<min(a[i+1]-a[i],a[i]-a[i-1]);
        cout<<" "<<max(a[n]-a[i],a[i]-a[1])<<endl;
    }
}
