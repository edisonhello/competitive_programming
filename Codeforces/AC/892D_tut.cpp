#include<bits/stdc++.h>
using namespace std;

int a[25];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<n;++i){
        int mx=1000000008;
        for(int j=0;j<n;++j)if(a[j]>a[i])mx=min(mx,a[j]);
        if(mx==1000000008)for(int j=0;j<n;++j)mx=min(mx,a[j]);
        cout<<mx<<" ";
    } cout<<endl;
}
