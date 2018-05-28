#include<bits/stdc++.h>
using namespace std;
#define ll long long

bitset<200005> frontdead;
ll co[200005],nco[200005],Q[200005],mid[200005];

int main(){
    ll n,k; cin>>n>>k;
    for(int i=0;i<=n;++i){
        cin>>co[i];
        nco[i]=co[i];
    }
    int ans=0;
    Q[n]=co[n];
    for(int i=n-1;i>=0;--i){
        if(frontdead[i+1])frontdead[i]=1;
        mid[i]=Q[i+1]*2;
        Q[i]=co[i]+mid[i];
        if(abs(Q[i])>(ll)4e9){
            frontdead[i]=1;
        }
    }
    /* for(int i=n;i>=0;--i)cout<<co[i]<<" "; cout<<endl;
    for(int i=n;i>=0;--i)cout<<Q[i]<<" "; cout<<endl;
    for(int i=n;i>=0;--i)cout<<mid[i]<<" "; cout<<endl; */
    for(int i=0;i<=n;++i){
        if(!frontdead[i]){
            ll target=-mid[i];
            ll delta=nco[i]-target;
            ll ornco=co[i]-delta;
            // cout<<i<<" "<<target<<" "<<delta<<" "<<ornco<<endl;
            if(i!=n && abs(ornco)<=k)++ans;
            else if(i==n && abs(ornco)<=k && ornco!=0)++ans;
        }
        if(nco[i]&1)break;
        nco[i]>>=1;
        nco[i+1]+=nco[i];
    }
    cout<<ans<<endl;
}
