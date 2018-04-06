#include<bits/stdc++.h>
using namespace std;

struct segtree{
    struct node{
        node *l,*r;
        int val;
        node():l(0),r(0),val(0){}
    } *root;
    int L,R;
#define mid ((l+r)>>1)
    int query(int x,int l,int r,node *now){
        if(l==r)return now->val;
        if(now->val)now->l->val=now->r->val=now->val,now->val=0;
        if(x<=mid)return query(x,l,mid,now->l);
        else return query(x,mid+1,r,now->r);
    }
    int query(int x){return query(x,L,R,root);}
    void modify(int ml,int mr,int v,int l,int r,node *now){
        if(mr<l || r<ml)return;
        if(ml<=l&&r<=mr){
            now->val=v;
            return;
        }
        if(now->val)now->l->val=now->r->val=now->val,now->val=0;
        modify(ml,mr,v,l,mid,now->l);
        modify(ml,mr,v,mid+1,r,now->r);
    }
    void modify(int ml,int mr,int v){modify(ml,mr,v,L,R,root);}
    void build(int l,int r,node *now){
        if(l==r)return;
        build(l,mid,now->l=new node());
        build(mid+1,r,now->r=new node());
    }
    void init(int l,int r){
        L=l,R=r;
        build(L,R,root=new node());
    }
    segtree():root(0){}
#undef mid
} water,empty[500005];

int n,dfst,in[500005],out[500005],sz[500005],mxssz[500005],mxsid[500005];
vector<int> G[500005];
int ch_cnt,chid[500005],chpos[500005],ctopa[500005],chsz[500005];

void dfs1(int now,int pa){
    in[now]=++dfst;
    sz[now]=1;
    for(int i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        sz[now]+=sz[i];
        if(sz[i]>mxssz[now]){
            mxssz[now]=sz[i];
            mxsid[now]=i;
        }
    }
    out[now]=dfst;
}
void dfs2(int now,int pa,int _chid,int _chpos){
    chid[now]=_chid;
    chpos[now]=_chpos;
    chsz[_chid]=_chpos;
    for(int i:G[now]){
        if(i==pa)continue;
        if(i==mxsid[now]){
            ctopa[i]=ctopa[now];
            dfs2(i,now,_chid,_chpos+1);
        }
        else{
            ctopa[i]=now;
            dfs2(i,now,++ch_cnt,1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1,1);
    water.init(1,dfst);
    dfs2(1,1,++ch_cnt,1);
    for(int i=1;i<=ch_cnt;++i){
        empty[i].init(1,chsz[i]);
    }
    int q; cin>>q;
    for(int i=1;i<=q;++i){
        int c,v; cin>>c>>v;
        if(c==1){
            water.modify(in[v],out[v],i);
        }
        else if(c==2){
            while(v){
                empty[chid[v]].modify(1,chpos[v],i);
                v=ctopa[v];
            }
        }
        else{
            int wa=water.query(in[v]);
            int em=empty[chid[v]].query(chpos[v]);
            if(em>=wa)cout<<0<<'\n';
            else cout<<1<<'\n';
        }
    }
}
