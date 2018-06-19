#include<bits/stdc++.h>
using namespace std;

int produce[27];
int dp[3][9][9];

int main(){
    int n; cin>>n;
    string s; cin>>s;
    for(char &c:s){
        if(c=='M')c=0;
        else if(c=='B')c=1;
        else c=2;
    }
    s='z'+s;
    for(int i=0;i<3;++i)for(int j=0;j<3;++j)for(int k=0;k<3;++k){
        set<int> st; st.insert(i); st.insert(j); st.insert(k);
        produce[i*9+j*3+k]=st.size();
        // cout<<i<<" "<<j<<" "<<k<<" "<<st.size()<<endl;
    }
    for(int i=1;i<=n;++i){
        for(int j=0;j<9;++j){
            for(int k=0;k<9;++k){
#define up(a,b) a=max(a,b)
                up(dp[i&1][(j*3+s[i])%9][k],dp[(i-1)&1][j][k]+produce[j*3+s[i]]);
                up(dp[i&1][j][(k*3+s[i])%9],dp[(i-1)&1][j][k]+produce[k*3+s[i]]);
            }
        }
    }
    int mx=0;
    for(int j=0;j<9;++j)for(int k=0;k<9;++k){
        mx=max(mx,dp[n&1][j][k]);
    }
    cout<<mx-6<<endl;
}
// in virtual AC
