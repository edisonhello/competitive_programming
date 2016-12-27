#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iomanip>
using namespace std;

int n,m,vil[20005],q,djs[20005],tot,cnt,Sekai;
struct {int u,v;bool c;} edge[60005];
struct {char c;int a,b;} hist[250005];

int Find(int x){if(djs[x]==x)return x;return djs[x]=Find(djs[x]);}
inline void Union(int x,int y){x=Find(x),y=Find(y);if(x!=y)djs[x]=y;}
inline bool Check(int x,int y){return Find(x)==Find(y);}

struct node{
    node *l,*r;
    int val,sz,key;
    node():l(NULL),r(NULL),val(0),sz(1){key=rand();};
    node(int v):l(NULL),r(NULL),val(v),sz(1){key=rand();};
    inline int lz(){return l?l->sz:0;}
    inline int rz(){return r?r->sz:0;}
} *treap[20005];
inline void pull(node *now){now->sz=now->lz()+now->rz()+1;}

node *merge(node *a,node *b){
    if(!a)return b;
    if(!b)return a;
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
void split(node *now,int k,node *&a,node *&b){
    if(!now){a=b=NULL;return;}
    if(now->val>=k){
        b=now;
        split(now->l,k,a,b->l);
        pull(b);
    }
    else{
        a=now;
        split(now->r,k,a->r,b);
        pull(a);
    }
}
int getK(node *now,int k){
    if(!now)return 0;
    if(k==now->sz-now->lz()){
        return now->val;
    }
    if(k<=now->rz()){
        return getK(now->r,k);
    }
    return getK(now->l,k-1-now->rz());
}

void del(node *now){
    if(!now)return;
    if(now->l)del(now->l);
    if(now->r)del(now->r);
    delete now;
}

bool isLeaf(node *now){
    if(!now)return 0;
    if(!now->l && !now->r)return 1;
    return 0;
}
node *getNode(node *now){
    if(!now)return NULL;
    node *tmp;
    if(now->l){
        if(isLeaf(now->l)){
            tmp=now->l;
            now->l=NULL;
            return tmp;
        }
        return getNode(now->l);
    }
    if(now->r){
        if(isLeaf(now->r)){
            tmp=now->r;
            now->r=NULL;
            return tmp;
        }
        return getNode(now->r);
    }
    return now; // ?????
}

int main(){
    ios_base::sync_with_stdio(0);
    Sekai=1;
    while(cin>>n>>m, n){
        memset(vil,0,sizeof(vil));
        memset(edge,0,sizeof(edge));
        memset(hist,0,sizeof(hist));
        q=0,tot=0,cnt=0;
        for(int i=0;i<n;++i)djs[i]=i;
        for(int i=0;i<n;++i)del(treap[i]),treap[i]=NULL;

        for(int i=0;i<n;++i)cin>>vil[i];
        for(int i=0;i<m;++i)cin>>edge[i].u>>edge[i].v,edge[i].c=1;
        while(cin>>hist[q].c,hist[q].c!='E'){
            if(hist[q].c=='Q')cin>>hist[q].a>>hist[q].b;
            else if(hist[q].c=='C'){
                cin>>hist[q].a>>hist[q].b;
                swap(hist[q].b,vil[hist[q].a]);
            }
            else if(hist[q].c=='D')cin>>hist[q].a,edge[hist[q].a].c=0;
            ++q;
        }

        for(int i=0;i<m;++i)if(edge[i].c){
            Union(edge[i].u,edge[i].v);
        }

        for(int i=0;i<n;++i){
            node *a,*b,*t;
            split(treap[Find(i)],vil[i],a,b);
            t=merge(a,new node(vil[i]));
            treap[Find(i)]=merge(t,b);
        }

        for(int i=q-1;i>=0;--i){
            auto &now=hist[i];
            if(now.c=='C'){
                node *a,*t,*b,*c;
                split(treap[Find(now.a)],vil[now.a]  ,a,t);
                split(                 t,vil[now.a]+1,b,c); // remember +-
                if(b->sz>1){
                    t=merge(b->l,b->r);
                    b=merge(a,t);
                    treap[Find(now.a)]=merge(b,c);
                }
                else treap[Find(now.a)]=merge(a,c);
                vil[now.a]=now.b;
                split(treap[Find(now.a)],vil[now.a],a,b);
                t=merge(a,new node(vil[i]));
                treap[Find(now.a)]=merge(t,b);
            }
            else if(now.c=='D'){
                edge[now.a].c=1;
                if(Check(edge[now.a].u,edge[now.a].v))continue;
                if(!treap[Find(edge[now.a].u)] || !treap[Find(edge[now.a].v)])continue;
                if(treap[Find(edge[now.a].u)]->sz > treap[Find(edge[now.a].v)]->sz){
                    node *tmp,*a,*b,*t;
                    while(!isLeaf(treap[Find(edge[now.a].v)]) && (tmp=getNode(treap[Find(edge[now.a].v)]))){
                        split(treap[Find(edge[now.a].u)],tmp->val,a,b);
                        t=merge(a,tmp);
                        treap[Find(edge[now.a].u)]=merge(t,b);
                    }
                    tmp=treap[Find(edge[now.a].v)];
                    treap[Find(edge[now.a].v)]=NULL;
                    split(treap[Find(edge[now.a].u)],tmp->val,a,b);
                    t=merge(a,tmp);
                    treap[Find(edge[now.a].u)]=merge(t,b);
                    djs[Find(edge[now.a].v)]=Find(edge[now.a].u);
                }
                else{
                    node *tmp,*a,*b,*t;
                    while(!isLeaf(treap[Find(edge[now.a].u)]) && (tmp=getNode(treap[Find(edge[now.a].u)]))){
                        split(treap[Find(edge[now.a].v)],tmp->val,a,b);
                        t=merge(a,tmp);
                        treap[Find(edge[now.a].v)]=merge(t,b);
                    }
                    tmp=treap[Find(edge[now.a].u)];
                    treap[Find(edge[now.a].u)]=NULL;
                    split(treap[Find(edge[now.a].v)],tmp->val,a,b);
                    t=merge(a,tmp);
                    treap[Find(edge[now.a].v)]=merge(t,b);
                    djs[Find(edge[now.a].u)]=Find(edge[now.a].v);
                }
            }
            else if(now.c=='Q'){
                tot+=getK(treap[Find(now.a)],now.b);
                ++cnt;
            }
        }
        cout<<"Sekai "<<Sekai++<<": ";
        cout<<fixed<<setprecision(6)<<(long double)tot/(long double)cnt<<endl;
    }
}
