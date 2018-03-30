#include<bits/stdc++.h>
using namespace std;

int main(){
    int ts; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        #define zzz pair<int,pair<int,pair<string,int>>>
        priority_queue<zzz,vector<zzz>,greater<zzz>> pq;
        for(int i=0;i<n;++i){
            string s; int t; cin>>s>>t;
            pq.push({t,make_pair(i,make_pair(s,t))});
        }
        int cnt=0;
        while(cnt<m){
            ++cnt;
            auto t=pq.top(); pq.pop();
            cout<<t.first<<" "<<t.second.second.first<<endl;
            pq.push({t.first+t.second.second.second,t.second});
        }
    }
}
