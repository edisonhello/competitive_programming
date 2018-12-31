#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=998244353;
/////////////dig fir mask
ll p10[23];
pair<ll,ll> dp[20][10][1<<10];

void init(){
    p10[0]=1;
    for(int i=1;i<23;++i)p10[i]=p10[i-1]*10%mod;
    for(int i=0;i<10;++i)for(int z=0;z<1024;++z){
        if(!(z&(1<<i)))continue;
        dp[0][i][z]={i,1};
    }
    for(int l=1;l<=19;++l){
        for(int i=0;i<10;++i){ // now
            for(int j=0;j<10;++j){ // prev
                for(int z=0;z<1024;++z){ // mask
                    if(!(z&(1<<i)))continue;
                    if(!(z&(1<<j)))continue;
                    dp[l][i][z].first+=p10[l]*i%mod*dp[l-1][j][z].second%mod+dp[l-1][j][z].first;
                    dp[l][i][z].second+=dp[l-1][j][z].second;
                    while(dp[l][i][z].first>=mod)dp[l][i][z].first-=mod;
                    if(dp[l][i][z].second>=mod)dp[l][i][z].second-=mod;
                }
            }
        }
    }
    for(int l=0;l<20;++l)for(int i=0;i<10;++i)for(int z=0;z<1024;++z){
        for(int zz=0;zz<z;++zz){
            if((z|zz)==z)dp[l][i][z].first-=dp[l][i][zz].first,dp[l][i][z].second-=dp[l][i][zz].second;
        }
        dp[l][i][z].first=(dp[l][i][z].first%mod+mod)%mod;
        dp[l][i][z].second=(dp[l][i][z].second%mod+mod)%mod;
    }
}

int glen(ll x){
    int q=0;
    while(x)x/=10,++q;
    return q;
}

ll get(ll up,int k){
    if(up==0)return 0;
    if(up<10)return up-1;
    int nmask=0;
    int l=glen(up);
    stringstream ss; ss<<up;
    string s; ss>>s;
    ll rt=0;
    for(int i=0;i<l-1;++i){
        for(int j=1;j<10;++j){
            for(int z=0;z<1024;++z){
                if(bitset<10>(z).count()>k)continue;
                rt+=dp[i][j][z].first;
            }
        }
    }
    rt%=mod;
    // cout<<"small len: "<<rt<<endl;
    ll nval=0;
    for(int i=0;i<l;++i){
        for(int j=(i==0);j<s[i]-'0';++j){
            // cout<<"i, j "<<i<<" "<<j<<" , nval: "<<nval<<endl;
            for(int z=0;z<1024;++z){
                if(!(z&(1<<j)))continue;
                if(bitset<10>(z|nmask).count()>k)continue;
                // cout<<"z: "<<z<<" , in"<<endl;
                rt+=dp[l-i-1][j][z].first+dp[l-i-1][j][z].second*nval%mod;
                rt%=mod;
                // cout<<"rt: "<<rt<<endl;
            }
        }
        nmask|=(1<<(s[i]-'0'));
        nval+=p10[l-i-1]*(s[i]-'0');
        nval%=mod;
    }
    return rt;
}

int main(){
    init();
    long long l,r; int k; cin>>l>>r>>k;
    // cout<<get(r+1,k)<<endl;
    cout<<(get(r+1,k)-get(l,k)+mod)%mod<<endl;
}
