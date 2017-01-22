#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> G[1000006];
int sz[1000006],csz[1000006];

void dfs(int now,int fr){
    sz[now]=1;csz[now]=0;
    for(int i:G[now]){
        if(i==fr)continue;
        dfs(i,now);
        sz[now]+=sz[i];
        csz[now]=max(csz[now],sz[i]);
    }
    csz[now]=max(csz[now],n-sz[now]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1,a,b;i<n;++i){
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs(0,0);
    int mn=99999999;
    for(int i=0;i<n;++i)mn=min(mn,csz[i]);
    cout<<mn<<endl;
}
