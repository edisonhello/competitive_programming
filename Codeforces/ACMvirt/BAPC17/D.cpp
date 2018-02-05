#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pli pair<long long,int>

vector<pair<int,int>> G[100005];
ll d[100005];
bitset<100005> v;
int cf[100005];
void dij(int s){
    priority_queue<pli,vector<pli>,greater<pli>> pq;
    pq.push({0,s});
    memset(d,0x3f,sizeof(d)); d[s]=0;
    while(pq.size()){
        while(pq.size() && v[pq.top().second])pq.pop();
        if(pq.empty())break;
        auto np=pq.top().second; pq.pop();
        v[np]=1;
        for(auto edg:G[np]){
            if(d[edg.first]>d[np]+edg.second){
                cf[edg.first]=np;
                d[edg.first]=d[np]+edg.second;
                pq.push({d[edg.first],edg.first});
            }
        }
    }
}

stack<int> ans;
bool dfs(int now){
    if(now==1){
        ans.push(1);
        return 1;
    }
    v[now]=1;
    for(auto edg:G[now]){
        if(edg.first==cf[now])continue;
        if(v[edg.first])continue;
        if(dfs(edg.first)){
            ans.push(now);
            return 1;
        }
    }
    return 0;
}

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,d; cin>>u>>v>>d;
        G[u].emplace_back(v,d);
        G[v].emplace_back(u,d);
    }
    dij(1);
    v.reset();
    dfs(0);
    if(ans.empty())cout<<"impossible"<<endl;
    else{
        cout<<ans.size();
        while(ans.size()){
            cout<<" "<<ans.top();
            ans.pop();
        } cout<<endl;
    }
}
