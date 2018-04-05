#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int mx=-(1<<29),mn=1<<29;
    for(int i=0;i<n;++i){
        int t; cin>>t;
        mx=max(t,mx);
        mn=min(t,mn);

    }
    cout<<mn<<" "<<mx<<" "<<(mx-mn+1==n?"yes":"no")<<endl;
}
