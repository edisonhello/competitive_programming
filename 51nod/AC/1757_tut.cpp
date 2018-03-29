#include<bits/stdc++.h>
using namespace std;

vector<int> G[2005];
int n,m,x[55],d[55][2005];
bitset<2005> v,ishole;
vector<int> dis[55];

struct edge{
    int u,v,f;
};

vector<edge> edg;
vector<int> fG[84504];

void ae(int u,int v,int f){
    // cout<<"ae: "<<u<<" "<<v<<" "<<f<<endl;
    fG[u].push_back(edg.size());
    edg.push_back({u,v,f});
    fG[v].push_back(edg.size());
    edg.push_back({v,u,0});
}


int dep[84504],vv[84504];
bool bfs(int s,int t,int c){
    queue<int> q; q.push(s);
    dep[s]=0; vv[s]=c;
    while(q.size()){
        int now=q.front(); q.pop();
        // cout<<"bfs now "<<now<<" "<<vv[t]<<endl;
        for(int eid:fG[now]){
            edge &e=edg[eid];
            if(e.f>0 && vv[e.v]!=c){
                vv[e.v]=c;
                q.push(e.v);
                dep[e.v]=dep[now]+1;
            }
        }
    }
    return vv[t]==c;
}

int cur[84503];
int dfs(int now,int t,int fl){
    if(fl==0)return 0;
    // cout<<"dfs now "<<now<<endl;
    if(t==now)return fl;
    int f=0,df;
    for(int &i=cur[now];i<fG[now].size();++i){
        int eid=fG[now][i];
    // for(int eid:fG[now]){
        edge &e=edg[eid];
        if(dep[e.v]==dep[now]+1 && (df=dfs(e.v,t,min(fl,e.f)))){
            f+=df;
            fl-=df;
            e.f-=df;
            edg[eid^1].f+=df;
            if(!fl)break;
        }
    }
    return f;
}


int flow(int s,int t){
    // cout<<"flow "<<s<<" "<<t<<endl;
    int f=0,c=0;
    while(bfs(s,t,++c)){
        // cout<<"new step"<<endl;
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,0x3f3f3f3f);
        // cout<<"now f: "<<f<<endl;
    }
    // cout<<"f: "<<f<<endl;
    return f;
}

bool ok(int t){
    // cout<<"ok: t "<<t<<endl;
    for(int i=0;i<84504;++i)fG[i].clear();
    edg.clear();
    for(int i=1;i<=n;++i)if(!ishole[i])ae(0,i,1);
    for(int i=1;i<=m;++i){
        // for(int j=1;j<=n;++j){
        for(int j:dis[i]){
            if(ishole[j])continue;
            // for(int z=d[i][j];z<=t;++z)ae(j,n+i*2000+z,1);
            if(d[i][j]<=t)ae(j,n+i*2000+d[i][j],1);
            else break;
            // if(d[i][j]<=t)ae(j,x[i],1);
        }
        for(int j=1;j<=t;++j)ae(n+i*2000+j,84502,1);
        for(int j=1;j<t;++j)ae(n+i*2000+j,n+i*2000+j+1,0x3f3f3f3f);
        // ae(n+i*2000+t,83002,0x3f3f3f3f);
        // for(int z=1;z<=t;++z)ae(n+i*2000+z,83002,1);
        // ae(x[i],n+1,t);
    }
    // cout<<"go flow"<<endl;
    int f=flow(0,84502);
    // cout<<"t: "<<t<<" , f: "<<f<<endl;
    return f>=n-m;
}

int main(){
    cin>>n>>m;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=m;++i){
        cin>>x[i];
        ishole[x[i]]=1;
        queue<int> q; q.push(x[i]);
        v.reset(); v[x[i]]=1;
        while(q.size()){
            int now=q.front(); q.pop();
            dis[i].push_back(now);
            for(int j:G[now]){
                if(!v[j]){
                    v[j]=1;
                    d[i][j]=d[i][now]+1;
                    q.push(j);
                }
            }
        }
    }
    int L=0,R=n;
    while(R>L){
        int mid=(L+R)>>1;
        if(ok(mid))R=mid;
        else L=mid+1;
    }
    cout<<L<<endl;
}
