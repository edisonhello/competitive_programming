#include "bubblesort2.h"
#include<bits/stdc++.h>
using namespace std;

/* struct node{
    node *l,*r;
    int val,pri,sz;
    node(int v):l(0),r(0),val(v),pri(rand()),sz(1){}
} *bit[500005];

void insert(node *&root,int v){
    node *a,*b;
    split_val(root,v,a,b);
    root=merge(merge(a,new node(v)),b);
}
void remove(node *&root,int v){
    node *a,*b,*c,*d;
    split_val(root,v-1,a,d);
    split_sz(d,1,b,c);
    delete b;
    root=merge(merge(a,b),c);
}

void add(int x,int v){ for(;x<=n;x+=x&-x)insert(bit[x],v); }
void del(int x,int v){ for(;x<=n;x+=x&-x)remove(bit[x],v); }
int query_bigger(int l,int r,int v){
    if(l>r)return 0;

} */

struct node{
    node *l,*r;
    int pri,sz,val,idx,rank,mx,tag;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=1+lz()+rz(); mx=max(idx-rank,max(l?l->mx:-7122,r?r->mx:-7122)); }
    void push(){ if(tag){ if(l)l->addtag(tag); if(r)r->addtag(tag); tag=0; } }
    void addtag(int t){ tag+=t; rank+=t; mx-=t; }
    node(int v,int i):l(0),r(0),pri(rand()),sz(1),val(v),idx(i),rank(1),mx(i-1),tag(0){}
} *root;
ostream& operator<<(ostream &o,const node &x){
    o<<"[sz: "<<x.sz<<" , val: "<<x.val<<" , idx: "<<x.idx<<" , rank: "<<x.rank<<" , mx: "<<x.mx<<" , tag: "<<x.tag<<"] ";
    return o;
}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    a->push(); b->push();
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
void split(node *now,int val,int idx,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    now->push();
    if(now->val<val || (now->val==val && now->idx<=idx)){
        a=now;
        split(now->r,val,idx,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split(now->l,val,idx,a,b->l);
        b->pull();
    }
}

void ptree(node *now,int dep){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l,dep+1),cout<<")";
    cout<<*now<<endl;
    for(int z=0;z<dep;++z)cout<<" ";
    if(now->r)cout<<"(",ptree(now->r,dep+1),cout<<")";
}

int n;

vector<int> count_scans(vector<int> _a,vector<int> xs,vector<int> vs){
    srand(clock());
    n=_a.size();
	int q=xs.size();
    vector<int> a(1,0);
    for(int i:_a)a.push_back(i);
    for(int i=1;i<=n;++i){
        node *z,*b;
        split(root,a[i],i-1,z,b);
        node *nn=new node(a[i],i);
        nn->rank=(z?z->sz:0)+1;
        nn->mx=nn->idx-nn->rank;
        if(b)b->addtag(1);
        root=merge(merge(z,nn),b);
        // cout<<"after insert "<<a[i]<<endl;
        // ptree(root,0); cout<<endl;
    }
    // ptree(root,0); cout<<endl;
    // cout<<"default max: "<<root->mx<<endl;
    for(int &i:xs)++i;
	vector<int> answer(q);
	for(int i=0;i<q;i++){
        int x=xs[i],v=vs[i];
        node *z,*b,*c,*d;
        split(root,a[x],x-1,z,d);
        split(d,a[x],x,b,c);
        delete b;
        if(c)c->addtag(-1);
        root=merge(z,c);

        // cout<<"after remove: "<<endl;
        // ptree(root,0); cout<<endl;

        a[x]=v;

        split(root,a[x],x-1,z,b);
        d=new node(a[x],x);
        d->rank=(z?z->sz:0)+1;
        d->mx=d->idx-d->rank;
        if(b)b->addtag(1);
        root=merge(merge(z,d),b);

        // cout<<"after insert: "<<endl;
        // ptree(root,0); cout<<endl;

        answer[i]=root->mx;
	}
	return answer;
}
