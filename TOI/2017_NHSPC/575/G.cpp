#include<bits/stdc++.h>
using namespace std;

int _buf[234234],dp[102][102];
int main(){
    string s,t; cin>>s>>t;
    int l,k; cin>>l>>k;
    for(int i=0;i<s.size();++i){
        for(int j=0;j<t.size();++j){
            if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int del=s.size()+t.size()-dp[s.size()-1][t.size()-1]*2;
    int tt=del/l+!!(del%l);
    if(tt>k)cout<<"Impossible"<<endl;
    else cout<<tt<<endl;
}
