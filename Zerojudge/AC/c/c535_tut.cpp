#pragma GCC optimize("no-stack-protector,Ofast")
#include<bits/stdc++.h>
using namespace std;

int last;

struct treap{
    treap *l,*r;
    int y,pri,tp1,tp2,tp1mx,tp1mn,tp2mx,tp2mn;
    treap(int y=0,int tp1=0,int tp2=0):l(0),r(0),y(y),pri(rand()),tp1(tp1),tp2(tp2),tp1mx(tp1),tp1mn(tp1),tp2mx(tp2),tp2mn(tp2){}
};
void pull(treap *now){
    now->tp1mx=max(now->tp1,max(now->l?now->l->tp1mx:-(1<<30),now->r?now->r->tp1mx:-(1<<30)));
    now->tp2mx=max(now->tp2,max(now->l?now->l->tp2mx:-(1<<30),now->r?now->r->tp2mx:-(1<<30)));
    now->tp1mn=min(now->tp1,min(now->l?now->l->tp1mn:(1<<30),now->r?now->r->tp1mn:(1<<30)));
    now->tp2mn=min(now->tp2,min(now->l?now->l->tp2mn:(1<<30),now->r?now->r->tp2mn:(1<<30)));
}

treap *merge(treap *a,treap *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        pull(a);
        return a;
    }
    else{
        b->l=merge(a,b->l);
        pull(b);
        return b;
    }
}
void split(treap *now,int y,treap *&a,treap *&b){
    if(!now){a=b=0; return;}
    if(now->y<=y){
        a=now;
        split(now->r,y,a->r,b);
        pull(a);
    }
    else{
        b=now;
        split(now->l,y,a,b->l);
        pull(b);
    }
}
void insert(treap *&root,int y,int v1,int v2){
    treap *a,*b;
    split(root,y,a,b);
    root=merge(merge(a,new treap(y,v1,v2)),b);
}

struct node{
    node *l,*r;
    treap *root;
} *root;

#define mid ((l+r)>>1)
void insert(node *&now,int l,int r,int x,int y,int v1,int v2){
    if(!now)now=new node();
    insert(now->root,y,v1,v2);
    if(l==r)return;
    if(x<=mid)insert(now->l,l,mid,x,y,v1,v2);
    else insert(now->r,mid+1,r,x,y,v1,v2);
}
void queryr(node *now,int l,int r,int ql,int qr,int y,int v1,int v2){
    if(!now)return;
    if(r<ql || qr<l)return;
    if(ql<=l&&r<=qr){
        treap *a,*b;
        split(now->root,y-1,a,b);
        if(b)last=min(last,b->tp1mn-v1);
        if(a)last=min(last,a->tp2mn-v2);
        now->root=merge(a,b);
        return;
    }
    if(l==r)return;
    queryr(now->l,l,mid,ql,qr,y,v1,v2);
    queryr(now->r,mid+1,r,ql,qr,y,v1,v2);
}
void queryl(node *now,int l,int r,int ql,int qr,int y,int v1,int v2){
    if(!now)return;
    if(r<ql || qr<l)return;
    if(ql<=l&&r<=qr){
        treap *a,*b;
        split(now->root,y-1,a,b);
        if(a)last=min(last,v1-a->tp1mx);
        if(b)last=min(last,v2-b->tp2mx);
        now->root=merge(a,b);
        return;
    }
    if(l==r)return;
    queryl(now->l,l,mid,ql,qr,y,v1,v2);
    queryl(now->r,mid+1,r,ql,qr,y,v1,v2);
}

int main(){
    ios_base::sync_with_stdio(0);
    int q; cin>>q;
    while(q--){
        int t,x,y; cin>>t>>x>>y;
        x=(last+x)%100000000+1;
        y=(last+y)%100000000+1;
        // cout<<"x,y de: "<<x<<" "<<y<<endl;
        if(t==1){
            insert(root,1,100000000,x,y,x+y,x-y);
        }
        else{
            last=1<<30;
            queryr(root,1,100000000,x,100000000,y,x+y,x-y);
            queryl(root,1,100000000,1,x,y,x+y,x-y);
            if(last>=(1<<29))last=0;
            cout<<last<<'\n';
        }
    }
}
