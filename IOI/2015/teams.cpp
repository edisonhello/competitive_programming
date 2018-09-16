// #include"teams.h"
#include<bits/stdc++.h>
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

int root[500005],node[500005*45][3];
int ptr;

inline int gn(int ref=-1){
    ++ptr;
    if(~ref)memcpy(node[ptr],node[ref],3<<2);
    else memset(node[ptr],0,3<<2);
    return ptr;
}

int n;
pair<int,int> p[500005];

#define mid ((l+r)>>1)
void build(int now,int l,int r){
    if(l==r)return;
    build(node[now][0]=gn(),l,mid);
    build(node[now][1]=gn(),mid+1,r);
}

void modify(int now,int l,int r,int x){
    ++node[now][2];
    if(l==r){ return; }
    if(x<=mid)modify(node[now][0]=gn(node[now][0]),l,mid,x);
    else modify(node[now][1]=gn(node[now][1]),mid+1,r,x);
}

int query(int nl,int nr,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    // cout<<"query range "<<l<<" to "<<r<<" cur v: "<<nl->v<<" and "<<nr->v<<endl;
    if(ql<=l&&r<=qr)return node[nr][2]-node[nl][2];
    return query(node[nl][0],node[nr][0],l,mid,ql,qr)+query(node[nl][1],node[nr][1],mid+1,r,ql,qr);
}

void init(int _n,int _a[],int _b[]){
    srand(clock());
    n=_n;
    for(int i=0;i<n;++i)p[i+1]={_a[i],_b[i]};
    sort(p+1,p+n+1);
    build(root[0]=gn(),1,n);
    int ptr=1;
    for(int i=1;i<=n;++i){
        root[i]=gn(root[i-1]);
        while(ptr<=n && p[ptr].first<=i)modify(root[i]=gn(root[i]),1,n,p[ptr].second),++ptr;
    }
}

namespace naive{
struct node{
    node *l,*r;
    int sz,pri,val;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
    node(int v=0):l(0),r(0),sz(1),pri(rand()),val(v){}
} *root,pool[500005];

int _ptr;
node *gnode(int v){
    pool[_ptr].l=0;
    pool[_ptr].r=0;
    pool[_ptr].sz=1;
    pool[_ptr].val=v;
    return &pool[_ptr++];
}

node *merge(node *a,node *b){
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

void split_val(node *now,int val,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->val<=val){
        a=now;
        split_val(now->r,val,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split_val(now->l,val,a,b->l);
        b->pull();
    }
}

void split_sz(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->lz()>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}

int solve(int m,int k[]){
    _ptr=0;
    int ptr=1;
    for(int i=0;i<m;++i){
        while(ptr<=n && p[ptr].first<=k[i]){
            node *a,*b;
            split_val(root,p[ptr].second,a,b);
            root=merge(merge(a,gnode(p[ptr].second)),b);
            ++ptr;
        }
        node *a,*b;
        split_val(root,k[i]-1,a,b);
        if(!b || b->sz<k[i]){
            root=0;
            return 0;
        }
        node *c,*d;
        split_sz(b,k[i],c,d);
        root=d;
    }
    root=0;
    return 1;
}

}

#define BOUND 450
int dp[BOUND+4];
int can(int m,int k[]){
    sort(k,k+m);
    // return naive::solve(m,k);
    if(m>BOUND)return naive::solve(m,k);
    else{
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<m;++i){
            int mn=9897788;
            for(int j=0;j<=i;++j){
                if(j==0)mn=query(root[0],root[k[i]],1,n,k[i],n);
                else mn=min(mn,dp[j-1]+query(root[k[j-1]],root[k[i]],1,n,k[i],n));
                // cout<<"j: "<<j<<" , mn: "<<mn<<endl;
            }
            dp[i]=mn-k[i];
            // cout<<"at "<<i<<" , dp: "<<dp[i]<<endl;
            if(dp[i]<0)return 0;
        }
        return 1;
    }
}

#ifdef WEAK
int l[500005],r[500005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>l[i]>>r[i];
    init(n,l,r);
    int m; cin>>m; while(m--){
        int k; cin>>k;
        int *a=new int[k];
        for(int i=0;i<k;++i)cin>>a[i];
        cout<<can(k,a)<<endl;
    }
}
#endif
// tutorial
