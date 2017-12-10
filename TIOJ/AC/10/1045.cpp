#include<bits/stdc++.h>
using namespace std;

struct Seg{
    struct node{
        node *l,*r;
        int tag;
        long long v;
        node(long long v=0):l(0),r(0),v(v),tag(0){}
    } *root;
    Seg():root(0){}

    void del(node *now){
        if(!now)return;
        if(now->l)del(now->l);
        if(now->r)del(now->r);
        delete now;
    }
    void rebuild(){
        if(root)del(root);
        root=new node(); root->v=10000;
    }
    #define m ((l+r)>>1)
    void mdf(node *now,int l,int r,int ml,int mr,int v){
        if(ml<=l && r<=mr){if(v==1)now->v<<=1; else now->v>>=1; now->tag+=v; return;}
        if(mr<l  ||  r<ml)return;
        if(!now->l)now->l=new node(now->v/(r-l+1)*(m-l+1)),now->tag=0;
        if(!now->r)now->r=new node(now->v/(r-l+1)*(r-m)),now->tag=0;
        if(now->tag>0)now->l->v<<=now->tag,now->l->tag+=now->tag,now->r->v<<=now->tag,now->r->tag+=now->tag,now->tag=0;
        if(now->tag<0)now->l->v>>=-now->tag,now->l->tag+=now->tag,now->r->v>>=-now->tag,now->r->tag+=now->tag,now->tag=0;
        mdf(now->l,l,m,ml,mr,v);
        mdf(now->r,m+1,r,ml,mr,v);
        now->v=now->l->v+now->r->v;
    }
    void mdf(int l,int r,int v){
        mdf(root,0,9999,l,r,v);
    }
    long long get(){return root->v;}
} seg;

struct ope{int x,u,d,v;};
vector<ope> op;
int main(){
    int n; while(scanf("%d",&n),n){
        op.clear();
        seg.rebuild();
        for(int i=0,q,w,e,r;i<n;++i){
            scanf("%d%d%d%d",&q,&w,&e,&r);
            op.push_back({q,w,r-1,1});
            op.push_back({e,w,r-1,-1});
        }
        sort(op.begin(),op.end(),[](const ope &a,const ope &b){return a.x<b.x;});
        long long ans=0; int prv=0,ptr=0;
        while(ptr<op.size()){
            ans+=seg.get()*(op[ptr].x-prv);
            prv=op[ptr].x; while(ptr<op.size() && op[ptr].x==prv){
                seg.mdf(op[ptr].u,op[ptr].d,op[ptr].v);
                ++ptr;
            }
        }
        ans+=seg.get()*(10000-prv);
        printf("%lld\n",ans);
    }
}
