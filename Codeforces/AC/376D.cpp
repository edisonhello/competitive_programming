#include<bits/stdc++.h>
using namespace std;
#define vint vector<int> 
#define pb push_back

int dp[5555][5555];
string mp[5555];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<n;++i)cin>>mp[i];
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mp[i][j]=='1'){
                if(j)dp[i][j]+=dp[i][j-1];
                ++dp[i][j];
            }
        }
    }
    int mx=0;
    for(int i=0;i<m;++i){
        vint v;
        for(int j=0;j<n;++j)if(dp[j][i])v.pb(dp[j][i]);
        sort(v.begin(),v.end(),greater<int>());
        int cnt=0;
        for(int &i:v){
            ++cnt;
            mx=max(mx,cnt*i);
        }
    }
    cout<<mx<<endl;
}
