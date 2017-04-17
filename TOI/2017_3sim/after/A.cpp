#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second

int t[1000006];
pii work[100005];

struct node{
    node *l,*r;
    int val,tag,sz,pri;
    node():l(NULL),r(NULL),val(0),tag(0),sz(1),pri(rand()){};
    node(int v):l(NULL),r(NULL),val(v),tag(0),sz(1),pri(rand()){};
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
} *treap;

void push(node *now){
    if(now->tag){
        now->val+=now->tag;
        if(now->l)now->l->tag+=now->tag;
        if(now->r)now->r->tag+=now->tag;
        now->tag=0;
    }
}
void pull(node *now){
    if(!now)return;
    now->sz=now->lz()+now->rz()+1;
}
void split_by_rank(node *now,int rank,node *&l,node *&r){
    // cout<<"in split_by_rank, rank: "<<rank<<endl;
    if(!now){l=r=NULL; return;}
    push(now);
    if(rank<=now->lz()){r=now; split_by_rank(now->l,rank,l,r->l); pull(r);}
    else{l=now; split_by_rank(now->r,rank-1-now->lz(),l->r,r); pull(l);}
}
void split_by_val(node *now,int val,node *&l,node *&r){
    if(!now){l=r=NULL; return;}
    push(now);
    if(val<=now->val){r=now; split_by_val(now->l,val,l,r->l); pull(r);}
    else{l=now; split_by_val(now->r,val,l->r,r); pull(l);}
}
node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        pull(a); return a;
    }
    else{
        b->l=merge(a,b->l);
        pull(b); return b;
    }
}
void addNum(int val){
    // // cout<<"call addNum "<<val<<endl;
    node *tmpl,*tmpr,*tmp; split_by_val(treap,val,tmpl,tmpr);
    tmp=merge(tmpl,new node(val)); treap=merge(tmp,tmpr);
}
int go_left(node *now){
    if(!now)return 99999999;
    push(now);
    if(now->l)return go_left(now->l);
    return now->val;
}
int go_right(node *now){
    if(!now)return -987;
    push(now);
    if(now->r)return go_right(now->r);
    return now->val;
}
// void printTreap(node *now){
//     if(!now)return;
//     if(now->l)// cout<<"(",printTreap(now->l),// cout<<")";
//     // cout<<now->val<<","<<now->tag;
//     if(now->r)// cout<<"(",printTreap(now->r),// cout<<")";
// }

int main(){
    int n;cin>>n;
    for(int i=0;i<n;++i){
        int l,r;cin>>l>>r;
        ++t[l],--t[r+1];
    }
    for(int i=1;i<1000006;++i)t[i]+=t[i-1];
    int m;cin>>m;
    for(int i=0;i<m;++i)cin>>work[i].X>>work[i].Y;
    sort(work,work+m,[](const pii &a,const pii &b){return a.Y<b.Y;});
    int nt=0;
    for(int i=0;i<m;++i){ // cout<<"processing i:"<<i<<endl;
        while(nt<work[i].Y)addNum(t[++nt]); // cout<<"moved time"<<endl; printTreap(treap);cout<<endl;
        node *tmpl,*tmpr; split_by_rank(treap,work[i].X,tmpl,tmpr); // cout<<"after split_by_rank"<<endl;
        ++tmpl->tag; int rightest=go_right(tmpl),leftest=go_left(tmpr); // cout<<"go right, go left"<<endl; printTreap(tmpl);cout<<" ,, ";printTreap(tmpr);cout<<endl;
        if(rightest>leftest){ // cout<<"reverse"<<endl;
            node *tmpll,*tmplr; split_by_val(tmpl,rightest,tmpll,tmplr); // cout<<"after split_by_val"<<endl; printTreap(tmpll);cout<<" ,, ";printTreap(tmplr);cout<<endl;
            node *tmprl,*tmprr; split_by_val(tmpr,leftest+1,tmprl,tmprr); // cout<<"after split_by_val"<<endl; printTreap(tmprl);cout<<" ,, ";printTreap(tmprr);cout<<endl;
            tmpl=merge(tmpll,tmprl), tmpr=merge(tmplr,tmprr); // cout<<"merged"<<endl; printTreap(tmpl);cout<<" ,, ";printTreap(tmpr);cout<<endl;
        }
        treap=merge(tmpl,tmpr); // cout<<"merged"<<endl;
    }
    while(nt<1000006)addNum(t[++nt]);
    cout<<go_right(treap)<<endl;
}
// AC
