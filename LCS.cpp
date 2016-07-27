#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define PB(x) push_back(x)
#define vint vector<int>
#define rz(x) resize(x+5)
#define X first
#define Y second

string a,b;
int dp[2][4005][4005];

int LCS0(){
    for(int i=1;i<=(int)a.length();i++){
        for(int j=1;j<=(int)b.length();j++){
            if(a[i-1]==b[j-1]){
                dp[0][i][j]=dp[0][i-1][j-1]+1;
            }
            else{
                dp[0][i][j]=max(dp[0][i-1][j],dp[0][i][j-1]);
            }
        }
    }
    return dp[0][a.length()][b.length()];
}
int LCS1(){
    for(int i=1;i<=(int)a.length();i++){
        for(int j=1;j<=(int)b.length();j++){
            if(a[i-1]==b[j-1]){
                dp[1][i][j]=dp[1][i-1][j-1]+1;
            }
            else{
                dp[1][i][j]=max(dp[1][i-1][j],dp[1][i][j-1]);
            }
        }
    }
    return dp[1][a.length()][b.length()];
}

int GCD(int q,int w){
    while(q&&w){
        if(q<w)swap(q,w);
        q -= (q/w)*w;
    }
    return w;
}

void rev(){
    for(int i=0;i<b.length();i++){
        if(b[i]=='A')b[i]='T';
        else if(b[i]=='T')b[i]='A';
        else if(b[i]=='G')b[i]='C';
        else if(b[i]=='C')b[i]='G';
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>a>>b;

    int lcs1 = LCS0();
    rev();
    // cout<<b<<endl;
    int lcs2 = LCS1();
    int lcs = max(lcs1,lcs2);
    // cout<<lcs1<<" "<<lcs2<<endl;
    int s = 2*lcs;
    int m = (int)(a.length()+b.length());
// cout<<s<<" "<<m<<endl;
    if(s==0){
        cout<<"0/"<<m<<'\n';
        return 0;
    }
    int gcd=GCD(s,m);
    if(gcd){
        s/=gcd;
        m/=gcd;
    }
    cout<<s<<"/"<<m<<'\n';
}
