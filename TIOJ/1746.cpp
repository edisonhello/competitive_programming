#include<bits/stdc++.h>
using namespace std;

void spec(int n,int k){
    if(n==1)exit((cout<<k<<endl,0));
    if(n==2)exit((cout<<k+1<<endl,0));
}

bitset<100005> isdia;
vector<int> G[100005];
int dis[100005],p[100005];

void dfs1(int now,int pa){
    p[now]=pa;
    for(int i:G[now]){
        if(i==pa)continue;
        dis[i]=dis[now]+1;
        dfs1(i,now);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    spec(n,k);
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,0);
    { int far=max_element(dis+1,dis+1+n)-dis; dis[far]=0; dfs1(far,0); }
    int d1=max_element(dis+1,dis+1+n)-dis,d2=d1; isdia[d1]=1;
    while(p[d2]){
        d2=p[d2];
        isdia[d2]=1;
    }
}
