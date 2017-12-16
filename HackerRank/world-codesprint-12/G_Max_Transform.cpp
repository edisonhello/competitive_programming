#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1000000007;

int a[4004];
pair<int,int> aa[8000000];
int main(){
    // int n; cin>>n;
    // for(int i=0;i<n;++i)cin>>a[i];
    int n=4000; srand(time(0));
    for(int i=0;i<n;++i)a[i]=rand();
    int ptr=0;
    for(int k=0;k<n;++k){
        set<int> st;
        for(int ii=0;ii<k;++ii)st.insert(a[ii]);
        for(int i=0;i<n-k;++i){
            st.insert(a[i+k]);
            auto it=st.end(); --it;
            aa[ptr]={*it,ptr}; ++ptr;
            st.erase(a[i]);
        }
    }
    ll ans=0;
    sort(aa,aa+ptr,greater<pair<int,int>>());
    for(int i=0;i<ptr;++i){
        // cout<<aa[i].first<<" "<<aa[i].second<<endl;
        ll dis=(aa[i].second-(-1))*1ll*(ptr-aa[i].second);
        ans=(ans+aa[i].first*dis%mod)%mod;
    }
    cout<<ans<<endl;
}
