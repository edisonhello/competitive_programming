#pragma GCC optimize("no-stack-protector,Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

struct treap{
    treap *l,*r;
    int pri,val,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=1+lz()+rz();}
    treap(int v=0):l(0),r(0),pri(rand()),val(v),sz(1){}
    treap(treap *ref):l(ref->l),r(ref->r),pri(ref->pri),val(ref->val),sz(ref->sz){}
} *troot[100005],tpool[12000005];
int tptr;

struct seg{
    seg *l,*r;
    int val;
    seg():l(0),r(0),val(0){};
} *sroot[100005],spool[4500005];
int sptr;

inline treap *copy(treap *ref){
    tpool[tptr].l=ref->l;
    tpool[tptr].r=ref->r;
    tpool[tptr].pri=ref->pri;
    tpool[tptr].val=ref->val;
    tpool[tptr].sz=ref->sz;
    ++tptr;
    return &tpool[tptr-1];
}

inline treap *gettreap(int pq){
    tpool[tptr].val=pq;
    ++tptr;
    return &tpool[tptr-1];
}
inline treap *gettreap(treap *ref){
    if(ref==0)return 0;
    return copy(ref);
}
inline seg *getseg(){
    ++sptr;
    return &spool[sptr-1];
}
inline seg *getseg(seg *ref){
    spool[sptr].l=ref->l;
    spool[sptr].r=ref->r;
    spool[sptr].val=ref->val;
    ++sptr;
    return &spool[sptr-1];
}

unordered_map<string,int> idmap;
int idptr;
int gid(string &s){
    auto it=idmap.find(s);
    if(it==idmap.end()){
        idmap[s]=idptr; ++idptr;
        return idptr-1;
    }
    else return it->second;
}

void split_val(treap *now,int val,treap *&a,treap *&b){
    if(!now){a=b=0; return;}
    if(now->val>val){
        b=gettreap(now);
        split_val(now->l,val,a,b->l);
        b->psz();
    }
    else{
        a=gettreap(now);
        split_val(now->r,val,a->r,b);
        a->psz();
    }
}
void split_sz(treap *now,int sz,treap *&a,treap *&b){
    if(!now){a=b=0; return;}
    if(now->lz()>=sz){
        b=gettreap(now);
        split_sz(now->l,sz,a,b->l);
        b->psz();
    }
    else{
        a=gettreap(now);
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->psz();
    }
}
treap *merge(treap *a,treap *b){
    if(!a)return gettreap(b);
    if(!b)return gettreap(a);
    if(a->pri>b->pri){
        treap *rt=gettreap(a);
        rt->r=merge(a->r,b);
        rt->psz();
        return rt;
    }
    else{
        treap *rt=gettreap(b);
        rt->l=merge(a,b->l);
        rt->psz();
        return rt;
    }
}

#define mid ((l+r)>>1)
void build(seg *now,int l,int r){
    if(l==r)return;
    build(now->l=getseg(),l,mid);
    build(now->r=getseg(),mid+1,r);
}
void modify(seg *now,int l,int r,int x,int v){
    if(l==r){
        now->val=v;
        return;
    }
    if(x<=mid)modify(now->l=getseg(now->l),l,mid,x,v);
    else modify(now->r=getseg(now->r),mid+1,r,x,v);
}
int query(seg *now,int l,int r,int x){
    if(l==r)return now->val;
    if(x<=mid)return query(now->l,l,mid,x);
    else return query(now->r,mid+1,r,x);
}
#undef mid

inline void addwork(treap *&troot,seg *sroot,int id,int pq){
    treap *l,*r;
    split_val(troot,pq,l,r);
    troot=merge(merge(l,gettreap(pq)),r);
    modify(sroot,0,100000,id,pq);
}
inline void editwork(treap *&troot,seg *sroot,int id,int pq){
    treap *a,*b,*c,*d;
    split_val(troot,query(sroot,0,100000,id)-1,a,d);
    split_sz(d,1,b,c);
    troot=merge(a,c);
    split_val(troot,pq,a,c);
    troot=merge(merge(a,gettreap(pq)),c);
    modify(sroot,0,100000,id,pq);
}
inline void deletework(treap *&troot,seg *sroot,int id){
    treap *a,*b,*c,*d;
    split_val(troot,query(sroot,0,100000,id)-1,a,d);
    split_sz(d,1,b,c);
    troot=merge(a,c);
    modify(sroot,0,100000,id,0);
}
inline int query(treap *&troot,int pq){
    if(!troot)return 0;
    if(troot->val<=pq)return query(troot->r,pq)+troot->lz()+1;
    else return query(troot->l,pq);
}

void ptree(treap *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    build(sroot[0]=getseg(),0,100000);
    int q; cin>>q; for(int i=1;i<=q;++i){
        string cmd; cin>>cmd;
        if(cmd[0]=='s'){
            troot[i]=gettreap(troot[i-1]);
            sroot[i]=getseg(sroot[i-1]);
            string work; cin>>work;
            int id=gid(work);
            int x; cin>>x;
            if(query(sroot[i],0,100000,id)==0)addwork(troot[i],sroot[i],id,x);
            else editwork(troot[i],sroot[i],id,x);
        }
        else if(cmd[0]=='r'){
            troot[i]=gettreap(troot[i-1]);
            sroot[i]=getseg(sroot[i-1]);
            string work; cin>>work;
            int id=gid(work);
            if(query(sroot[i],0,100000,id))deletework(troot[i],sroot[i],id);
        }
        else if(cmd[0]=='q'){
            troot[i]=gettreap(troot[i-1]);
            sroot[i]=getseg(sroot[i-1]);
            string work; cin>>work;
            int id=gid(work);
            if(query(sroot[i],0,100000,id))cout<<query(troot[i],query(sroot[i-1],0,100000,id)-1)<<endl;
            else cout<<-1<<endl;
        }
        else{
            int undo; cin>>undo;
            troot[i]=troot[i-undo-1];
            sroot[i]=sroot[i-undo-1];
        }
        // ptree(troot[i]);
        // cout<<endl;
    }
}
