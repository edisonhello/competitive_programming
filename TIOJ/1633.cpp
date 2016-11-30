#include<iostream>
using namespace std;
struct node{
    node *l,*r;
    int val,pri,sz;
    bool tag;
    node(){
        l=r=NULL;
        val=0,pri=rand(),sz=1,tag=0;
    }
    node(int val){
        this->l=this->r=NULL;
        this->val=val,this->pri=rand(),this->sz=1,tag=0;
    }
    inline int lz(){return this->l?this->l->sz:0;}
    inline int rz(){return this->r?this->r->sz:0;}
    inline void pull(){this->sz=this->lz()+this->rz()+1;}
    inline void push(){
        if(this->tag){
            if(this->l)this->l->tag^=1;
            if(this->r)this->r->tag^=1;
            node *tmp=this->l;
            this->l=this->r,this->r=tmp;
            this->tag=0;
        }
    }
} *root;

node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;
    a->push(),b->push();
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(b->l,a);
        b->pull();
        return b;
    }
}

void read(int &n,int &m){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
}
void build(int &n){
    for(int i=1;i<=n;++i){
        node *tmp=new node(i);
        root=merge(root,tmp);
    }
}
void solve(int &m){
    char c[5];cin>>c;
    int a,b,c,d;
    if(c[0]=='R'){
        
    }
    else if(c[0]=='S'){
        
    }
}

int main(){
    int n,m;
    read(n,m);
    build(n);
    solve(m);
}
