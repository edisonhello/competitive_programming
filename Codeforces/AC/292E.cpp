#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005];

struct node{
    node *l,*r;
    int ref;
    node():l(0),r(0),ref(0){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}

void push(node *now,int l,int r){
    if(!now)exit(7123);
    now->l->ref=now->ref;
    now->r->ref=now->ref+mid-l+1;
    now->ref=0;
}

void modify(node *now,int l,int r,int ml,int mr,int rl,int rr){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->ref=l-ml+rl;
        return;
    }
    if(now->ref)push(now,l,r);
    modify(now->l,l,mid,ml,mr,rl,rr);
    modify(now->r,mid+1,r,ml,mr,rl,rr);
}

int query(node *now,int l,int r,int x){
    if(x<l || r<x)exit(7122);
    if(l==x && x==r)return now->ref?a[now->ref]:b[l];
    if(now->ref)push(now,l,r);
    if(x<=mid)return query(now->l,l,mid,x);
    else return query(now->r,mid+1,r,x);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i];
    build(root=new node(),1,n);
    while(m--){
        int c; cin>>c;
        if(c==1){
            int x,y,k; cin>>x>>y>>k;
            modify(root,1,n,y,y+k-1,x,x+k-1);
        }
        else{
            int x; cin>>x;
            cout<<query(root,1,n,x)<<endl;
        }
    }
}
