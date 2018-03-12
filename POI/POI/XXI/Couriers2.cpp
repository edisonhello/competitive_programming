/* tutorial by bc4iaa */

#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int sz;
    node():l(0),r(0),sz(0){}
    node(node *ref):l(ref->l),r(ref->r),sz(ref->sz){}
    int lsz(){return l?l->sz:0;}
    int rsz(){return r?r->sz:0;}
    void pull(){sz=lsz()+rsz();}
    node *copy(node *ref){l=ref->l, r=ref->r, sz=ref->sz; return this;}
} *root[500005],pool[10000005];

int a[500005],ptr=-1;



#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){return;}
    build(now->l=&pool[++ptr],l,mid);
    build(now->r=&pool[++ptr],mid+1,r);
}
void modify(node *now,int l,int r,int x){
    if(l==r){
        ++now->sz;
        return;
    }
    if(x<=mid)modify(now->l=pool[++ptr].copy(now->l),l,mid,x);
    else modify(now->r=pool[++ptr].copy(now->r),mid+1,r,x);
    now->pull();
}
int query(node *nowl,node *nowr,int l,int r,int gt){
    if(l==r){
        if(nowr->sz-nowl->sz>gt)return l;
        else return 0;
    }
    if(nowr->l->sz-nowl->l->sz>gt)return query(nowl->l,nowr->l,l,mid,gt);
    if(nowr->r->sz-nowl->r->sz>gt)return query(nowl->r,nowr->r,mid+1,r,gt);
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root[0]=&pool[++ptr],1,n);
    for(int i=1;i<=n;++i)modify(root[i]=pool[++ptr].copy(root[i-1]),1,n,a[i]);
    while(m--){
        int l,r; cin>>l>>r;
        cout<<query(root[l-1],root[r],1,n,(r-l+1)/2)<<'\n';
    }
}
