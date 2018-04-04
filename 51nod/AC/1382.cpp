#include<bits/stdc++.h>
using namespace std;
#define ll long long 


struct item{
    ll LR,Lr,lR,lr,mx,mn;
};

struct node{
    node *l,*r;
    item res;
    node():l(0),r(0){}
} *root;

int n;
ll a[100005];

item merge(item l,item r){
    item rt;
    rt.mx=max(l.mx,r.mx);
    rt.mn=min(l.mn,r.mn);
    rt.LR=rt.Lr=rt.lR=rt.lr=0;
    rt.LR=max({rt.LR,l.Lr+r.lR,l.LR+r.lR,l.Lr+r.LR});
    rt.Lr=max({rt.Lr,l.Lr+r.lr,l.LR+r.lr,l.Lr+r.Lr});
    rt.lR=max({rt.lR,l.lr+r.lR,l.lR+r.lR,l.lr+r.LR});
    rt.lr=max({rt.lr,l.lr+r.lr,l.lR+r.lr,l.lr+r.Lr});
    return rt;
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->res.LR=now->res.mx=now->res.mn=a[l];
        now->res.Lr=now->res.lR=now->res.lr=0;
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->res=merge(now->l->res,now->r->res);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        a[x]=v;
        now->res.LR=now->res.mx=now->res.mn=a[l];
        now->res.Lr=now->res.lR=now->res.lr=0;
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->res=merge(now->l->res,now->r->res);
}
item query(node *now,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr)return now->res;
    if(qr<=mid)return query(now->l,l,mid,ql,qr);
    else if(ql>mid)return query(now->r,mid+1,r,ql,qr);
    else return merge(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>n>>q;
    for(int i=0;i<n;++i)cin>>a[i];
    build(root=new node(),0,n-1);
    while(q--){
        int t; cin>>t;
        if(t==1){
            int id,nv; cin>>id>>nv;
            modify(root,0,n-1,id,nv);
        }
        else{
            int l,r; cin>>l>>r;
            auto rt=query(root,0,n-1,l,r);
            if(rt.mx<=0)cout<<rt.mx<<endl;
            else cout<<max({rt.mx,rt.LR,rt.Lr,rt.lR,rt.lr})<<endl;
        }
    }
}
