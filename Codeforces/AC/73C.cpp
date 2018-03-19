#include<bits/stdc++.h>
using namespace std;

int dp[111][111][28];
// dp[pos][change][last];

int c[333][333];

int main(){
    string s; int k;
    cin>>s>>k; int n=s.size();
    for(char &c:s)c-='a';
    memset(dp,0xb0,sizeof(dp));
    int ppp; cin>>ppp; while(ppp--){
        char u,v; cin>>u>>v;
        int cc; cin>>cc;
        c[u-'a'][v-'a']=cc;
    }
    for(int i=0;i<26;++i){
        dp[0][s[0]!=i][i]=0;
    }
    for(int i=1;i<n;++i){
        int j=0;
        for(int th=0;th<26;++th){
            if(th!=s[i])continue;
            for(int lz=0;lz<26;++lz){
                dp[i][j][th]=max(dp[i][j][th],dp[i-1][j][lz]+c[lz][th]);
            }
        }
        for(j=1;j<=k;++j){
            for(int th=0;th<26;++th){
                for(int lz=0;lz<26;++lz){
                    dp[i][j][th]=max(dp[i][j][th],dp[i-1][j-(th!=s[i])][lz]+c[lz][th]);
                }
            }
        }
    }
    int az=-(1<<30);
    for(int j=0;j<=k;++j){
        for(int lz=0;lz<26;++lz){
            az=max(az,dp[n-1][j][lz]);
        }
    }
    cout<<az<<endl;
}
