#pragma GCC optimize("O")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> nums;
ll rec[1000006];

void init(){
    for(int i=1;i<=1000000;++i){
        rec[i]=i;
        ll sq=round(sqrt(i));
        if(sq*sq==i)rec[i]=0;
    }
    for(int i=3;i<=60;i+=2){
        for(int j=1;j<=1000000;++j){
            ll nw=rec[j]*j;
            if(nw/j!=rec[j] || nw>1000000000000000000ll)break;
            ll nwnw=nw*j;
            if(nwnw/j!=nw || nwnw>1000000000000000000ll)break;
            rec[j]=nwnw;
            if(rec[j])nums.push_back(rec[j]);
        }
    }
    sort(nums.begin(),nums.end());
    nums.resize(unique(nums.begin(),nums.end())-nums.begin());
    // for(int i=0;i<1000;++i)cout<<nums[i]<<" ";
}

ll calc(ll x){
    auto it=upper_bound(nums.begin(),nums.end(),x);
    ll rt=it-nums.begin();
    return rt+floor(pow((long double)x,0.5)+1e-15);
}

int main(){
    init();
    int q; cin>>q;
    while(q--){
        ll l,r; cin>>l>>r;
        cout<<calc(r)-calc(l-1)<<endl;
    }
}
