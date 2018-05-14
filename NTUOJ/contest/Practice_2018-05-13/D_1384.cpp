#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int val,tag;
    node():l(0),r(0),val(0),tag(0){}
    void init(){l=r=0; val=tag=0;}
} pool[50000 * 20];
int ptr;
node *gnode(){
    ++ptr;
    pool[ptr].init();
    return &pool[ptr];
}
void push(node *now){
    if(!now)return;
    if(!now->tag)return;
    if(!now->l)return;
    now->l->val+=now->tag;
    now->l->tag+=now->tag;
    now->r->val+=now->tag;
    now->r->tag+=now->tag;
    now->tag=0;
}
#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=gnode(),l,mid);
    build(now->r=gnode(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,int x){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->tag+=x;
        now->val+=x;
        return;
    }
    push(now);
    modify(now->l,l,mid,ml,mr,x);
    modify(now->r,mid+1,r,ml,mr,x);
}
int query(node *now,int l,int r,int x){
    if(l==r)return now->val;
    push(now);
    if(x<=mid)return query(now->l,l,mid,x);
    else return query(now->r,mid+1,r,x);
}

struct segtree{
    int L,R;
    node *root;
    segtree():L(0),R(0),root(0){}
    void init(int z,int x){
        L=z, R=x;
        build(root=gnode(),z,x);
    }
    void mdf(int l,int r,int x){
        modify(root,L,R,l,r,x);
    }
    int qry(int x){
        return query(root,L,R,x);
    }
} ctree[50005];

vector<int> G[50005];
int d[50005],p[18][50005],sz[50005];
int chmx[50005],chmxi[50005];

void dfsz(int now,int pa,int dep){
    sz[now]=1;
    p[0][now]=pa;
    d[now]=dep;
    for(int i=1;(1<<i)<=dep;++i){
        p[i][now]=p[i-1][p[i-1][now]];
    }
    for(int i:G[now]){
        if(i==pa)continue;
        dfsz(i,now,dep+1);
        sz[now]+=sz[i];
        if(sz[i]>chmx[now]){
            chmx[now]=sz[i];
            chmxi[now]=i;
        }
    }
}

int bel[50005],icpos[50005],cc,clen[50005],ctop[50005];

void dfs(int now,int pa,int cnum,int cpos){
    bel[now]=cnum;
    icpos[now]=cpos;
    clen[cnum]=cpos;
    for(int i:G[now]){
        if(i==pa)continue;
        if(i==chmxi[now]){
            dfs(i,now,cnum,cpos+1);
        }
        else{
            ctop[++cc]=now;
            dfs(i,now,cc,1);
        }
    }
}
void addv(int u,int d,int c){
    while(bel[u]!=bel[d]){
        ctree[bel[d]].mdf(1,icpos[d],c);
        d=ctop[bel[d]];
    }
    ctree[bel[d]].mdf(icpos[u],icpos[d],c);
}
int glca(int pa,int pb){
    if(pa==pb)return pa;
    if(d[pa]>d[pb])swap(pa,pb);
    for(int i=0;i<18;++i){
        if((d[pb]-d[pa])&(1<<i)){
            pb=p[i][pb];
        }
    }
    if(pa==pb)return pa;
    for(int i=17;i>=0;--i){
        if(p[i][pa]!=p[i][pb]){
            pa=p[i][pa];
            pb=p[i][pb];
        }
    }
    return p[0][pa];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts,ks=0; cin>>ts; while(ts--){
        int n; cin>>n;

        ptr=-1;
        for(int i=0;i<n;++i)G[i].clear();
        memset(p,0,sizeof(p));
        memset(d,0,sizeof(d));
        memset(chmx,0,sizeof(chmx));
        cc=0;

        cout<<"Case #"<<(++ks)<<":"<<endl;
        for(int i=1,u,v;i<n;++i){
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfsz(0,0,0);
        dfs(0,0,++cc,1);
        for(int i=1;i<=cc;++i){
            ctree[i].init(1,clen[i]);
        }
        int q; cin>>q; while(q--){
            int a,b,c; cin>>a>>b>>c;
            int lca=glca(a,b);
            // cout<<a<<" "<<b<<" lca "<<lca<<endl;
            addv(lca,a,c);
            addv(lca,b,c);
            addv(lca,lca,-c);
        }
        for(int i=0;i<n;++i){
            cout<<ctree[bel[i]].qry(icpos[i])<<'\n';
        }
    }
}
