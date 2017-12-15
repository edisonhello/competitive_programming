// copy from TIOJ 1146
#include<iostream>
#include<cstring>
using namespace std;
bool con[31][31];
int dp[31][51];
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,md,st,ed,tot;
    while(cin>>n){
    memset(con,0,sizeof(con));
    memset(dp,0,sizeof(dp));
    string s;
    for(int i=1,j;i<=n;++i){
        cin>>s;
        for(j=0;j<n;++j){
            if(s[j]=='1')con[i][j+1]=1;
        }
    }
    cin>>st>>ed>>md;
    dp[0][st]=1;
    tot=0;
    for(int i=1,j,k;i<=md;++i){
        for(j=1;j<=n;++j){
            if(!dp[i-1][j])continue;
            for(k=1;k<=n;++k){
                if(con[j][k])dp[i][k]+=dp[i-1][j];
            }
        }
        tot+=dp[i][ed];
    }
    cout<<tot<<endl;
}}
