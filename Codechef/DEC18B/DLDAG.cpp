#include<bits/stdc++.h>
using namespace std;

vector<int> G[1000006];
int indeg[1000006];
int cval[1000006];

void dfs(int now){
    cval[now]=1;
    for(int i:G[now]){
        if(!cval[i])dfs(i);
        cval[now]+=cval[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[v].push_back(u);
        ++indeg[u];
    }
    for(int i=1;i<=n;++i)dfs(i);
    for(int i=1;i<=n;++i)cval[i]+=G[i].size();
    auto cmp=[&](const int &a,const int &b){ return cval[a]>cval[b]; };
    priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
    for(int i=1;i<=n;++i)if(indeg[i]==0)pq.push(i);
    vector<int> ans; 
    int steps=0;
    while(pq.size()){
        int pa=pq.top(); pq.pop();
        ++steps;
        if(pq.size()){
            int pb=pq.top(); pq.pop();
            ans.push_back(2);
            ans.push_back(pa);
            ans.push_back(pb);
            for(int i:G[pa]){
                --indeg[i];
                if(indeg[i]==0)pq.push(i);
            }
            for(int i:G[pb]){
                --indeg[i];
                if(indeg[i]==0)pq.push(i);
            }
        }
        else{
            ans.push_back(1);
            ans.push_back(pa);
            for(int i:G[pa]){
                --indeg[i];
                if(indeg[i]==0)pq.push(i);
            }
        }
    }
    cout<<steps<<endl;
    for(auto it=ans.begin();it!=ans.end();++it){
        if(*it==1){
            cout<<"1 "<<*++it<<'\n';
        }
        else{
            cout<<"2 "<<*++it<<" "<<*++it<<'\n';
        }
    }
}
