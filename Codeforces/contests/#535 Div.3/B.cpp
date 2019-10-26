#include<bits/stdc++.h>
using namespace std;
set<int> st;
int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<bool> u(10005,0),u2(n,0);
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;++i){
        if(u[a[i]] || a[i]==a.back())continue;
        if(a[n-1]%a[i]==0){
            u[a[i]]=1;
            u2[i]=1;
        }
    }
    for(int i=n-2;i>=0;--i){
        if(!u2[i])exit((cout<<a[i]<<" "<<a.back()<<endl,0));
    }
}
