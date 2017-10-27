#include<bits/stdc++.h>
using namespace std;
int a[111];
int main(){
    int n; while(cin>>n){
        for(int i=0;i<n;++i)cin>>a[i];
        int q; cin>>q; while(q--){
            int e,r; cin>>e>>r;
            swap(a[e],a[r]);
        }
        for(int i=0;i<n;++i)cout<<a[i]<<" "; cout<<endl;
    }
}
