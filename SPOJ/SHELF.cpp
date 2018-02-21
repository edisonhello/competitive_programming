#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[100005],h[100005],w[100005],wpre[100005];

int main(){
    int n,l; cin>>n>>l;
    multiset<ll> vals;
    deque<int> deq;
    vals.insert(0);
    deq.push_back(0); h[0]=1000000009;
    for(int i=1;i<=n;++i){
        cin>>h[i]>>w[i];
        wpre[i]=wpre[i-1]+w[i];
        while(deq.size() && wpre[i]-wpre[deq.front()-1]>l){
            auto it=vals.find(dp[
        }
        while(h[deq.back()]<h[i]){
            // vals.erase(dp[deq.back()-1]+h[deq.back()]);
            vals.erase(
            deq.pop_back();
        }
        while(wpre[i]-wpre[deq.front()-1]>l){
            
        }
        dp[i]=*vals.begin();
        deq.push_back(i);
        vals.insert(dp[i-1]+h[i]);
    }
}
