#include<bits/stdc++.h>
using namespace std;
#define eb emplace_back

vector<int> pos[1000006];
vector<pair<int,int>> dp[1000006];

void clear(int x){
    sort(dp[x].begin(),dp[x].end(),greater<pair<int,int>>());
    if(dp[x].size()>2u)dp[x].resize(2);
}

int h[1000006];

int main(){
    int n; cin>>n;
    vector<int> v(n);
    for(int &i:v)cin>>i;
    v.resize(unique(v.begin(),v.end())-v.begin());
    vector<int> u=v;
    sort(u.begin(),u.end());
    u.resize(unique(u.begin(),u.end())-u.begin());
    for(int &i:v)i=upper_bound(u.begin(),u.end(),i)-u.begin();
    n=v.size();
    for(int i=1;i<=n;++i)h[i]=v[i-1];
    // cout<<"new h: "; for(int i=1;i<=n;++i)cout<<h[i]<<" "; cout<<endl;
    for(int i=1;i<=n;++i)pos[h[i]].eb(i);
    dp[0].eb(0,-1);
    dp[0].eb(0,-1);
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        for(int x:pos[i]){
            if(h[x+1]!=h[x]+1)continue;
            // cout<<"x: "<<x<<endl;
            if(pos[i].size()>1u && dp[i-1][0].second==x-1){
                dp[i].eb(dp[i-1][1].first+1,x);
            }
            else{
                dp[i].eb(dp[i-1][0].first+1,x);
            }
        }
        clear(i);
    }
    cout<<n-1-dp[n][0].first<<endl;
}
