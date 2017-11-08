#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
    edge(int u=0,int v=0,int f=0):u(u),v(v),f(f){}
};
vector<edge> edg;
vector<int> G[222];
int a[111],b[111];

void ae(int u,int v,int f){
    G[u].push_back(edg.size());
    edg.emplace_back(u,v,f);
    G[v].push_back(edg.size());
    edg.emplace_back(v,u,0);
}
bitset<222> inq;
int bn[222],cf[222];
bool ww(int st,int ed,int &nf){
    memset(bn,0,sizeof(bn)); bn[st]=123456789;
    inq.reset(); inq[st]=1; queue<int> q; q.push(st);
    while(q.size()){
        for(int id:G[q.front()]){
            if(min(edg[id].f,bn[q.front()])>bn[edg[id].v]){
                bn[edg[id].v]=min(edg[id].f,bn[q.front()]);
                cf[edg[id].v]=id;
                if(!inq[edg[id].v]){
                    inq[edg[id].v]=1;
                    q.push(edg[id].v);
                }
            }
        }
        inq[q.front()]=0; q.pop();
        if(bn[ed])break;
    }
    if(!bn[ed])return 0;
    for(int u=ed;u!=st;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[ed];
        edg[cf[u]^1].f+=bn[ed];
    }
    nf+=bn[ed];
    return 1;
}
int flow(int st,int ed){
    int ans=0;
    while(ww(st,ed,ans));
    return ans;
}
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>a[i],ae(201,i,1);
    int m; cin>>m;
    for(int i=0;i<m;++i)cin>>b[i],ae(i+100,200,1);

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(abs(a[i]-b[j])<=1){
                ae(i,j+100,1);
            }
        }
    }

    cout<<flow(201,200)<<endl;
}
