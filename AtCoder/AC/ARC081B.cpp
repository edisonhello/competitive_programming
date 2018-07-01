#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod=1000000007;

int n; 
string mp[2];
ll dp[55];
int main(){
    cin>>n>>mp[0]>>mp[1];
    int i=0;
    if(mp[0][i]==mp[1][i]){
        dp[0]=3;
        i=1;
    }
    else{
        dp[1]=6;
        i=2;
    }
    for(;i<n;){
        if(mp[0][i]==mp[1][i]){
            if(mp[0][i-1]==mp[1][i-1]){
                dp[i]=(dp[i-1]*2)%mod;
            }
            else{
                dp[i]=dp[i-1];
            }
            ++i;
        }
        else{
            if(mp[0][i-1]==mp[1][i-1]){
                dp[i+1]=(dp[i-1]*2)%mod;
            }
            else{
                dp[i+1]=(dp[i-1]*3)%mod;
            }
            i+=2;
        }
    }
    cout<<dp[n-1]<<endl;
}
