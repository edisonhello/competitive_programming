#include<bits/stdc++.h>
using namespace std;

int _dp[1000006];
int dp(int n){
    if(_dp[n])return _dp[n];
    if(!n)return 0;
    if(n/10==0)return 1;

    set<int> st;
    int nn=n;
    while(nn){st.insert(nn%10); nn/=10;}
    int mx=1000006;
    for(const int &ii:st){
        if(ii){
            mx=min(mx,dp(n-ii));
        }
    }
    return _dp[n]=mx+1;
}

int main(){
    int n; cin>>n;
    cout<<dp(n)<<endl;
}
