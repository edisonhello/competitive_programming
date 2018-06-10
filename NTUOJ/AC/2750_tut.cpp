#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fac[20];
// map<ll,ll> dp[20][150];
map<ll,ll> dp[20][150];
map<ll,ll> dp2[20][2][150];

ll calc(string s){
    for(int i=0;i<10;++i)for(int j=0;j<64;++j)dp[i][j].clear();
    for(int i=0;i<20;++i)for(int j=0;j<2;++j)for(int k=0;k<150;++k)dp2[i][j][k].clear();
    fac[0]=1;
    for(int i=1;i<20;++i)fac[i]=fac[i-1]*i;
    // for(int i=0;i<20;++i)cout<<"fac["<<i<<"]="<<fac[i]<<endl;
    int sum=0;
    for(char c:s)sum+=c-'0';
    int n=s.size();
    ll pro=1;
    for(char c:s)pro*=(c-'0'+1);
    ll ans=0;
    {
        ll dp[20][150];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;++i){
            for(int j=0;j<150;++j){
                for(int k=0;k<=9;++k){
                    if(j+k>=150)break;
                    dp[i][j+k]+=dp[i-1][j];
                }
            }
        }
        for(int j=0;j<sum;++j)ans+=dp[n][j];
    }
    {
        dp[0][0][1]=1;
        for(int i=1;i<=n;++i){
            for(int j=0;j<150;++j){
                for(auto &p:dp[i-1][j]){
                    for(int k=0;k<=9;++k){
                        if(j+k>=150)break;
                        dp[i][j+k][p.first*(k+1)]+=p.second;
                    }
                }
            }
        }
        for(auto &p:dp[n][sum]){
            if(p.first>=pro)break;
            ans+=p.second;
        }
    }
    {
#define dp dp2
        dp[0][1][0][1]=1;
        for(int i=1;i<=n;++i){
            int cd=s[i-1]-'0';
            for(int j=0;j<150;++j){
                for(auto &p:dp[i-1][1][j]){
                    ll k=p.first,val=p.second;
                    for(int nd=0;nd<=cd;++nd){
                        if(nd+j>sum)break;
                        dp[i][nd==cd][nd+j][k*(nd+1)]+=val;
                    }
                }
                for(auto &p:dp[i-1][0][j]){
                    ll k=p.first,val=p.second;
                    for(int nd=0;nd<=9;++nd){
                        if(nd+j>sum)break;
                        dp[i][0][nd+j][k*(nd+1)]+=val;
                    }
                }
            }
        }
        ans+=dp[n][0][sum][pro];
#undef dp
    }
    return ans;
}

int main(){
    string s; cin>>s; cout<<calc(s)<<endl;
    /* vector<pair<ll,string>> v;
    for(char i='0';i<='9';++i)
    for(char j='0';j<='9';++j)
    for(char k='0';k<='9';++k){
        string s;
        s+=i; s+=j; s+=k;
        v.emplace_back(calc(s),s);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        auto p=v[i];
        cout<<i<<" : ";
        cout<<"("<<p.first<<","<<p.second<<")"<<endl;
    } */
}
