#include<bits/stdc++.h>
using namespace std;
#define ll long long

string s;
ll dp[222];

void meow(){
    memset(dp,0,sizeof(dp));
    for(int i=0;i<s.length();++i){
        ll now=0,base=1;
        for(int j=i;j>=0;--j){
            now+=1ll*(s[j]-'0')*base;
            base*=10;
            if(now>INT_MAX)break;
            dp[i+1]=max(dp[i+1],dp[j]+now);
        }
    }
}

int main(){
    int n; cin>>n; while(n--){
        cin>>s;
        meow();
        cout<<dp[s.length()]<<endl;
    }
}
