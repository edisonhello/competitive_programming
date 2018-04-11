#include<bits/stdc++.h>
using namespace std;

set<int> G[100005];
map<pair<int,int>,pair<int,int>> num;
int in[100005],low[100005],dt;
stack<pair<int,int>> st;
set<int> bel[100005];
int cto,csz[100005];

void dfs(int now,int pa){
    in[now]=low[now]=++dt;
    while(G[now].size()){
        int i=*G[now].begin();
        G[now].erase(G[now].begin());
        if(i==pa)continue;
        G[i].erase(now);
        st.push({now,i});
        if(in[i]){
            low[now]=min(low[now],in[i]);
        }
        else{
            dfs(i,now);
            low[now]=min(low[now],low[i]);
            if(low[i]==in[now]){
                int tag=0;
                do{
                    auto p=st.top(); st.pop();
                    ////  cout<<"now: "<<now<<" , ["<<p.first<<","<<p.second<<endl;
                    if(p.first==now && p.second==i)++tag;
                    bel[p.first].insert(cto);
                    bel[p.second].insert(cto);
                    auto it=num.find(p);
                    if(it==num.end()){
                        swap(p.first,p.second);
                        it=num.find(p);
                    }
                    it->second.second=cto;
                    --csz[cto];
                }while(tag<1);
                ++cto;
            }
            else if(low[i]>in[now])st.pop();
        }
    }
}

int main(){
    int n,m; cin>>n>>m;
    for(int i=0,u,v;i<m;++i){
        cin>>u>>v;
        G[u].insert(v);
        G[v].insert(u);
        num[make_pair(u,v)]={i+1,-1};
    }
    for(int i=1;i<=n;++i){
        if(in[i])continue;
        dfs(i,i);
    }
    /* for(int i=1;i<=n;++i)cout<<i<<" "<<in[i]<<" "<<low[i]<<endl;
    for(int i=1;i<=n;++i){
        cout<<i;
        for(int z:bel[i])cout<<" "<<z;
        cout<<endl;
    } */
    for(int i=1;i<=n;++i)for(int j:bel[i])++csz[j];
    set<int> ans;
    for(auto &p:num){
        if(p.second.second==-1)continue;
        if(csz[p.second.second]==0)ans.insert(p.second.first);
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<" ";
}
