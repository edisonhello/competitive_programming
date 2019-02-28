#include<bits/stdc++.h>
using namespace std;

pair<int,int> pr[100005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t; cin>>n>>t;
    for(int i=0;i<n;++i)cin>>pr[i].first>>pr[i].second;
    sort(pr,pr+n);
    int nt=0,ans=0,cur=0,last=-1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;++i){
        if(nt+pr[i].first>t){
            pq.emplace(pr[i].second,pr[i].first-pr[i].second);
        }
        else{
            nt+=pr[i].first;
            cur+=2;
            ans+=2;
            last=i;
        }
    }
    // cout<<ans<<endl;
    while(pq.size() && nt+pq.top().first<=t){
        auto p=pq.top(); pq.pop();
        nt+=p.first;
        ++cur;
        ans=max(ans,cur);
        pq.emplace(p.second,t+1);
    }
    // cout<<ans<<endl;
    while(last>=0){
        cur-=2;
        nt-=pr[last].first;
        pq.emplace(pr[last].second,pr[last].first-pr[last].second);
        --last;
        while(pq.size() && nt+pq.top().first<=t){
            auto p=pq.top(); pq.pop();
            nt+=p.first;
            ++cur;
            ans=max(ans,cur);
            pq.emplace(p.second,t+1);
        }
    }
    cout<<ans<<endl;
}
