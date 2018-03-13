/* tutorial by commonc */

#include<bits/stdc++.h>
using namespace std;

int n,a[1000006],dp[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int q; cin>>q; while(q--){
        int k; cin>>k;
        deque<int> dq; dq.push_back(1);
        for(int i=2;i<=n;++i){
            while(i-dq.front()>k)dq.pop_front();
            dp[i]=dp[dq.front()]+(a[dq.front()]<=a[i]);
            while(dq.size() && (dp[i]<dp[dq.back()] || (dp[i]==dp[dq.back()] && a[i]>=a[dq.back()])))dq.pop_back();
            dq.push_back(i);
        }
        cout<<dp[n]<<'\n';
    }
}
