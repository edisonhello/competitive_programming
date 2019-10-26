#include<bits/stdc++.h>
#define ignore ghiujoefid
using namespace std;

map<pair<int,int>,int> edgeans,edgeid;
vector<int> G[200005];
int deg[200005],o[200005],ans[200005],ignore[200005];

void dfs(int now,int pa,int uec){
    if(ignore[now]){
        for(int i:G[now])if(i!=pa){
            edgeans[minmax(now,i)]=1;
            dfs(i,now,1);
        }
    }
    else{
        int id=1; if(uec==id)++id;
        for(int i:G[now])if(i!=pa){
            edgeans[minmax(now,i)]=id;
            dfs(i,now,id);
            ++id; if(uec==id)++id;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++deg[u]; ++deg[v];
        edgeid[minmax(u,v)]=i;
    }
    for(int i=1;i<=n;++i)o[i]=i;
    sort(o+1,o+1+n,[&](const int &a,const int &b){ return deg[a]>deg[b]; });
    int ref=deg[o[k+1]];
    cout<<ref<<endl;
    for(int i=1;i<=k;++i)ignore[o[i]]=1;
    dfs(1,0,0);
    for(auto &p:edgeid){
        ans[p.second]=edgeans[p.first];
    }
    for(int i=1;i<n;++i)cout<<ans[i]<<" "; cout<<endl;
}
