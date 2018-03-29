#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,w;
};
vector<edge> edg;

int __dp[50005],__prv[50005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        edg.push_back({u,v,w});
    }
    sort(edg.begin(),edg.end(),[&](const edge &a,const edge &b){return a.w<b.w;});
    int mx=0;
    int *dp=__dp,*tmp=__prv;
    int pw=0;
    vector<int> upd;
    for(auto i:edg){
        if(pw!=i.w){
            for(int i:upd)dp[i]=max(dp[i],tmp[i]);
            upd.clear();
        }
        int dpu=dp[i.u],dpv=dp[i.v];
        tmp[i.u]=max(max(dpu,dpv+1),tmp[i.u]);
        tmp[i.v]=max(max(dpv,dpu+1),tmp[i.v]);
        mx=max(mx,max(tmp[i.u],tmp[i.v]));
        upd.push_back(i.u);
        upd.push_back(i.v);
        // cout<<dpu<<" "<<dpv<<endl;
        pw=i.w;
    }
    cout<<mx<<endl;
}
