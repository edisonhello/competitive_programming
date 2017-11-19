#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    long long tot=0,aa=0;
    for(int i=0;i<n;++i)cin>>aa,tot+=aa;
    priority_queue<int,vector<int>,less<int>> pq;
    for(int i=0;i<n;++i)cin>>aa,pq.push(aa);
    tot-=pq.top(); pq.pop(); tot-=pq.top();
    if(tot<=0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
