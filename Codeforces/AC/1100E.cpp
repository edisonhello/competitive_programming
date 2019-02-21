#include<bits/stdc++.h>
using namespace std;

struct edge{
    int id,u,v,w;
};
bool operator<(const edge &a,const edge &b){ return tie(a.w,a.u,a.v)<tie(b.w,b.u,b.v); }

int n,m;

vector<edge> edg;
vector<int> G[100005];
int ind[100005];

int ok(int li){
    for(int i=1;i<=n;++i)G[i].clear();
    memset(ind,0,sizeof(ind));
    for(auto &e:edg){
        if(e.w<=li)continue;
        G[e.u].push_back(e.v);
        ++ind[e.v];
    }
    int cq=0;
    queue<int> q;
    for(int i=1;i<=n;++i)if(!ind[i]){
        q.push(i);
        ++cq;
    }
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            --ind[i];
            if(!ind[i]){
                q.push(i);
                ++cq;
            }
        }
    }
    return cq==n;
}

int incq[100005];
void build(int li){
    for(int i=1;i<=n;++i)G[i].clear();
    memset(ind,0,sizeof(ind));
    for(auto &e:edg){
        if(e.w<=li)continue;
        G[e.u].push_back(e.v);
        ++ind[e.v];
    }
    int cq=0;
    queue<int> q;
    for(int i=1;i<=n;++i)if(!ind[i]){
        q.push(i);
        ++cq;
        incq[i]=cq;
    }
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i:G[now]){
            --ind[i];
            if(!ind[i]){
                q.push(i);
                ++cq;
                incq[i]=cq;
            }
        }
    }
    vector<int> ch;
    for(auto &e:edg){
        if(e.w>li)break;
        if(incq[e.u]<incq[e.v])continue;
        ch.push_back(e.id);
    }
    cout<<ch.size()<<endl;
    for(int i:ch)cout<<i<<" "; cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    edg.resize(m);
    for(int i=0;i<m;++i){
        cin>>edg[i].u>>edg[i].v>>edg[i].w;
        edg[i].id=i+1;
    }
    sort(edg.begin(),edg.end());
    int L=0,R=1e9;
    while(R>L){
        int M=(L+R)>>1;
        if(ok(M))R=M;
        else L=M+1;
    }
    cout<<L<<" ";
    build(L);
}
