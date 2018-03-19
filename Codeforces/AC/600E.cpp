#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int c[100005],mx[100005];
ll ans[100005];
vector<int> G[100005];


void dfs(int now,int pa,map<int,int> *&rt){
    if(now!=pa && G[now].size()==1){
        (*rt)[c[now]]=1;
        ans[now]=c[now];
        mx[now]=1;
        return;
    }
    for(int i:G[now]){
        if(i==pa)continue;
        map<int,int> *nw=new map<int,int>();
        dfs(i,now,nw);
        if(mx[i]>mx[now]){
            mx[now]=mx[i];
            ans[now]=ans[i];
        }
        else if(mx[i]==mx[now]){
            ans[now]+=ans[i];
        }

        if(nw->size()>rt->size())swap(rt,nw);
        for(auto it:*nw){
            auto &iit=(*rt)[it.first];
            iit+=it.second;
            if(iit>mx[now]){
                mx[now]=iit;
                ans[now]=it.first;
            }
            else if(iit==mx[now]){
                if(it.second!=mx[now] && it.second!=0)ans[now]+=it.first;
            }
        }
    }
    auto &it=(*rt)[c[now]];
    ++it;
    if(it>mx[now]){
        mx[now]=it;
        ans[now]=c[now];
    }
    else if(it==mx[now]){
        ans[now]+=c[now];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>c[i];
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    map<int,int> *meow=new map<int,int>();
    dfs(1,1,meow);
    for(int i=1;i<=n;++i)cout<<ans[i]<<" "; cout<<endl;
}
