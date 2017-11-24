#include<bits/stdc++.h>
using namespace std;
#define dec sfrijoo

vector<int> G[500009];

struct segt{
    struct node{
        node *l,*r;
        int val,tag;
        node():l(0),r(0),val(0),tag(0){}
    } *root;
    #define m ((l+r)>>1)
    void build(node *now,int l,int r){
        if(l==r)return;
        build(now->l=new node(),l,m);
        build(now->r=new node(),m+1,r);
    }
    void push(node *now){
        if(!now)return;
        if(now->l)now->l->tag=max(now->l->tag,now->tag),now->l->val=max(now->l->val,now->tag);
        if(now->r)now->r->tag=max(now->r->tag,now->tag),now->r->val=max(now->r->val,now->tag);
        now->tag=0;
    }
    void mdf(node *now,int l,int r,int ml,int mr,int x){
        if(r<ml || mr<l)return;
        if(now->tag)push(now);
        if(ml<=l&&r<=mr)return now->tag=x,now->val=x,void();
        mdf(now->l,l,m,ml,mr,x); mdf(now->r,m+1,r,ml,mr,x);
    }
    int qry(node *now,int l,int r,int q){
        if(l==q && r==q)return now->val;
        if(now->tag)push(now);
        if(q<=m)return qry(now->l,l,m,q);
        else return qry(now->r,m+1,r,q);
    }
    #undef m
};

struct {
    int sz[500009],xch[500009],xchi[500009];
    int blc[500009],icp[500009],cct[500009],cmxd[500009],cn;
    vector<segt> seg;
    void dfs1(int now,int pa=0){
        ++sz[now];
        for(int i:G[now]){
            if(i==pa)continue;
            dfs1(i,now);
            sz[now]+=sz[i];
            if(sz[i]>xch[now])xch[now]=sz[i],xchi[now]=i;
        }
    }
    void dfs2(int now,int pa,int ccn,int dep){
        blc[now]=ccn; icp[now]=dep; cmxd[ccn]=dep;
        for(int i:G[now]){
            if(i==pa)continue;
            if(i!=xchi[now])dfs2(i,now,++cn,0),cct[cn]=now;
            else dfs2(i,now,ccn,dep+1);
        }
    }
    void build(){
        dfs1(1);
        dfs2(1,0,++cn,0);
        
        seg.resize(cn+3);
        for(int i=1;i<=cn;++i)seg[i].build(seg[i].root=new segt::node(),0,cmxd[i]);
    }
    void mdf(int x,int v){
        while(x){
            seg[blc[x]].mdf(seg[blc[x]].root,0,cmxd[blc[x]],0,icp[x],v);
            x=cct[blc[x]];
        }
    }
    int get(int x){
        return seg[blc[x]].qry(seg[blc[x]].root,0,cmxd[blc[x]],icp[x]);
    }
} dec;

struct {
    int timer=0,in[500009],out[500009];
    segt seg;
    void dfs(int now,int pa=0){
        in[now]=timer++;
        for(int &i:G[now]){
            if(i==pa)continue;
            dfs(i,now);
        }
        out[now]=timer++;
    }
    void build(){
        dfs(1);
        seg.build(seg.root=new segt::node(),0,timer);
    }
    void mdf(int p,int x){
        // cout<<"flat modify "<<in[p]<<"~"<<out[p]<<" with "<<x<<endl;
        seg.mdf(seg.root,0,timer,in[p],out[p],x);
    }
    int get(int p){
        return seg.qry(seg.root,0,timer,in[p]);
    }
} flat;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    // cout<<"jizz"<<endl;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    flat.build();
    dec.build();
    int q; cin>>q; for(int i=1;i<=q;++i){
        int c,v; cin>>c>>v;
        if(c==1)flat.mdf(v,i);
        else if(c==2)dec.mdf(v,i);
        else cout<<"flat ans: "<<flat.get(v)<<", dec ans: "<<dec.get(v)<<endl,cout<<(flat.get(v)>dec.get(v)?1:0)<<endl;
    }
}
