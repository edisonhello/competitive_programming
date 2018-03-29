#include<vector>
#include<bitset>
#include<iostream>
#include<queue>
using namespace std;

int n,m;

struct edge{
    int u,v,f;
    edge(int u,int v,int f):u(u),v(v),f(f){}
};

vector<edge> edg;
vector<int> fG[304];

void ae(int u,int v,int f){
    // cout<<"ae: "<<u<<" "<<v<<" "<<f<<endl;
    fG[u].push_back(edg.size());
    edg.push_back(edge(u,v,f));
    fG[v].push_back(edg.size());
    edg.push_back(edge(v,u,0));
}


int dep[304],vv[304];
bool bfs(int s,int t,int c){
    queue<int> q; q.push(s);
    dep[s]=0; vv[s]=c;
    while(q.size() && vv[t]!=c){
        int now=q.front(); q.pop();
        // cout<<"bfs now "<<now<<" "<<vv[t]<<endl;
        for(int i=0;i<fG[now].size();++i){
            int eid=fG[now][i];
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
int dfs(int now,int t,int fl){
    if(t==now)return fl;
    // cout<<"dfs now "<<now<<endl;
    int f;
    for(int i=0;i<fG[now].size();++i){
        int eid=fG[now][i];
        edge &e=edg[eid];
        if(dep[e.v]==dep[now]+1 && (f=dfs(e.v,t,min(fl,e.f)))){
            e.f-=f;
            edg[eid^1].f+=f;
            return f;
        }
    }
    return 0;
}


int flow(int s,int t){
    int f=0,c=0;
    while(bfs(s,t,++c)){
        f+=dfs(s,t,0x3f3f3f3f);
    }
    return f;
}

int main(){
    int m,n; while(cin>>m>>n){
        edg.clear();
        for(int i=0;i<304;++i)fG[i].clear();
        while(m--){
            int u,v,w; cin>>u>>v>>w;
            ae(u,v,w);
        }
        cout<<flow(1,n)<<endl;
    }
}
