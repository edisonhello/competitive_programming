#include<bits/stdc++.h>
using namespace std;
#define vint vector<int>
#define PQ priority_queue


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;cin>>n;
    PQ<int,vint,greater<int>> pq;
    for(int i=0;i<n;++i){
        int t;cin>>t;
        pq.push(t);
    }
    int ans=0;
    while((int)pq.size()>1){
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        pq.push(a+b);
        ans+=a+b;
    }
    cout<<ans<<'\n';
}
