#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005];
int d[100005];

void dfs(int now,int pa){
    for(int i:G[now]){
        if(i==pa)continue;
        d[i]=d[now]+1;
        dfs(i,now);
    }
}

priority_queue<int,vector<int>,less<int>> pq;
int ln[100005];
void dfs1(int now,int pa){
    int lest=0;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        lest=max(lest,ln[i]);
    }
    for(int i:G[now]){
        if(i==pa)continue;
        if(lest==ln[i]){
            ln[now]=lest+1;
            lest=1e9;
        }
        else{
            pq.push(ln[i]+1);
        }
    }
}

int ans[100005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    int d1=max_element(d+1,d+1+n)-d;
    dfs1(d1,d1);
    pq.push(ln[d1]);
    ans[1]=1;
    for(int i=2;i<=n;++i){
        ans[i]+=ans[i-1];
        if(pq.size())ans[i]+=pq.top(),pq.pop();
    }
    for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
}
