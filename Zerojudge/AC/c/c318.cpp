#include<bits/stdc++.h>
using namespace std;



int main(){
    int n,t; cin>>n>>t;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
    while(n--){
        int s,d; cin>>s>>d;
        pq.push({s,d});
    }
    int ans=0;
    while(t--){
        auto p=pq.top(); pq.pop();
        ans+=p.first;
        p.first-=p.second;
        pq.push(p);
    }
    cout<<ans<<endl;
}
