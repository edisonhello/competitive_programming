#include<bits/stdc++.h>
using namespace std;
#define next sdfjio

string s; 
int next[200005][26],dp[202005],cf[200005],chr[200005];

int main(){
    cin>>s;
    s="-"+s;
    int n=s.size();
    for(int i=0;i<26;++i)next[n][i]=n+i;
    for(int i=n-1;i>=0;--i){
        for(int j=0;j<26;++j)next[i][j]=next[i+1][j];
        next[i][s[i]-'a']=i;
        /* cout<<"next of "<<i<<" : ";
        for(int j=0;j<26;++j)cout<<next[i][j]<<" ";
        cout<<endl; */
    }
    for(int i=n-1;i>=0;--i){
        int val=9988776;
        for(int j=0;j<26;++j){
            // if(i==0)cout<<j<<" "<<next[i+1][j]<<" "<<dp[next[i+1][j]]<<endl;
            if(dp[next[i+1][j]]+1<val){
                val=dp[next[i+1][j]]+1;
                cf[i]=next[i+1][j];
                chr[i]=j;
            }
        }
        dp[i]=val;
        // cout<<i<<" "<<dp[i]<<" "<<cf[i]<<" "<<chr[i]<<endl;
    }
    string ans;
    int now=0;
    while(now<n){
        ans+=char(chr[now]+'a');
        now=cf[now];
    }
    cout<<ans<<endl;
}
