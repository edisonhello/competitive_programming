#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct node{
    node *l,*r;
    int val,pri,sz;
    node(){
        l=r=NULL;
        val=0;pri=rand();sz=1;
    }
    node(int v){
        l=r=NULL;
        val=v;pri=rand();sz=1;
    }
    inline int lz(){return l?l->sz:0;}
    inline int rz(){return r?r->sz:0;}
    inline int lv(){return l?l->val:0;}
    inline int rv(){return r?r->val:0;}
} *root;
inline void pull(node *now){now->sz=now->lz()+now->rz()+1;}

node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;
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
void split(node *now,int k,node *&a,node *&b){
    if(!now)a=b=NULL;
    else if(now->val<k){
        a=now;
        split(now->r,k,a->r,b);
        pull(a);
    }
    else{
        b=now;
        split(now->l,k,a,b->l);
        pull(b);
    }
}
int query(node *now,int k){
    // cout<<now->val<<" "<<k<<endl;
    // if(k<0 || !now)while(1){}; // careful for this case, cause by line:68 x<=0
    if(k==now->lz()+1)return now->val;
    else if(k<=now->lz())return query(now->l,k);
    else return query(now->r,k-now->lz()-1);
}

void insert(int x){
    node *a,*b,*c,*t;
    split(root,x,a,t);
    split(t,x+1,b,c);
    if(!b)b=new node(x);
    t=merge(a,b);
    root=merge(t,c);
}
void ask(int x){
    if(!root || x>root->sz || x<=0)cout<<"error\n";
    else cout<<query(root,x)<<endl;
}
void remove(int x){
    node *a,*b,*c,*t;
    split(root,x,a,t);
    split(t,x+1,b,c);
    delete b;
    root=merge(a,c);
}

int main(){
    ios_base::sync_with_stdio(0);
    string s;int n;
    while(cin>>s){
        if(s[0]=='e')break;
        cin>>n;
        if(s[0]=='i')insert(n);
        if(s[0]=='a')ask(n);
        if(s[0]=='r')remove(n);
    }
}
