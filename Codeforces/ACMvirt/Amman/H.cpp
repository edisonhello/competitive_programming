#include<bits/stdc++.h>
using namespace std;

int a[2004];

int main(){
    int ts; cin>>ts; while(ts--){
        int n; cin>>n; n<<=1;
        for(int i=1;i<=n;++i)cin>>a[i];
        int mx=0;
        for(int i=1;i<=n;++i)mx=max(mx,a[i]+a[n+1-i]);
        cout<<mx<<endl;
    }
}
