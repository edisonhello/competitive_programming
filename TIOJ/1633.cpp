#include<iostream>
#include<algorithm>
#include<random>
#include<ctime>
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
            swap(this->l,this->r);
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

void split(node *now,int sz,node *&a,node *&b){
    if(!now){
        a=b=NULL;
        return;
    }
    now->push();
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split(now->r,sz-now->lz()-1,a->r,b);
        a->pull();
    }
}

void print(node *now){
    if(!now)return;
    now->push();
    if(now->l)print(now->l);
    cout<<now->val<<" ";
    if(now->r)print(now->r);
}

int deep=1;
void printInfo(node *now){
    for(int i=0;i<(deep>>1);++i)cout<<" ";
    if(!now){
        cout<<"NULL"<<endl;
        --deep;
        return;
    }
    cout<<"now at "<<now<<", val:"<<now->val<<", tag:"<<now->tag<<endl;
    deep+=2;
    printInfo(now->l);
    printInfo(now->r);
}

void read(int &n,int &m){
    // cin.tie(0);
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
    char c[5];
    int l,r,ll,rr;
    while(m--){
        cin>>c;
        if(c[0]=='R'){
            cin>>l>>r;
            node *a,*b,*c,*d;
            split(root,l-1,a,b);
            split(b,r-l+1,c,d);
            // cout<<a<<" "<<c<<" "<<d<<endl;
            print(a);cout<<" ";
            print(c);cout<<" ";
            print(d);cout<<endl;
            c->tag^=1;
            b=merge(a,c);
            root=merge(b,d);
        }
        else if(c[0]=='S'){
            cin>>l>>r>>ll>>rr;
            if(ll<l){swap(l,ll);swap(r,rr);}
            node *a,*b,*c,*d,*e,*f;
            split(root,l-1,a,f);
            split(f,r-l+1,b,e);
            split(e,ll-r-1,c,f);
            split(f,rr-ll+1,d,e);
            // print(a);cout<<" ";
            // print(b);cout<<" ";
            // print(c);cout<<" ";
            // print(d);cout<<" ";
            // print(e);cout<<" "<<endl;
            f=merge(a,d);
            a=merge(f,c);
            d=merge(a,b);
            root=merge(d,e);
        }
        deep=0;
        printInfo(root);
        // print(root);
        // cout<<endl;
    }
}


int main(){
    int n,m;
    srand(7122);
    read(n,m);
    build(n);
    solve(m);
    print(root);
    cout<<endl;
}
