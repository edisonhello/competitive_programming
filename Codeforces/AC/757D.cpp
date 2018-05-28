#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int dp[77][1<<20];

int main(){
    int n; cin>>n;
    string s; cin>>s; s="z"+s;
    for(char &c:s)c-='0';
    for(int i=0;i<n;++i)dp[i][0]=1;
    for(int i=0;i<n;++i){
        int now=0;
        int ptr=i;
        while(ptr<n){
            ++ptr;
            now=now*2+s[ptr];
            if(now>19)break;
            if(now){
                for(int j=0;j<(1<<20);++j){
                    dp[ptr][j|(1<<now)]+=dp[i][j];
                    if(dp[ptr][j|(1<<now)]>=mod)dp[ptr][j|(1<<now)]-=mod;
                }
            }
        }
    }
    vector<int> oks;
    for(int i=2;i<=20;++i)oks.push_back((1<<i)-2);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j:oks){
            ans+=dp[i][j];
            if(ans>=mod)ans-=mod;
        }
    }
    cout<<ans<<endl;
}
