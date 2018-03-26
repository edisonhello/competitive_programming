#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> G[100005];
vector<int> ans,t;


int deg[100005],n;

bool test(int ttt){
    memset(deg,0,sizeof(deg));
    t.clear();
    for(int i=1;i<=n;++i){
        for(auto p:G[i]){
            if(p.second<=ttt)++deg[p.first];
        }
    }
    int cnt=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;++i)if(deg[i]==0)pq.push(i);
    while(pq.size()){
        ++cnt;
        int now=pq.top(); pq.pop();
        t.push_back(now);
        for(auto p:G[now]){
            if(p.second<=ttt){
                --deg[p.first];
                if(deg[p.first]==0)pq.push(p.first);
            }
        }
    }
    return cnt==n;
}

int main(){
    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);
    int m; cin>>n>>m;
    for(int i=1;i<=m;++i){
        int x; cin>>x; int prv; cin>>prv; --x;
        while(x--){
            int nw; cin>>nw;
            G[prv].emplace_back(nw,i);
            prv=nw;
        }
    }
    // for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end(),greater<pair<int,int>>());
    int L=0,R=m;
    while(R>L){
        int mid=(L+R+1)>>1;
        if(test(mid))L=mid,ans=t;
        else R=mid-1;
    }
    for(int i:ans)cout<<i<<" \n"[i==ans.back()];
}
