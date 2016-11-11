// #include<bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second

string a,b;
int dp[405][405];

int LCS(){
    for(int i=1;i<=(int)a.length();i++){
        for(int j=1;j<=(int)b.length();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[a.length()][b.length()];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while(cin>>a>>b){
        int lcs = LCS();
        cout<<lcs<<'\n';
    }
}
