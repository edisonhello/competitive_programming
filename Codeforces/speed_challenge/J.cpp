#include<bits/stdc++.h>
using namespace std;

int x[100005];

int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>x[i];
    sort(x,x+n);
    int q; cin>>q; while(q--){
        int t; cin>>t;
        cout<<(upper_bound(x,x+n,t)-x)<<'\n';
    }
}
