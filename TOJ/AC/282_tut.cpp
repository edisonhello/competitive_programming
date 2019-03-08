#include<bits/stdc++.h>
using namespace std;

vector<int> lo;
vector<long long> pre;
vector<pair<int,int>> hi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t; cin>>n>>t;
    for(int i=0;i<n;++i){
        int a,b; cin>>a>>b;
        int c=a-b;
        if(b<=c)lo.push_back(b),lo.push_back(c);
        else hi.emplace_back(b,c);
    }
    sort(lo.begin(),lo.end());
    sort(hi.begin(),hi.end(),[&](const pair<int,int> &a,const pair<int,int> &b){ return a.first+a.second<b.first+b.second; });
    pre.resize(lo.size()+1,0);
    for(int i=1;i<=int(lo.size());++i)pre[i]=pre[i-1]+lo[i-1];
    int ans=0;
    int hiptr=0;
    long long hit=0;
    auto update=[&](const long long t,const int offset=0){
        // cout<<t<<" "<<offset<<" "<<hiptr<<endl;
        if(t<0)return;
        if(t==0){ ans=max(ans,hiptr*2+offset); return; }
        int L=0,R=lo.size();
        while(L<R){
            int M=(L+R+1)>>1;
            if(pre[M]<=t)L=M;
            else R=M-1;
        }
        // cout<<"update use time "<<t<<" , get "<<L<<" low, have
        ans=max(ans,hiptr*2+L+offset);
    };
    multiset<int> getone;
    priority_queue<int,vector<int>,less<int>> delone;
    for(auto &p:hi)getone.insert(p.first);
    update(t-hit);
    if(getone.size())update(t-hit-*getone.begin(),1);
    if(delone.size())update(t-hit+delone.top(),-1);
    while(hiptr<int(hi.size())){
        hit+=hi[hiptr].first+hi[hiptr].second;
        getone.erase(getone.find(hi[hiptr].first));
        delone.push(hi[hiptr].second);
        ++hiptr;
        update(t-hit);
        if(getone.size())update(t-hit-*getone.begin(),1);
        if(delone.size())update(t-hit+delone.top(),-1);
    }
    cout<<ans<<endl;
}
