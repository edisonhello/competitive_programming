#include<bits/stdc++.h>
using namespace std;

namespace MEOW{

struct node{
    node *l,*r;
    int val,sz;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
    bool isleaf(){ return !(l||r); }
    node():l(0),r(0),val(0),sz(1){}
} pool[100005*60];

node *gnode(){
    static int p=0;
    return &pool[++p];
}

void lspin(node *&now){
    node *tmp=now->l;
    now->l=tmp->r;
    tmp->r=now;
    now=tmp;
    now->r->pull();
    now->pull();
}
void rspin(node *&now){
    node *tmp=now->r;
    now->r=tmp->l;
    tmp->l=now;
    now=tmp;
    now->l->pull();
    now->pull();
}

void insert(node *&now,int x){
    if(!now){
        now=gnode();
        now->val=x;
        return;
    }
    if(now->val>x){
        insert(now->l,x);
        now->pull();
        if(now->lz()>now->rz()+2)lspin(now);
    }
    else{
        insert(now->r,x);
        now->pull();
        if(now->rz()>now->lz()+2)rspin(now);
    }
}

void erase(node *&now,int x){
    assert(now);
    if(now->val==x){
        if(now->isleaf())now=0;
        else if(now->l){
            lspin(now);
            erase(now->r,x);
            now->pull();
            if(now->rz()>now->lz()+2)rspin(now);
        }
        else{
            rspin(now);
            erase(now->l,x);
            now->pull();
            if(now->lz()>now->rz()+2)lspin(now);
        }
    }
    else if(now->val>x){
        erase(now->l,x);
        now->pull();
        if(now->rz()>now->lz()+2)rspin(now);
    }
    else{
        erase(now->r,x);
        now->pull();
        if(now->lz()>now->rz()+2)lspin(now);
    }
}

int nth(node *now,int v){
    if(!now)return 0;
    if(now->val==v)return now->lz()+1;
    if(now->val>v)return nth(now->l,v);
    return now->lz()+1+nth(now->r,v);
}

unordered_map<int,node*> mp;

void add(int x,int pos){
    insert(mp[x],pos);
}
void remove(int x,int pos){
    erase(mp[x],pos);
}
int check(int l,int r,int x){
    return nth(mp[x],r)-nth(mp[x],l-1);
}


}

struct node{
    int v,c,x;
    void init(){ x=v; c=1; }
    node(int v=0,int c=0,int x=0):v(v),c(c),x(x){}
} z[400005];
int pos[100005];

node operator+(const node a,const node b){
    node r;
    r.x=max(a.x,b.x);
    if(a.v==b.v){
        r.v=a.v;
        r.c=a.c+b.c;
    }
    else if(a.c>=b.c){
        r.v=a.v;
        r.c=a.c-b.c;
    }
    else{
        r.v=b.v;
        r.c=b.c-a.c;
    }
    return r;
}

#define mid ((l+r)>>1)
#define lc (((o)<<1))
#define rc (((o)<<1)|1)
void pull(int o){
    z[o]=z[lc]+z[rc];
}

void build(int o,int l,int r){
    if(l==r){
        pos[l]=o;
        cin>>z[o].v;
        MEOW::add(z[o].v,l);
        z[o].init();
        return;
    }
    build(lc,l,mid);
    build(rc,mid+1,r);
    pull(o);
}

void update(int o,int ox,int y){
    MEOW::remove(z[o].v,ox);
    z[o].v=y;
    MEOW::add(z[o].v,ox);
    z[o].init();
    for(o>>=1;o;o>>=1)pull(o);
}

void modify(int o,int l,int r,int ml,int mr,int k){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        if(z[o].x==0)return;
        if(l==r){
            MEOW::remove(z[o].v,l);
            z[o].v/=k;
            MEOW::add(z[o].v,l);
            z[o].init();
            return;
        }
    }
    modify(lc,l,mid,ml,mr,k);
    modify(rc,mid+1,r,ml,mr,k);
    pull(o);
}

node query(int o,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return node(-1,0,0);
    if(ql<=l&&r<=qr)return z[o];
    return query(lc,l,mid,ql,qr)+query(rc,mid+1,r,ql,qr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    build(1,1,n);
    while(q--){
        int c; cin>>c;
        switch(c){
            case 1:
                int x,y; cin>>x>>y;
                update(pos[x],x,y);
                break;
            case 2:
                int l,r,k; cin>>l>>r>>k;
                if(k>1)modify(1,1,n,l,r,k);
                break;
            case 3:
                cin>>l>>r;
                x=query(1,1,n,l,r).v;
                if(MEOW::check(l,r,x)>=(r-l+3)/2)cout<<x<<'\n';
                else cout<<"-1\n";
                break;
        }
    }
}
