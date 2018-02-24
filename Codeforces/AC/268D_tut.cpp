#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1000000009;

void add(int &a,int b){a+=b; a>=mod?a-=mod:0;}

int dp[1001][32][32][32][2];

int main(){
    int n,h; cin>>n>>h;
    dp[0][0][0][0][1]=1;
    // dp[1][0][0][0][1]=1;
    // dp[0][0][0][0][1]=1;
    int ans=0;
    for(int i=0;i<n;++i){
        for(int a=0;a<=h+1;++a){
            for(int b=0;b<=h+1;++b){
                for(int c=0;c<=h+1;++c){
                    // myself
                    int ato=(a==h+1?h+1:a+1),bto=(b==h+1?h+1:b+1),cto=(c==h+1?h+1:c+1);
                    add(dp[i+1][ato][bto][cto][1],dp[i][a][b][c][1]);
                    add(dp[i+1][ato][bto][cto][0],dp[i][a][b][c][0]);
                    // a
                    add(dp[i+1][bto][cto][1][a<h],dp[i][a][b][c][1]);
                    add(dp[i+1][bto][cto][h+1][a<h],dp[i][a][b][c][0]);
                    // b
                    add(dp[i+1][cto][1][ato][b<h],dp[i][a][b][c][1]);
                    add(dp[i+1][cto][h+1][ato][b<h],dp[i][a][b][c][0]);
                    // c
                    add(dp[i+1][1][ato][bto][c<h],dp[i][a][b][c][1]);
                    add(dp[i+1][h+1][ato][bto][c<h],dp[i][a][b][c][0]);
                    
                }
            }
        }
    }
    for(int a=0;a<=h+1;++a){
        for(int b=0;b<=h+1;++b){
            for(int c=0;c<=h+1;++c){
                add(ans,dp[n][a][b][c][1]);
                if(a<h||b<h||c<h)add(ans,dp[n][a][b][c][0]);
            }
        }
    }
    cout<<ans<<endl;
}
