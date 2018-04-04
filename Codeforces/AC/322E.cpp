#include<bits/stdc++.h>
using namespace std;

vector<int> G[100005],work;
bitset<100005> v;
int tot,sz[100005],mxson[100005];

void dfs1(int now,int pa){
    sz[now]=1; mxson[now]=0;
    ++tot; work.push_back(now);
    for(int i:G[now]){
        if(i==pa)continue;
        if(v[i])continue;
        dfs1(i,now);
        sz[now]+=sz[i];
        mxson[now]=max(mxson[now],sz[i]);
    }
}

char ans[100005];

void cende(int now,char lev){
    // cout<<"cende "<<now<<endl;
    tot=0;
    work.clear();
    dfs1(now,now);
    int cen=-1;
    for(int i:work)if(max(tot-sz[i],mxson[i])<=tot/2)cen=i;
    for(int i:work)v[i]=0;
    if(cen==-1){
        ans[now]=lev;
        return;
    }
    ans[cen]=lev;
    v[cen]=1;
    // cout<<"cen: "<<cen<<endl;
    for(int i:G[cen]){
        if(!v[i])cende(i,lev+1);
    }
}

int main(){
    int n; cin>>n;
    for(int i=1;i<n;++i){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cende(1,'A');
    for(int i=1;i<=n;++i)cout<<ans[i]<<" ";
}
