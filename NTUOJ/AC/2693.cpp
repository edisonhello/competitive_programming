#include<bits/stdc++.h>
using namespace std;

long long djs[200005],sz[200005];
long long nans;

struct node{
    node *l,*r;
    vector<pair<int,int>> meow;
    node():l(0),r(0){}
    void init(){l=r=0; meow.clear();}
} *root,pool[500005*4];
int ptr;
node *gnode(){
    ++ptr;
    pool[ptr].init();
    return &pool[ptr];
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=gnode(),l,mid);
    build(now->r=gnode(),mid+1,r);
}
void insert(node *now,int l,int r,int ml,int mr,pair<int,int> in){
    if(r<ml || mr<l)return;
    if(ml<=l && r<=mr){
        now->meow.push_back(in);
        return;
    }
    insert(now->l,l,mid,ml,mr,in);
    insert(now->r,mid+1,r,ml,mr,in);
}
void go(node *now,int l,int r){
    // cout<<"now "<<l<<" "<<r<<endl;
    stack<pair<long long*,long long>> history;
    for(auto p:now->meow){
        // cout<<"doing "<<p.first<<" "<<p.second;
        while(djs[p.first]!=p.first)p.first=djs[p.first];
        while(djs[p.second]!=p.second)p.second=djs[p.second];
        // cout<<" -> "<<p.first<<" "<<p.second<<endl;
        // cout<<"djs: "; for(int i=1;i<=4;++i)cout<<djs[i]<<" "; cout<<endl;
        if(p.first==p.second)continue;
        if(sz[p.second]>sz[p.first])swap(p.second,p.first);
        history.emplace(&djs[p.second],djs[p.second]);
        history.emplace(&sz[p.first],sz[p.first]);
        history.emplace(&nans,nans);
        nans-=1ll*sz[p.first]*(sz[p.first]-1)+1ll*sz[p.second]*(sz[p.second]-1);
        sz[p.first]+=sz[p.second];
        djs[p.second]=p.first;
        nans+=1ll*sz[p.first]*(sz[p.first]-1);
    }
    if(l==r){
        cout<<nans<<'\n';
    }
    else{
        go(now->l,l,mid);
        go(now->r,mid+1,r);
    }
    while(history.size()){
        *history.top().first=history.top().second;
        history.pop();
    }
}

map<pair<int,int>,int> rel;

int main(){
    int n,m; while(cin>>n>>m){
    ptr=-1;
    rel.clear();
    for(int i=1;i<=n;++i)djs[i]=i;
    for(int i=1;i<=n;++i)sz[i]=1;
    build(root=gnode(),1,m);
    for(int i=1;i<=m;++i){
        int u,v; cin>>u>>v;
        if(u>v)swap(u,v);
        auto it=rel.find(make_pair(u,v));
        if(it==rel.end()){
            rel[make_pair(u,v)]=i;
        }
        else{
            // cout<<it->first.first<<" - "<<it->first.second<<" from "<<it->second<<" to "<<i-1<<endl;
            insert(root,1,m,it->second,i-1,it->first);
            rel.erase(it);
        }
    }
    for(auto p:rel){
        insert(root,1,m,p.second,m,p.first);
    }
    go(root,1,m);
} }
