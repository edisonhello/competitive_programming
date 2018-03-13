#include<bits/stdc++.h>
using namespace std;
#ifdef WEAK
#include"../template/debug.cpp"
#else
#define PDE(...) ;
#endif

int a[300005];

int get(pair<int,int> x){return a[x.second]-a[x.first];}

struct node{
    node *l,*r;
    int mx,mn;
    pair<int,int> ans;
    node():l(0),r(0),ans({300004,0}),mx(0),mn(0){}
} *root;

#define mid ((l+r)>>1)
void pull(node *now){
    if(get(now->l->ans)>get(now->r->ans))now->ans=now->l->ans;
    else now->ans=now->r->ans;
    pair<int,int> tmp(now->l->mn,now->r->mx);
    if(get(tmp)>get(now->ans))now->ans=tmp;
    if(a[now->l->mx]>a[now->r->mx])now->mx=now->l->mx;
    else now->mx=now->r->mx;
    if(a[now->l->mn]>a[now->r->mn])now->mn=now->r->mn;
    else now->mn=now->l->mn;
}

void build(node *now,int l,int r){
    if(l==r){
        now->mx=now->mn=l;
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    pull(now);
}
void modify(node *now,int l,int r,int x){
    if(l==x && r==x){
        now->mx=0;
        now->mn=300004;
        return;
    }
    if(x<l || r<x)return;
    modify(now->l,l,mid,x);
    modify(now->r,mid+1,r,x);
    pull(now);
}

int main(){
    a[300004]=99999888;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root=new node(),1,n);
    long long ans=0;
    PDE(root->r->mx,root->l->l->mn,root->l->r->mn);
    while(get(root->ans)>0){
        auto bk=root->ans;
        PDE(bk);
        ans+=a[bk.second]-a[bk.first];
        modify(root,1,n,bk.first);
        modify(root,1,n,bk.second);
        PDE("mdfed");
    }
    cout<<ans<<endl;
}
