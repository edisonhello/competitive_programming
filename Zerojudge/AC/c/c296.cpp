#include<bits/stdc++.h>
using namespace std;


struct node{
    node *l,*r;
    int val,key,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    node(int v=0):l(0),r(0),val(v),sz(1),key(rand()){}
} *root;

void pull(node *now){
    if(!now)return;
    now->sz=1+(now->l?now->l->sz:0)+(now->r?now->r->sz:0);
}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->key>b->key){
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
void split(node *s,int sz,node *&a,node *&b){
    if(!s){a=0,b=0; return;}
    if(s->lz()>=sz){
        b=s;
        split(s->l,sz,a,b->l);
        pull(a);
        pull(b);
    }
    else{
        a=s;
        split(s->r,sz-s->lz()-1,a->r,b);
        pull(a);
        pull(b);
    }
}

int main(){
    srand(time(0));
    int n,m,k; cin>>n>>m>>k;
    for(int i=1;i<=n;++i)root=merge(root,new node(i));
    for(int i=1;i<=k;++i){
        node *a,*b,*c,*d;
        int front=m%root->sz;
        if(front==0)front=root->sz;
        --front;
        split(root,front,a,d);
        split(d,1,b,c);
        root=merge(c,a);
    }
    node *a,*b;
    split(root,1,a,b);
    cout<<a->val<<endl;
}
