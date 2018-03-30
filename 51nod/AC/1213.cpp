#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct pnt{
    ll x,y,i;
    void swap(){
        std::swap(x,y);
    }
};
vector<pnt> ps;

struct edge{
    int u,v;
    ll w;
};
vector<edge> edg;

#define lb(x) ((x)&-(x))
pair<ll,int> bit[50005];
pair<ll,int> query(int x){
    pair<ll,int> rt={-(1ll<<59),-1};
    for(;x;x-=lb(x))rt=max(rt,bit[x]);
    return rt;
}
void add(int x,pair<ll,int> v){
    for(;x<50005;x+=lb(x))bit[x]=max(bit[x],v);
}

int dis(int id1,int id2){
    return abs(ps[id1].x-ps[id2].x)+abs(ps[id1].y-ps[id2].y);
}
void addedge(int id1,int id2){
    edg.push_back({ps[id1].i,ps[id2].i,dis(id1,id2)});
}

int djs[50005];
int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=0,x,y;i<n;++i){
         cin>>x>>y;
         ps.push_back({x,y,i});
    }
    for(int d=0;d<4;++d){
        if(d&1)for(int i=0;i<n;++i)ps[i].x*=-1;
        if(d==2)for(int i=0;i<n;++i)ps[i].swap();
        sort(ps.begin(),ps.end(),[](const pnt &a,const pnt &b){return a.x==b.x?a.y<b.y:a.x<b.x;});
        vector<ll> bases;
        for(int i=0;i<n;++i)bases.push_back(ps[i].y-ps[i].x);
        sort(bases.begin(),bases.end());
        for(int i=0;i<50005;++i)bit[i]={-(1ll<<59),-1};
        for(int i=0;i<n;++i){
            int pos=lower_bound(bases.begin(),bases.end(),ps[i].y-ps[i].x)-bases.begin()+1;
            auto rt=query(pos);
            if(rt.second>=0)addedge(rt.second,i);
            add(pos,{ps[i].y+ps[i].x,i});
        }
    }
    sort(edg.begin(),edg.end(),[](const edge &a,const edge &b){return a.w<b.w;});
    ll ans=0;
    for(int i=0;i<n;++i)djs[i]=i;
    for(auto &e:edg){
        if(F(e.u)!=F(e.v)){
            U(e.u,e.v);
            ans+=e.w;
        }
    }
    cout<<ans<<endl;
}
