#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u,v,f;
} edg[1234];
// vector<edge> edg;
int edgsize=-1;
vector<int> G[85];

void addedge(int u,int v,int f){
    cout<<"addedge: "<<u<<" "<<v<<" "<<f<<endl;
    edg[++edgsize]={u,v,f};
    G[u].push_back(edgsize);
    edg[++edgsize]={v,u,0};
    G[v].push_back(edgsize);
}

int bn[85],cf[85],que[8000];
bitset<85> inq;
bool flow(int s,int t,int &cur){
    int qtop=0,qtail=1,now;
    inq.reset(); inq[s]=1; que[0]=s;
    memset(bn,0,sizeof(bn)); bn[s]=0x3f3f3f3f;
    while(qtail-qtop && !bn[t]){
        now=que[qtop]; ++qtop;
        cout<<"now: "<<now<<endl;
        inq[now]=0;
        for(int eid:G[now]){
            edge &e=edg[eid];
            if(e.f && bn[e.v]<min(e.f,bn[now])){
                bn[e.v]=min(e.f,bn[now]);
                cf[e.v]=eid;
                if(!inq[e.v]){
                    inq[e.v]=1;
                    que[qtail]=e.v;
                    ++e.v; ++qtail;
                }
            }
        }
    }
    if(!bn[t])return 0;
    cur+=bn[t];
    for(;t!=s;t=edg[cf[t]].u){
        edg[cf[t]].f-=bn[t];
        edg[cf[t]^1].f+=bn[t];
    }
    cout<<"fadd: "<<bn[t]<<endl;
    return 1;
}

int flow(int s,int t){
    int f=0;
    while(flow(s,t,f));
    return f;
}

int c[45];
int main(){
    srand(time(0));
    auto clc=clock();
    int p,k,n; cin>>p>>k>>n;
    for(int i=1;i<=p;++i)cin>>c[i];
    int t=p+k+1;
    while((double)(clock()-clc)/CLOCKS_PER_SEC<=0.95){
        edgsize=-1;
        for(int i=0;i<85;++i)G[i].clear();
        for(int i=1;i<=p;++i){
            addedge(0,i,c[i]);
        }
        /* for(int j=1;j<=k;++j){
            int i1=rand()%p+1,i2=i1;
            while(i2==i1)i2=rand()%p+1;
            addedge(i1,j+p,1<<30);
            addedge(i2,j+p,1<<30);
        } */
        addedge(1,4,1<<30);
        addedge(3,4,1<<30);
        addedge(2,5,1<<30);
        addedge(3,5,1<<30);
        addedge(1,6,1<<30);
        addedge(3,6,1<<30);
        for(int j=1;j<=k;++j){
            addedge(j+p,t,n);
        }
        int f=flow(0,p+k+1);
        cout<<"f: "<<f<<endl;
        if(f==k*n){
            for(int i=1;i<=k;++i){
                for(int eid:G[i+p]){
                    if(edg[eid].v<=p && edg[eid].f){
                        cout<<edg[eid].v<<" "<<edg[eid].f<<endl;
                    }
                }
            }
            exit(0);
        }
    }
    cout<<-1<<endl;
}
