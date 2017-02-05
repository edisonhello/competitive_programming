#include<iostream>
using namespace std;
#include<algorithm>
#include<queue>
#include<vector>
#include<utility>
#define ll long long

struct eg{int s,t,i;ll w;};
struct inf{int t,i;};
bool operator<(const eg &a,const eg &b){return a.w<b.w;}
bool operator>(const eg &a,const eg &b){return a.w>b.w;}

const int st=18;

int n,m,djs[200005],d[200005],par[st][200005];
ll MST,w[200005],ans[200005],dis[st][200005];
vector<inf> G[200005];
bool u[200005];
vector<eg> E;

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){x=F(x),y=F(y);djs[x]=y;}
bool C(int x,int y){return F(x)==F(y);}

void dfs(int now,int p,int dep,int frm){
    // if(now==3)cout<<" a"<<frm<<" "<<w[frm]<<endl;
    d[now]=dep;
    par[0][now]=p;
    dis[0][now]=w[frm];
    for(int i=1;i<st;++i){
        if((1<<i)>dep)break;
        par[i][now]=par[i-1][par[i-1][now]];
        dis[i][now]=max({dis[i-1][now],dis[i-1][par[i-1][now]]});
        // if(now==3)cout<<i<<" "<<dis[i][now]<<endl;
    }
    for(auto &i:G[now]){
        if(i.t==p)continue;
        if(!u[i.i])continue;
        dfs(i.t,now,dep+1,i.i);
    }
}
ll mxw(int pa,int pb){
    ll mx=0;
    if(d[pb]>d[pa])swap(pa,pb);
    for(int i=0;i<st;++i){
        if((d[pa]-d[pb])&(1<<i)){
            mx=max({mx,dis[i][pa]});
            pa=par[i][pa];
        }
        if(d[pb]==d[pa])break;
    }
    // cout<<pa<<" "<<pb<<endl;
    if(pa==pb)return mx;
    for(int i=st-1;i>=0;--i){
        if(par[i][pa]==par[i][pb])continue;
        mx=max({mx,dis[i][pa],dis[i][pb]});
        pa=par[i][pa],pb=par[i][pb];
    }
    mx=max({mx,dis[0][pa],dis[0][pb]});
    return mx;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    E.resize(m);
    for(int i=0;i<m;++i){
        cin>>E[i].s>>E[i].t>>E[i].w;
        G[E[i].s].push_back({E[i].t,i});
        G[E[i].t].push_back({E[i].s,i});
        E[i].i=i;
        w[i]=E[i].w;
    }
    for(int i=0;i<=n;++i)djs[i]=i;
    sort(E.begin(),E.end());
    for(int i=0,in=1;i<m&&in<n;++i){
        if(C(E[i].s,E[i].t))continue;
        U(E[i].s,E[i].t);
        MST+=E[i].w;
        u[E[i].i]=1;
        ++in;
    }
    // cout<<"MST: "<<MST<<endl;
    // cout<<"u   ";for(int i=0;i<m;++i)cout<<u[i]<<" ";cout<<endl;
    dfs(1,1,0,0);
    // cout<<"d   ";for(int i=1;i<=n;++i)cout<<d[i]<<" ";cout<<endl;
    // cout<<"par ";for(int i=1;i<=n;++i)cout<<par[i]<<" ";cout<<endl;
    for(int i=0;i<m;++i){
        // cout<<"doing side "<<E[i].i<<endl;
        if(u[E[i].i])ans[E[i].i]=MST;
        else ans[E[i].i]=MST-mxw(E[i].s,E[i].t)+E[i].w;
    }
    for(int i=0;i<m;++i)cout<<ans[i]<<endl;
}
