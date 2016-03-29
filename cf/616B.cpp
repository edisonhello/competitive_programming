#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int mx=-98989;
    for(int i=0;i<n;i++){
        int mn=1000000001;
        for(int j=0;j<m;j++){
            int t;cin>>t;
            mn = min(mn,t);
        }
        mx=max(mx,mn);
    }
    cout<<mx<<endl;
}
