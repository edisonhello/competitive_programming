#include<bits/stdc++.h>
using namespace std;

int a[7333];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        ++a[t];
    }
    int ans=0;
    for(int i=1;i<=6666;++i){
        while(a[i]>1){
            --a[i];++a[i+1];
            ++ans;
        }
    }
    cout<<ans;
}
