#include<bits/stdc++.h>
using namespace std;

int a[100005];

struct node{
    node *l,*r,*pa;
    int pri,sz,p,mxp;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    int lp(){return l?l->mxp:0;}
    int rp(){return r?r->mxp:0;}
    int lv(){return a[lp()];}
    int rv(){return a[rp()];}
    int val(){return a[p];}
    void pull(){
        sz=lz()+rz()+1;
        if(val()>lv() && val()>rv())mxp=p;
        else if(lv()>val() && lv()>rv())mxp=lp();
        else mxp=rp();
    }
    node(int p):l(0),r(0),pa(0),pri(rand()),sz(1),p(p),mxp(p){}
} *root,*rec[100005];

void split(node *now,int sz,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        b->pa=0;
        if(b->l)b->l->pa=b;
        b->pull();
    }
    else{
        a=now;
        split(now->r,sz-1-now->lz(),a->r,b);
        a->pa=0;
        if(a->r)a->r->pa=a;
        a->pull();
    }
}

node *merge(node *a,node *b){
    if(!(a&&b))return a?:b;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        if(a->r)a->r->pa=a;
        a->pa=0;
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        if(b->l)b->l->pa=b;
        b->pa=0;
        return b;
    }
}

void print(node *now){
    if(!now)return;
    print(now->l);
    cout<<a[now->p]<<'\n';
    print(now->r);
}

int gsz(node *now){
    // cout<<"now: "<<now<<endl;
    int rt=now->lz();
    while(now){
        // cout<<"now and pa: "<<now<<" "<<now->pa<<endl;
        if(now->pa && now->pa->r==now){
            rt+=now->pa->lz()+1;
        }
        now=now->pa;
    }
    return rt;
}

int main(){
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)root=merge(root,rec[i]=new node(i));
    for(int i=1;i<n;++i){
        node *a,*b,*c,*d;
        // cout<<"split root: "<<root<<" with size "<<root->sz<<endl;
        split(root,i-1,a,d);
        // cout<<"split2 "<<endl;
        split(d,k+1,b,c);
        // cout<<"b: "<<b<<endl;
        // cout<<"b->sz: "<<b->sz<<endl;
        int mxp=b->mxp;
        // cout<<mxp<<endl;
        int lsz=gsz(rec[mxp]);
        // cout<<mxp<<" "<<lsz<<" "<<b->sz<<endl;
        node *e,*f,*g,*h;
        split(b,lsz,e,h);
        split(h,1,f,g);
        // cout<<"splitttt"<<endl;
        root=merge(merge(merge(merge(a,f),e),g),c);
        // cout<<"mergggg"<<endl;
        k-=lsz;
    }
    print(root);
}
