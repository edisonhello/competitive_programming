#include<bits/stdc++.h>
using namespace std;

int dp[200005][5];
int cf[200005][5];
int id[266];

int main(){
    int n; cin>>n;
    string s; cin>>s;
    s=" "+s;
    
    id['R']=1;
    id['G']=2;
    id['B']=3;

    memset(dp,0x3f,sizeof(dp));
    dp[0][1]=0; dp[0][2]=0; dp[0][3]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j){
            for(int k=1;k<=3;++k){
                if(j==k)continue;
                int v=dp[i-1][j]+(id[s[i]]!=k);
                if(v<dp[i][k]){
                    dp[i][k]=v;
                    cf[i][k]=j;
                }
            }
        }
    }
    int vv=min(dp[n][1],min(dp[n][2],dp[n][3]));
    cout<<vv<<endl;
    int i=n,j;
    if(dp[i][1]==vv){
        j=1;
    }
    else if(dp[i][2]==vv)j=2;
    else j=3;
    string zz;
    while(i){
        if(j==1)zz+="R";
        if(j==2)zz+="G";
        if(j==3)zz+="B";
        tie(i,j)=make_pair(i-1,cf[i][j]);
    }
    reverse(zz.begin(),zz.end());
    cout<<zz<<endl;
}
