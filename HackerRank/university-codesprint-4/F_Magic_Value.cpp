#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;


ll a[200006];
int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    ll ans=0;

    for(int i=1;i<=n;++i){
        ll mx=a[i],gcd=a[i];
        for(int j=i+1;j<=n;++j){
            mx=max(mx,a[j]*(j-i+1));
            gcd=__gcd(gcd,a[j]);
            // cout<<i<<" "<<j<<" "<<mx<<" "<<gcd<<endl;
            ans=(ans+(mx-gcd)%mod*(j-i+1)%mod)%mod;
        }
    }

    /* map<ll,int> gcd,newgcd;
    vector<pair<ll,int>> stk;
    ll instacksum=0,maxsum=0;
    for(int i=1;i<=n;++i){
        cout<<"in i: "<<i<<endl;
        if(stk.size())instacksum+=stk.back().first;
        maxsum+=instacksum;
        int orig_end=i;
        while(stk.size() && stk.back().first<=a[i]){
            ll len=(orig_end-stk.back().second+1);
            cout<<"len: "<<len<<endl;
            maxsum-=(1+len)*(len)/2*stk.back().first;
            instacksum-=len*stk.back().first;
            orig_end=stk.back().second-1;
            stk.pop_back();
        }
        cout<<"maxsum: "<<maxsum<<" , instacksum: "<<instacksum<<endl;
        int start_point=stk.size()?stk.back().second+1:1;
        stk.push_back({a[i],start_point});
        instacksum+=a[i]*(i-start_point+1);
        maxsum+=a[i]*(i-start_point+2)*(i-start_point+1)/2;
        ans=ans+maxsum;
        
        cout<<"maxsum: "<<maxsum<<" , instacksum: "<<instacksum<<endl;

        cout<<"finish max"<<endl;

        newgcd[a[i]]=i;
        for(auto ii:gcd){
            ll _newgcd=__gcd(ii.first,a[i]);
            if(newgcd[_newgcd]==0)newgcd[_newgcd]=ii.second;
            else newgcd[_newgcd]=min(gcd[_newgcd],ii.second);
        }
        gcd=newgcd;
        for(auto ii:gcd){
            ans-=(i-ii.second+1)*ii.first;
        }

        cout<<"finish min"<<endl;
    }
    */
    cout<<ans%mod<<endl;
}
