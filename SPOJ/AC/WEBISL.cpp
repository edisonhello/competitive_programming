#include<bits/stdc++.h>
using namespace std;


int low[100005],in[100005],dfst,instack[100005],sccs,bel[100005];
stack<int> st;
vector<int> memb[100005],G[100005];

void tarj(int now){
    low[now]=in[now]=++dfst;
    instack[now]=1; st.push(now);
    for(int i:G[now]){
        if(!in[i]){
            tarj(i);
            low[now]=min(low[now],low[i]);
        }
        else if(instack[i]){
            low[now]=min(low[now],in[i]);
        }
    }
    if(low[now]==in[now]){
        while(1){
            int u=st.top(); st.pop();
            instack[u]=0;
            bel[u]=sccs;
            memb[sccs].push_back(u);
            if(u==now)break;
        }
        ++sccs;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
    }
    for(int i=0;i<n;++i){
        if(!in[i])tarj(i);
    }
    for(int i=0;i<sccs;++i)sort(memb[i].begin(),memb[i].end());
    for(int i=0;i<n;++i)cout<<memb[bel[i]][0]<<'\n';
}
