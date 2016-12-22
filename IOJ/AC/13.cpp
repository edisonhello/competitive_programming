#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int n,m;

struct node{
    int v,p,sz;
    node *l,*r;
    bool tag;
    node(int v){
        this->p=rand();
        this->v=v;
        l=r=NULL;
        tag=0;
        sz=1;
    }
    int lz(){
        if(this->l)return this->l->sz;
        return 0;
    }
    int rz(){
        if(this->r)return this->r->sz;
        return 0;
    }
} *root;

void push(node *now){
    //cout<<"in "<<now<<endl;
    if(now->tag){
        if(now->l)now->l->tag^=1;
        if(now->r)now->r->tag^=1;
        swap(now->l,now->r);
        now->tag^=1;
    }
    //cout<<"out<<endl;"<<endl;
}
void pull(node *now){
    now->sz=1+now->lz()+now->rz();
}

node* merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;
    push(a),push(b);
    if(a->p>b->p){
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

void split(node *now,int k,node *&a,node *&b){
    if(!now){a=b=NULL;return;}
    //cout<<"sp"<<endl;
    push(now);
    if(now->lz()<k){
        a=now;
        split(now->r,k-now->lz()-1,a->r,b);
        pull(a);
    }
    else{
        b=now;
        split(now->l,k,a,b->l);
        pull(b);
    }
}

void init(){
    root=new node(1);
    for(int i=2;i<=n;++i){
        node *tmp=new node(i);
        root=merge(root,tmp);
    }
}

void print(node *now){
    push(now);
    if(now->l)print(now->l);
    cout<<now->v<<" ";
    if(now->r)print(now->r);
}

int main(){
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    cin>>n>>m;
    init();
    while(m--){
        int c,l,r,ll,rr;
        cin>>c;
        if(c==1){
            cin>>l>>r;
            node *a,*t,*b,*c;
            split(root,l-1,a,t);
            split(t,r-l+1,b,c);
            //cout<<"jiozz<<en"<<endl;
            b->tag^=1;
            t=merge(a,b);
            root=merge(t,c);
            //print(root);
        }
        else if(c==2){
            cin>>l>>r>>ll>>rr;
            node *a,*b,*c,*d,*e,*t;
            split(root,l-1,a,t);
            split(t,r-l+1,b,e);
            split(e,ll-r-1,c,t);
            split(t,rr-ll+1,d,e);
            t=merge(a,d);
            a=merge(t,c);
            t=merge(a,b);
            root=merge(t,e);
        }
    }
    print(root);
}
