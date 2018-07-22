#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    int n; cin>>n;
    long long ans=0;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i)if(a[i]>i){ cout<<-1<<endl; exit(0); }
    for(int i=1;i<n;++i)if(a[i]>a[i-1]+1){ cout<<-1<<endl; exit(0); }
    for(int i=n-1;i>=0;--i){
        if(a[i]==a[i+1]-1)continue;
        ans+=a[i];
    }
    cout<<ans<<endl;
}
