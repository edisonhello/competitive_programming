#include<bits/stdc++.h>
using namespace std;
#define ll long long
bitset<10000002> _prime;
vector<int> prime;
void sieve(int n=10000000){
    for(ll i=2;i<=n;++i){
        // cout<<i<<endl;
        if(!_prime[i])prime.push_back(i);
        for(long long j=i*i;j<=n;j+=i){
            // cout<<j<<endl;
            _prime[j]=1;
        }
    }
}
int meow(int pss){
    int ans=0;
    for(int i:prime){
        if(i>pss)break;
        if(pss%i==0)++ans;
    } return ans;
}

pair<ll,ll> getans(int x){
    ll mx=1; ll mxatcut=0;
    for(int cut=1;cut<=x;++cut){
        int pss=x/cut;
        int mww=meow(pss);
        if(mww){
            if((16ll<<((mww-1)*4))+cut>mx){
                mx=(16ll<<((mww-1)*4))+cut;
                mxatcut=cut;
            }
        }
    } return pair<ll,ll>(mx,mxatcut);
}

int main(){
    sieve();
    for(int i=1;i<=100;++i){
        pair<ll,ll> ans=getans(i);
        cout<<i<<" "<<ans.first<<" "<<ans.second<<endl;
    }
}
