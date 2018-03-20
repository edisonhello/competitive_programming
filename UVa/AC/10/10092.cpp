#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f; 
};
vector<edge> edg;
vector<int> G[1234];

void ae(int s,int t,int f){
    G[s].push_back(edg.size());
    edg.push_back({s,t,f});
    G[t].push_back(edg.size());
    edg.push_back({t,s,0});
}

int bn[1234],cf[1234];
bitset<1234> inq;

bool flow(int s,int t,int &nf){
    inq.reset(); inq[s]=1;
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    queue<int> q; q.push(s);
    while(q.size() && !bn[t]){
        int now=q.front(); q.pop(); inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f && bn[e.v]<min(bn[now],e.f)){
                bn[e.v]=min(bn[now],e.f);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!bn[t])return 0;
    nf+=bn[t];
    for(int u=t;u!=s;u=edg[cf[u]].u){
        edg[cf[u]].f-=bn[t];
        edg[cf[u]^1].f+=bn[t];
    }
    return 1;
}

int flow(int s,int t){
    int f=0;
    while(flow(s,t,f));
    return f;
}

int main(){
    int n,m; while(cin>>m>>n,n){
        edg.clear();
        for(int i=0;i<1234;++i)G[i].clear();
        int ptr=1;
        int sum=0;
        for(int i=0;i<m;++i){
            int t; cin>>t;
            ae(++ptr,1,t);
            sum+=t;
        }
        vector<int> track;
        for(int i=0;i<n;++i){
            int pid=++ptr;
            int t; cin>>t; while(t--){
                int t; cin>>t; 
                track.push_back(edg.size());
                ae(pid,t+1,1);
            }
            ae(0,pid,1);
        }
        int f=flow(0,1);
        vector<int> li[22];
        if(f==sum){
            cout<<"1\n";
            for(int eid:track){
                if(edg[eid].f==0){
                    li[edg[eid].v-1].push_back(edg[eid].u-1-m);
                }
            }
            for(int i=1;i<=m;++i){
                for(int ii:li[i])cout<<ii<<" ";
                cout<<'\n';
            }
        }
        else cout<<"0\n";
    }
}
