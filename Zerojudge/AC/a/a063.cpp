#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int sz,i,tag,pri;
    node(int x):l(0),r(0),sz(1),i(x),tag(0),pri(rand()){}
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void addtag(){tag^=1; swap(l,r);}
    void psz(){sz=lz()+rz()+1;}
    void push(){
        if(!tag)return;
        if(l)l->addtag();
        if(r)r->addtag();
        tag=0;
    }
} *root;

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->push();
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->push();
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}
void split(node *s,int sz,node *&a,node *&b){
    if(!s){a=b=0; return;}
    s->push();
    if(s->lz()>=sz){
        b=s;
        split(s->l,sz,a,b->l);
        b->psz();
    }
    else{
        a=s;
        split(s->r,sz-1-s->lz(),a->r,b);
        a->psz();
    }
}
void go(node *now){
    if(!now)return;
    now->push();
    go(now->l);
    cout<<now->i<<" ";
    go(now->r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)root=merge(root,new node(i));
    while(m--){
        int s,t; cin>>s>>t;
        node *a,*b,*c,*d;
        split(root,s-1,a,d);
        split(d,t-s+1,b,c);
        b->addtag();
        root=merge(merge(a,b),c);
    }
    go(root); cout<<endl;
}
