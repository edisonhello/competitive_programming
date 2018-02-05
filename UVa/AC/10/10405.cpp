#include<bits/stdc++.h>
using namespace std;
int dp[1234][1234];
int main(){
    string s,t; while(getline(cin,s)){
        getline(cin,t);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<s.size();++i){
            for(int j=0;j<t.size();++j){
                if(s[i]==t[j])dp[i+1][j+1]=dp[i][j]+1;
                else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
            }
        }
        cout<<dp[s.size()][t.size()]<<endl;
    }
}
