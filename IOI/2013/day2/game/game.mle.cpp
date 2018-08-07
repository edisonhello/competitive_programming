#include "game.h"
#include<bits/stdc++.h>
 
#define ll int_fast64_t
 
using namespace std;
 
ll gcd(ll a,ll b){
    while(b){
        a%=b; swap(a,b);
    } return a;
}
 
struct treap{
    treap *l,*r;
    ll v,g;
    int pri,key;
    void pull(){ g=gcd(gcd(l?l->g:0,r?r->g:0),v); }
    treap(int x,ll v):l(0),r(0),v(v),g(v),pri(rand()),key(x){}
};
treap *merge(treap *a,treap *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split(treap *now,int key,treap *&a,treap *&b){
    if(!now){ a=b=0; return; }
    if(now->key<=key){
        a=now;
        split(now->r,key,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split(now->l,key,a,b->l);
        b->pull();
    }
}
 
struct nodey{
    nodey *l,*r;
    treap *root;
    ll g;
    void pull(){ g=gcd(l?l->g:0,r?r->g:0); return; }
    nodey():l(0),r(0),root(0),g(0){}
};
 
struct nodex{
    nodex *l,*r;
    nodey *root;
    nodex():l(0),r(0),root(0){}
} *root,xpool[30*25000];
nodex *getnodex(){
    static int ptr=-1;
    return &xpool[++ptr];
}
 
int x,y;
 
void init(int R, int C){
    x=R; y=C;
}
 
#define mid ((l+r)>>1)
void modify(nodey *&now,int l,int r,int xtag,int my,ll v){
    if(!now)now=new nodey();
    if(l==r){
        treap *a,*b,*c,*d;
        split(now->root,xtag-1,a,d);
        split(d,xtag,b,c);
        if(b)b->v=b->g=v;
        else b=new treap(xtag,v);
        now->root=merge(merge(a,b),c);
        now->g=now->root->g;
        return;
    }
    if(my<=mid)modify(now->l,l    ,mid,xtag,my,v);
    else       modify(now->r,mid+1,r  ,xtag,my,v);
    now->pull();
}
void modify(nodex *&now,int l,int r,int mx,int my,ll v){
    if(!now)now=getnodex();
    modify(now->root,0,y-1,mx,my,v);
    if(l==r)return;
    if(mx<=mid)modify(now->l,l    ,mid,mx,my,v);
    else       modify(now->r,mid+1,r  ,mx,my,v);
}
void update(int p, int q, long long v){
    modify(root,0,x-1,p,q,v);
}
 
ll query(nodey *now,int l,int r,int yl,int yr){
    if(yr<l || r<yl || !now)return 0;
    if(yl<=l&&r<=yr)return now->g;
    return gcd(query(now->l,l    ,mid,yl,yr),
               query(now->r,mid+1,r  ,yl,yr));
}
ll query(nodex *now,int l,int r,int xl,int xr,int yl,int yr){
    // cout<<"querying x range "<<l<<" to "<<r<<" , xl and xr: "<<xl<<" "<<xr<<endl;
    if(xr<l || r<xl || !now)return 0;
    if(xl<=l&&r<=xr){
        ll Q=query(now->root,0,y-1,yl,yr);
        // cout<<"x range "<<l<<" to "<<r<<" query "<<yl<<" to "<<yr<<" get "<<Q<<endl;
        return Q;
    }
    return gcd(query(now->l,l    ,mid,xl,xr,yl,yr),
               query(now->r,mid+1,r  ,xl,xr,yl,yr));
}
long long calculate(int x1, int y1, int x2, int y2){
    return query(root,0,x-1,x1,x2,y1,y2);
}
