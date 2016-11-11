#include<iostream>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
string m[15];
int n;
int dp[15][15];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){cin>>m[i];m[i]="X"+m[i]+"X";}
    m[0]="XXXXXXXXXXXXXX";
    m[1][1]='0';
    for(int i=2;i<=n+1;++i)dp[0][i]=dp[n+1][i]=dp[i][0]=dp[i][n+1]=-1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(m[i][j]=='X'){
                dp[i][j]=-1;
            }
            else if(dp[i-1][j]==-1 && dp[i][j-1]==-1){
                dp[i][j]=-1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                dp[i][j]+=m[i][j]-'0';
            }
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if(dp[n][n]==-1)cout<<"X"<<endl;
    else cout<<dp[n][n]+'0'-'B'<<endl;
}
