#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,c;
};

vector<edge> edg;
int djs[10005],spc[10005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}

int main(){
    int t; cin>>t; while(t--){
        int n,t,k; cin>>n>>t>>k;
        edg.clear();
        for(int i=1;i<=n;++i)djs[i]=i;
        for(int i=1;i<=n;++i)spc[i]=0;
        for(int i=1;i<n;++i){
            int u,v,c; cin>>u>>v>>c;
            edg.push_back({u,v,c});
        }
        for(int i=0,tt;i<t;++i){
            cin>>tt;
            spc[tt]=1;
        }
        sort(edg.begin(),edg.end(),[](const edge &a,const edge &b){return a.c>b.c;});
        vector<int> can;
        for(edge &e:edg){
            int u=F(e.u),v=F(e.v);
            if(spc[u] && spc[v])can.push_back(e.c);
            else if(spc[u])djs[v]=u;
            else djs[u]=v;
        }
        reverse(can.begin(),can.end());
        int ans=0;
        for(int i=0;i<k;++i)ans+=can[i];
        cout<<ans<<endl;
    }
}
