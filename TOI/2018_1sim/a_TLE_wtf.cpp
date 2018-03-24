#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
};
vector<edge> edg;
vector<int> G[242];

void addedge(int u,int v,int f){
    G[u].push_back(edg.size());
    edg.push_back({u,v,f});

    G[v].push_back(edg.size());
    edg.push_back({v,u,0});

}

int bn[242],cf[242];
bitset<242> inq;
bool flow(int s,int t,int &cur){
    queue<int> q; q.push(s);
    inq.reset(); inq[s]=1;
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    while(q.size() && !bn[t]){
        int now=q.front(); q.pop();
        inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f && bn[e.v]<min(e.f,bn[now])){
                bn[e.v]=min(e.f,bn[now]);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    q.push(e.v);
                }
            }
        }
    }
    if(!bn[t])return 0;
    cur+=bn[t];
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

int c[111];
int main(){
    freopen("in.txt","r",stdin);
    srand(time(0));
    auto clc=clock();
    int p,k,n; cin>>p>>k>>n;
    for(int i=1;i<=p;++i)cin>>c[i];
    int t=p+k+1;
    while((double)(clock()-clc)/CLOCKS_PER_SEC<=0.985){
        edg.clear();
        for(int i=0;i<242;++i)G[i].clear();
        for(int i=1;i<=p;++i){
            addedge(0,i,c[i]);
        }
        for(int j=1;j<=k;++j){
            int i1=rand()%p+1,i2=i1;
            while(i2==i1)i2=rand()%p+1;
            addedge(i1,j+p,1<<30);
            addedge(i2,j+p,1<<30);
        }
        for(int j=1;j<=k;++j){
            addedge(j+p,t,n);
        }
        int f=flow(0,p+k+1);
        if(f==k*n){
            for(int i=1;i<=k;++i){
                for(int eid:G[i+p]){
                    if(edg[eid].v<=p && edg[eid].f){
                        cout<<edg[eid].v<<" "<<edg[eid].f<<" ";
                    }
                }
                cout<<endl;
            }
            exit(0);
        }
    }
    cout<<-1<<endl;
}


