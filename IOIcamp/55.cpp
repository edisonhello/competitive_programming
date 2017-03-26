#include<iostream>
#include<string>
#include<cstring>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;

string s[100005];
int dp[2][100005];
int count[100005];
int ans[1005];

int main(){
    int ts;cin>>ts;while(ts--){
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));

        int n,m,mn;cin>>n>>m;
        mn=min(n,m);
        for(int i=0;i<n;++i){
            memset(count,0,sizeof(count));
            cin>>s[i];
            for(int j=0;j<m;++j){
                if(s[i][j]=='.'){
                    ++dp[i&1][j];
                }
                else if(s[i][j]=='#'){
                    dp[i&1][j]=0;
                }

            }
        }
    }
}
