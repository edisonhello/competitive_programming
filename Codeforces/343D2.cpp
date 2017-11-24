#include<bits/stdc++.h>
using namespace std;

struct segt{
    struct node{
        node *l,*r;
        int val,tag;
        node():l(0),r(0),val(0),tag(0){}
    } *root;
    int L,R;
    void build(int l,int r){L=l; R=r; build(root=new node(),l,r);}
    void mdf(int l,int r,int x){mdf(root,L,R,l,r,x);}
    int qry(int p){return qry(root,L,R,p);}

    #define m ((l+r)>>1)
    void push(node *now){
        if(!now)return;
        if(now->l)now->l->val=max(now->l->val,now->tag),now->l->tag=max(now->l->tag,now->tag);
        if(now->r)now->r->val=max(now->r->val,now->tag),now->r->tag=max(now->r->tag,now->tag);
    }
    void build(node *now,int l,int r){
        if(l==r)return;
        build(now->l=new node(),l,m);
        build(now->r=new node(),m+1,r);
    }
    void mdf(node *now,int l,int r,int ml,int mr,int x){
        if(r<ml || mr<l)return;
        if(ml<=l&&r<=mr)return now->tag=x,now->val=x,void();
        push(now);
        mdf(now->l,l,m,ml,mr,x); mdf(now->r,m+1,r,ml,mr,x);
    }
    int qry(node *now,int l,int r,int q){
        if(l==q && q==r)return now->val;
        push(now);
        return q<=m?qry(now->l,l,m,q):qry(now->r,m+1,r,q);
    }
    #undef m
};

vector<int> G[50009];

struct {
    int in[500009],out[500009],timer;
    segt seg;
    void dfs(int now,int pa){
        in[now]=timer++;
        for(int i:G[now]){
            if(i!=pa)
            dfs(i,now);
        }
        out[now]=timer++;
    }
    void build(){
        dfs(1,0);
        seg.build(0,timer);
    }
    void mdf(int x,int v){seg.mdf(in[x],out[x],v);}
    int qry(int x){return seg.qry(in[x]);}
} water;

struct {
    int mxc[500009],mxi[500009],sz[500009];
    int bel[500009],cps[500009],cct[500009],mxd[500009],tcn;
    vector<segt> seg;
    void dfs1(int now,int pa){
        for(int i:G[now]){
            if(i==pa)continue;
            dfs1(i,now);
            sz[now]+=sz[i];
            if(sz[i]>mxc[now])mxc[now]=sz[i],mxi[now]=i;
        }
        ++sz[now];
    }
    void dfs2(int now,int pa,int ccn,int dep){
        bel[now]=ccn; cps[now]=mxd[ccn]=dep;
        for(int i:G[now]){
            if(i==pa)continue;
            if(i==mxi[now])dfs2(i,now,ccn,dep+1);
            else dfs2(i,now,tcn,0),cct[tcn++]=now;
        }
    }
    void build(){
        dfs1(1,0);
        dfs2(1,0,tcn++,0);
        seg.resize(tcn);
        for(int i=0;i<tcn;++i)seg[i].build(0,mxd[i]);
    }
    void mdf(int x,int v){
        while(x){
            seg[bel[x]].mdf(0,cps[x],v);
            x=cct[bel[x]];
        }
    }
    int qry(int x){
        return seg[bel[x]].qry(cps[x]);
    }
} empty;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    water.build();
    empty.build();
    int q,c,x; cin>>q; for(int i=1;i<=q;++i){
        cin>>c>>x;
        if(c==1)water.mdf(x,i);
        else if(c==2)empty.mdf(x,i);
        else cout<<(water.qry(x)>empty.qry(x)?1:0)<<endl;
    }
}
