#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    int ans=1e9;
    int prv; cin>>prv;
    ans=1000000-prv;
    for(int i=1;i<n;++i){
        int now; cin>>now;
        ans=min(ans,max(prv-1,1000000-now));
        prv=now;
    }
    ans=min(ans,prv-1);
    cout<<ans<<endl;
}
