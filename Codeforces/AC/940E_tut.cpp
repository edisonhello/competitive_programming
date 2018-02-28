#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100005],dp[100005],pre[100005];


int main(){
    int n,c; cin>>n>>c;
    for(int i=1;i<=n;++i)cin>>a[i];
    deque<int> dq;
    for(int i=1;i<=n;++i){
        dp[i]=dp[i-1]+a[i];
        pre[i]=pre[i-1]+a[i];
        while(dq.size() && a[dq.back()]>=a[i])dq.pop_back();
        dq.push_back(i);
        if(i>=c){
            if(dq.front()==i-c)dq.pop_front();
            dp[i]=min(dp[i],dp[i-c]+pre[i]-pre[i-c]-a[dq.front()]);
        }
    }
    cout<<dp[n]<<endl;
}
