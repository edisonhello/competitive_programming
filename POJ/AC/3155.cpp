#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#include<vector>
#include<utility>
#include<cstring>
#include<set>
using namespace std;

double eps=1e-7;

struct edge{
    int u,v;
    double f;
    edge(int u,int v,double f):u(u),v(v),f(f){}
};
vector<edge> edg;
vector<int> G[1200];

void ae(int u,int v,double f){
    G[u].push_back(edg.size());
    edg.push_back(edge(u,v,f));
    G[v].push_back(edg.size());
    edg.push_back(edge(v,u,0));
}

vector<pair<int,int> > org;
int vis[1200],d[1200];
bool bfs(int s,int t,int vid){
    queue<int> q; q.push(s);
    d[s]=0; vis[s]=vid;
    while(q.size()){
        int now=q.front(); q.pop();
        for(int i=0;i<G[now].size();++i){
            edge &e=edg[G[now][i]];
            if(e.f>eps && vis[e.v]!=vid){
                vis[e.v]=vid;
                d[e.v]=d[now]+1;
                q.push(e.v);
            }
        }
    }
    return vis[t]==vid;
}

int cur[1200];
double dfs(int now,int t,double fl){
    if(now==t)return fl;
    if(fl<eps)return eps;
    double rt=0,df;
    for(int &i=cur[now];i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        while(d[e.v]==d[now]+1 && ((df=dfs(e.v,t,min(fl,e.f)))>eps)){
            rt+=df;
            e.f-=df;
            fl-=df;
            edg[G[now][i]^1].f+=df;
        }
        if(fl<eps)break;
    }
    return rt;
}

double flow(int s,int t){
    double f=0;
    int c=0;
    memset(vis,0,sizeof(vis));
    while(bfs(s,t,++c)){
        memset(cur,0,sizeof(cur));
        f+=dfs(s,t,1e10);
    }
    return f;
}

int n,m;
double test(double we){
    edg.clear();
    for(int i=0;i<1200;++i)G[i].clear();

    for(int i=0;i<org.size();++i){
        ae(i+1,org[i].first+org.size(),1e10);
        ae(i+1,org[i].second+org.size(),1e10);
        ae(0,i+1,1);
    }
    for(int i=1;i<=n;++i)ae(i+org.size(),1199,we);
    double f=flow(0,1199);
    // cout<<"testing "<<we<<" , get f: "<<f<<endl;
    return f;
}

set<int> ans;
void dfs(int now,int vid=-1){
    ans.insert(now);
    vis[now]=vid;
    for(int i=0;i<G[now].size();++i){
        edge &e=edg[G[now][i]];
        if(vis[e.v]!=vid && e.f>eps)dfs(e.v);
    }
}
int main(){
    cin>>n>>m;
    if(m==0)return cout<<"1\n1"<<endl,0;
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        org.push_back(pair<int,int>(a,b));
    }
    double L=0,R=1000;
    while(R-L>1e-5){
        double mid=(L+R)/2;
        if(test(mid)<m)L=mid;
        else R=mid;
    }
    test(L);
    dfs(0);
    vector<int> aans;
    for(set<int>::iterator it=ans.begin();it!=ans.end();++it)if(*it>m)aans.push_back(*it-m);
    cout<<aans.size()<<endl;
    for(int i=0;i<aans.size();++i)cout<<aans[i]<<endl;
    // cout<<L<<endl;
}
