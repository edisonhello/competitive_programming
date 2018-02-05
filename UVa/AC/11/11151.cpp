#include<bits/stdc++.h>
using namespace std;

int dp[1234][1234];

int main(){
    int n; cin>>n; 
    string s; getline(cin,s);
    while(n--){
        getline(cin,s);
        for(int i=0;i<s.size();++i)for(int j=0;j<s.size();++j)dp[i][j]=0;
        for(int len=1;len<=s.size();++len){
            for(int i=0;i<s.size();++i){
                int j=i+len-1;
                if(j>=s.size())break;
                if(len==1)dp[i][j]=1;
                else if(len==2)dp[i][j]=(s[i]==s[j]?2:1);
                else{
                    if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
                    dp[i][j]=max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));
                }
            }
        }
        cout<<dp[0][s.size()-1]<<endl;
    }
}
