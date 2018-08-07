#include "grader.h"
#include<bits/stdc++.h>
 
#define ll int_fast64_t
 
using namespace std;
 
ll gcd(ll a,ll b){
    while(b){
        a%=b; swap(a,b);
    } return a;
}
 
struct treap{
    int l,r;
    ll v,g;
    int pri,key;
    void pull();
    // treap(int x,ll v):l(0),r(0),v(v),g(v),pri(rand()),key(x){}
} ts[30*10000];
void treap::pull(){ g=gcd(gcd(l?ts[l].g:0,r?ts[r].g:0),v); }
int gettreap(int x,ll v){
    static int ptr=1;
    ts[ptr].key=x;
    ts[ptr].v=ts[ptr].g=v;
    return ptr++;
}
 
int merge(int a,int b){
    if(!a)return b; if(!b)return a;
    if(ts[a].pri>ts[b].pri){
        ts[a].r=merge(ts[a].r,b);
        ts[a].pull();
        return a;
    }
    else{
        ts[b].l=merge(a,ts[b].l);
        ts[b].pull();
        return b;
    }
}
void split(int now,int key,int &a,int &b){
    if(!now){ a=b=0; return; }
    if(ts[now].key<=key){
        a=now;
        split(ts[now].r,key,ts[a].r,b);
        ts[a].pull();
    }
    else{
        b=now;
        split(ts[now].l,key,a,ts[b].l);
        ts[b].pull();
    }
}
 
struct nodey{
    int l,r,root;
    ll g;
    void pull();
    // void pull(){ g=gcd(l?l->g:0,r?r->g:0); return; }
} ys[30*30*10000];
 
void nodey::pull(){ g=gcd(l?ys[l].g:0,r?ys[r].g:0); }
 
struct nodex{
    int l,r,root;
} xs[30*10000];
int root,xptr,yptr;
 
int x,y;
 
void init(int R, int C){
    x=R; y=C;
}
 
#define mid ((l+r)>>1)
void modifyy(int &now,int l,int r,int xtag,int my,ll v){
    if(!now)now=++yptr;
    if(l==r){
        int a,b,c,d;
        split(ys[now].root,xtag-1,a,d);
        split(d,xtag,b,c);
        if(b)ts[b].v=ts[b].g=v;
        else b=gettreap(xtag,v);
        ys[now].root=merge(merge(a,b),c);
        ys[now].g=ts[ys[now].root].g;
        return;
    }
    if(my<=mid)modifyy(ys[now].l,l    ,mid,xtag,my,v);
    else       modifyy(ys[now].r,mid+1,r  ,xtag,my,v);
    ys[now].pull();
}
void modifyx(int &now,int l,int r,int mx,int my,ll v){
    if(!now)now=++xptr;
    modifyy(xs[now].root,0,y-1,mx,my,v);
    if(l==r)return;
    if(mx<=mid)modifyx(xs[now].l,l    ,mid,mx,my,v);
    else       modifyx(xs[now].r,mid+1,r  ,mx,my,v);
}
void update(int p, int q, long long v){
    modifyx(root,0,x-1,p,q,v);
}
 
ll query(int now,int l,int r,int yl,int yr){
    if(yr<l || r<yl || !now)return 0;
    if(yl<=l&&r<=yr)return ys[now].g;
    return gcd(query(ys[now].l,l    ,mid,yl,yr),
               query(ys[now].r,mid+1,r  ,yl,yr));
}
ll query(int now,int l,int r,int xl,int xr,int yl,int yr){
    // cout<<"querying x range "<<l<<" to "<<r<<" , xl and xr: "<<xl<<" "<<xr<<endl;
    if(xr<l || r<xl || !now)return 0;
    if(xl<=l&&r<=xr){
        ll Q=query(xs[now].root,0,y-1,yl,yr);
        // cout<<"x range "<<l<<" to "<<r<<" query "<<yl<<" to "<<yr<<" get "<<Q<<endl;
        return Q;
    }
    return gcd(query(xs[now].l,l    ,mid,xl,xr,yl,yr),
               query(xs[now].r,mid+1,r  ,xl,xr,yl,yr));
}
long long calculate(int x1, int y1, int x2, int y2){
    return query(root,0,x-1,x1,x2,y1,y2);
}

