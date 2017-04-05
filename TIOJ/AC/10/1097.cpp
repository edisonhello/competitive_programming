#include<iostream>
#include<queue>
#include<deque>
#include<stack>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[3][5005];

int main(){
    int n,m;while(cin>>n>>m,n){
        int sz=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>dp[i&1][j]; if(dp[i&1][j]==2)dp[i&1][j]=0;
                else{
                    dp[i&1][j]=min({dp[i&1][j-1],dp[!(i&1)][j],dp[!(i&1)][j-1]})+1;
                    sz=max(sz,dp[i&1][j]);
                }
            }
        }
        cout<<sz*sz<<endl;
    }
}
