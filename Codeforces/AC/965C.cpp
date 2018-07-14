#include<bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int n,k,m,d; cin>>n>>k>>m>>d;
    // candy people max_at_once max_of_times
    int ans=0;
    for(int i=1;i<=d;++i){
        int mingroup=(i-1)*k+1;
        int maxgroup=i*k;
        if(n<maxgroup && n<mingroup)break;
        int maxonce=n/mingroup;
        int minonce=n/maxgroup;
        int once=maxonce;
        if(once>m)once=m;
        if(m>=minonce)ans=max(ans,once*i);
    }
    cout<<ans<<endl;
}
