#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,brk;
    bool cov;
    edge(int u=0,int v=0,int brk=0,bool cov=0):u(u),v(v),brk(brk),cov(cov){}
};
vector<edge> edg;
vector<pair<int,int>> G[100005];

int albrk[100005],cfeid[100005],d[100005];

int main(){
    int n,m; cin>>n>>m;
    while(m--){
        int u,v,st;
        cin>>u>>v>>st;
        G[u].emplace_back(v,edg.size());
        G[v].emplace_back(u,edg.size());
        edg.emplace_back(u,v,!st);
    }
    memset(albrk,0x3f,sizeof(albrk)); albrk[1]=0;
    queue<int> q; q.push(1); d[1]=1;
    while(q.size()){
        for(auto &e:G[q.front()]){
            if(!d[e.first]){
                d[e.first]=d[q.front()]+1;
                albrk[e.first]=albrk[q.front()]+edg[e.second].brk;
                cfeid[e.first]=e.second;
                q.push(e.first);
            }
            else if(d[e.first]==d[q.front()]+1 and albrk[e.first]>albrk[q.front()]+edg[e.second].brk){
                d[e.first]=d[q.front()]+1;
                albrk[e.first]=albrk[q.front()]+edg[e.second].brk;
                cfeid[e.first]=e.second;
            }
        }
        q.pop();
    }
    for(int u=n;u!=1;u=edg[cfeid[u]].u==u?edg[cfeid[u]].v:edg[cfeid[u]].u){
        // cout<<"path on u: "<<u<<endl;
        edg[cfeid[u]].cov=1;
    }
    vector<edge> ope;
    for(auto &e:edg){
        if(e.brk and e.cov)ope.emplace_back(e.u,e.v,1);
        else if(!e.brk and !e.cov)ope.emplace_back(e.u,e.v,0);
    }
    cout<<ope.size()<<endl;
    for(auto &e:ope)cout<<e.u<<" "<<e.v<<" "<<e.brk<<endl;
}
