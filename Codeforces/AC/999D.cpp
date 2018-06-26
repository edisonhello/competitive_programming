#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int sz,pri,val,idx,tag;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void psz(){ sz=lz()+rz()+1; }
    void push(){
        if(!tag)return;
        if(l){
            l->tag+=tag;
            l->val+=tag;
        }
        if(r){
            r->tag+=tag;
            r->val+=tag;
        }
        tag=0;
    }
    void addtag(int t){
        tag+=t;
        val+=t;
    }
    node(int v=0,int i=0):l(0),r(0),pri(rand()),sz(1),val(v),idx(i),tag(0){}
} *root[200005];

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    a->push(); b->push();
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}
void split(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    now->push();
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        b->psz();
    }
    else{
        a=now;
        split(now->r,sz-1-now->lz(),a->r,b);
        a->psz();
    }
}

int a[200005];

void dfs(node *now){
    if(!now)return;
    now->push();
    dfs(now->l);
    dfs(now->r);
    a[now->idx]=now->val;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        int t; cin>>t;
        int r=t%m;
        root[r]=merge(root[r],new node(t,i));
    }
    long long ans=0;
    for(int z=0;z<2;++z){
    for(int i=0;i<m;++i){
        // cout<<i<<endl;
        if(root[i] && root[i]->sz>n/m){
            int csz=root[i]->sz-n/m;
            node *a,*b;
            split(root[i],n/m,a,b);
            // cout<<a<<" "<<b<<endl;
            ans+=csz;
            b->addtag(1);
            root[i]=a;
            root[(i+1)%m]=merge(b,root[(i+1)%m]);
        }
    }
    }
    for(int i=0;i<m;++i){
        dfs(root[i]);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    cout<<endl;
}
