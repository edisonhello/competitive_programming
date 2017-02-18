#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<vector>
using namespace std;

int n,m,vi[20005],q,d[20005],peop,qs,Sekai;
struct {char t;int a,b;} hist[310005];
struct {bool c;int u,v;} edge[60006];

int F(int x){if(d[x]==x)return x;return d[x]=F(d[x]);}
inline bool C(int x,int y){return F(x)==F(y);}
inline void U(int x,int y){x=F(x),y=F(y);if(x==y)return;d[x]=y;}

struct node{
    node *l,*r;
    int val,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    node():l(NULL),r(NULL),val(0),sz(1){};
    node(int v):l(NULL),r(NULL),val(v),sz(1){};
} *root[20005];

inline void psz(node *now){now->sz=now->lz()+now->rz()+1;}
inline void rot(node *&now){
    node *tmp;
    if(now->lz()>now->rz()){
        tmp=now->l;
        now->l=tmp->r;
        tmp->r=now;
        now=tmp;
    }
    else if(now->rz()>now->lz()){
        tmp=now->r;
        now->r=tmp->l;
        tmp->l=now;
        now=tmp;
    }
}
inline void pull(node *now){
    if(now->l)psz(now->l);
    if(now->r)psz(now->r);
    if(now->l && now->r)rot(now);
    if(now->l)psz(now->l);
    if(now->r)psz(now->r);
    psz(now);
}

void insert(node *&now,int v){
    if(!now)now=new node(v);
    else if(now->val>v)insert(now->l,v);
    else insert(now->r,v);
    pull(now);
}

void del(node *&now,int x){
    if(!now)return;
    if(now->val==x){
        node *tmp;
        if(now->l && now->r){
            tmp=now;
            if(!now->l->r){
                now=now->l;
                delete tmp;
            }
            else{
                node *pr=now->l;
                tmp=now->l->r;
                while(tmp->r){pr=tmp;tmp=tmp->r;}
                now->val=tmp->val;
                pr->r=tmp->l;
                delete tmp;
            }
        }
        else if(now->l){
            tmp=now;
            now=now->l;
            delete tmp;
        }
        else if(now->r){
            tmp=now;
            now=now->r;
            delete tmp;
        }
        else{
            tmp=now;
            now=NULL;
            delete tmp;
        }
    }
    else if(now->val<x)del(now->r,x);
    else del(now->l,x);
}

void modify(int x,int k){
    // cout<<"b4msz:"<<root[F(x)]->sz<<" ";
    del(root[F(x)],vi[x]);
    // cout<<"delsz"<<root[F(x)]->sz<<" ";
    vi[x]=k;
    insert(root[F(x)],vi[x]);
    // cout<<"inssz"<<root[F(x)]->sz<<endl;
}

void merge(node *now,node *bemg){
    if(bemg->l)merge(now,bemg->l);
    if(bemg->r)merge(now,bemg->r);
    insert(now,bemg->val);
    delete bemg;
}

int getK(node *now,int k){
    if(!now)return 0;
    if(now->rz()>=k)return getK(now->r,k);
    if(now->rz()+1==k)return now->val;
    return getK(now->l,k-1-now->rz());
}

void printTreap(node *now){
    if(!now)return;
    if(now->l){cout<<"(";printTreap(now->l);cout<<")";}
    cout<<now->val;
    if(now->r){cout<<"(";printTreap(now->r);cout<<")";}
}

void proc(){
    while(q--){
        // printTreap(root[1]);cout<<endl;
        auto &now=hist[q];
        // cout<<"doing "<<now.t<<" "<<now.a<<" "<<now.b<<endl;
        if(now.t=='Q'){
            peop+=getK(root[F(now.a)],now.b);
            ++qs;
            // cout<<"Q! "<<peop<<" "<<qs<<endl;
        }
        else if(now.t=='C'){
            modify(now.a,now.b);
        }
        else if(now.t=='D'){
            auto eg=edge[now.a];
            if(C(eg.u,eg.v))continue;
            if(root[F(eg.u)]->sz > root[F(eg.v)]->sz){ // jizz?
                merge(root[F(eg.u)],root[F(eg.v)]);
                root[F(eg.v)]=NULL;
                d[eg.v]=eg.u;
            }
            else{
                merge(root[F(eg.v)],root[F(eg.u)]);
                root[F(eg.u)]=NULL;
                d[eg.u]=eg.v;
            }
        }
    }
}

void print(){
    cout<<"Sekai "<<(++Sekai)<<": ";
    #define ld long double
    cout<<fixed<<setprecision(6)<<(ld)peop/(ld)qs<<endl;
}

void init(){
    for(int i=0;i<n;++i)d[i]=i;
    for(int i=0;i<m;++i)if(edge[i].c){
        U(edge[i].u,edge[i].v);
    }
    // cout<<"djs:";for(int i=0;i<n;++i)cout<<d[i]<<" ";cout<<endl;
    for(int i=0;i<n;++i){
        insert(root[F(i)],vi[i]);
    }
    // cout<<"tsz:";for(int i=0;i<n;++i)cout<<(root[i]?root[i]->sz:0)<<" ";cout<<endl;
}

void read(){
    for(int i=0;i<n;++i)cin>>vi[i];
    for(int i=0;i<m;++i){
        cin>>edge[i].u>>edge[i].v;
        edge[i].c=1;
    }
    while(cin>>hist[q].t && hist[q].t!='E'){
        if(hist[q].t=='Q')cin>>hist[q].a>>hist[q].b;
        else if(hist[q].t=='C'){
            cin>>hist[q].a>>hist[q].b;
            swap(vi[hist[q].a],hist[q].b);
        }
        else if(hist[q].t=='D'){
            cin>>hist[q].a;
            edge[hist[q].a].c=0;
        }
        ++q;
    }
}
void clearTreap(node *now){
    if(!now)return;
    clearTreap(now->l);
    clearTreap(now->r);
    delete now;
}
void clear(){
    for(int i=0;i<n;++i)clearTreap(root[i]),root[i]=NULL;
    memset(hist,0,sizeof(hist));
    memset(edge,0,sizeof(edge));
    memset(vi,0,sizeof(vi));
    memset(d,0,sizeof(d));
    q=peop=qs=0;
}
int main(){
    while(cin>>n>>m, n){
        clear();
        read();
        init();
        proc();
        print();
    }
}
