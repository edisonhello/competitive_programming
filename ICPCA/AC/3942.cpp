#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll unsigned long long
const ll p=1249,mod=100000000000031ll;
ll pw[300008];
long long dp[300008];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ks=0;
    pw[0]=1; for(int i=1;i<300008;++i)pw[i]=pw[i-1]*p%mod;
    string s; while(cin>>s){
        cc_hash_table<ll> st;
        int n; cin>>n;
        for(int i=0;i<n;++i){
            string s; cin>>s;
            ll now=0,np=1;
            for(int i=s.size()-1;i>=0;--i)now=(now+s[i]*np)%mod, np=np*p%mod;
            // cout<<"hash is "<<now<<endl;
            st.insert(now);
        }
        ll now=0,np=1;
        dp[0]=1;
        for(int i=0;i<s.size();++i){
            dp[i+1]=0;
            ll now=0,np=1;
            for(int j=i,cc=0;j>=0 && cc<100;--j,++cc){
                now=(now+s[j]*np)%mod; np=np*p%mod;
                if(st.find(now)!=st.end())dp[i+1]=dp[i+1]+dp[j];
                // cout<<i<<" "<<j<<" "<<now<<endl;
            }
            dp[i+1]%=20071027;
            // cout<<dp[i+1]<<endl;
        }
        cout<<"Case "<<(++ks)<<": "<<dp[s.size()]<<endl;
    }
}
