#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main(){
    int n,k; cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    if(k==0){
        if(a[0]==1)exit((cout<<-1<<endl,0));
        else exit((cout<<1<<endl,0));
    }
    if(k==n){
        exit((cout<<1000000000<<endl,0));
    }
    if(a[k-1]==a[k])exit((cout<<-1<<endl,0));
    cout<<a[k-1]<<endl;
}
