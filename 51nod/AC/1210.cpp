#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    long long val,tag;
    node():l(0),r(0),val(0),tag(0){}
} *root[222];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        cin>>now->val;
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->val=now->l->val+now->r->val;
}

void push(node *now,int l,int r){
    now->l->tag+=now->tag;
    now->r->tag+=now->tag;
    now->l->val+=now->tag*(mid-l+1);
    now->r->val+=now->tag*(r-mid);
    now->tag=0;
}

long long query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    if(ql<=l&&r<=qr)return now->val;
    if(now->tag)push(now,l,r);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

void modify(node *now,int l,int r,int ml,int mr,int v){
    // cout<<"mdf "<<l<<" "<<r<<" "<<ml<<" "<<mr<<" "<<v<<endl;
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->tag+=v;
        now->val+=1ll*v*(r-l+1);
        // cout<<"now now val: "<<now->val<<endl;
        return;
    }
    if(now->tag)push(now,l,r);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->val=now->l->val+now->r->val;
}

void print(node *now,int l,int r){
    // cout<<now<<" "<<l<<" "<<r<<endl;
    if(l==r){
        cout<<now->val<<" ";
        return;
    }
    if(now->tag)push(now,l,r);
    print(now->l,l,mid);
    print(now->r,mid+1,r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,n,q; cin>>m>>n>>q; swap(n,m);
    for(int i=1;i<=n;++i)build(root[i]=new node(),1,m);
    while(q--){
        int x1,y1,x2,y2,a; long long z,tot=0;
        cin>>x1>>y1>>x2>>y2>>z>>a; swap(x1,y1); swap(x2,y2);
        for(int i=x1;i<=x2;++i){
            tot+=query(root[i],1,m,y1,y2);
        }
        // if(a==1640)cout<<"tot: "<<tot<<endl;
        if(tot<z*(x2-x1+1)*(y2-y1+1)){
            for(int i=x1;i<=x2;++i){
                modify(root[i],1,m,y1,y2,a);
            }
        }
    }
    for(int i=1;i<=n;++i)print(root[i],1,m),cout<<'\n';
}
