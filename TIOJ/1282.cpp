#include<iostream>
#include<algorithm>
#include<assert.h>
#define m (l+r)/2
#define ll long long
using namespace std;

struct node{
    node *l,*r;
    ll v,tag;
    node():l(NULL),r(NULL),v(0){}
} *root;

int n,q;
ll a[100005],b[100005],p[100005];

void build(node *now,int l,int r){
    if(l==r){
        now->v=b[l];
        return;
    }
    now->l=new node();
    now->r=new node();
    build(now->l,l,m);
    build(now->r,m+1,r);
    now->v=__gcd(now->l->v,now->r->v);
}

void updateSingle(node *now,int l,int r,int up,ll k){
    if(up<l || up>r)return;
    if(l==up&&up==r){
        now->v+=k;
        return;
    }
    updateSingle(now->l,l,m,up,k);
    updateSingle(now->r,m+1,r,up,k);
    now->v=__gcd(now->l->v,now->r->v);
}
void updateSegm(node *now,int l,int r,int ul,int ur,ll k){
    if(ur<l || r<ul)return;
    if(ul<=l&&r<=ur){
        now->tag+=k;
        return;
    }
    if(now->tag){
        now->l->tag+=now->tag;
        now->r->tag+=(m-l+1)*now->tag;
        now->tag=0;
    }
    updateSegm(now->l,l,m,ul,ur,k);
    updateSegm(now->r,m+1,r,ul,ur,k);
}

ll querySegm(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr){
        return now->v;
    }
    ll lc=querySegm(now->l,l,m,ql,qr);
    ll rc=querySegm(now->r,m+1,r,ql,qr);
    if(lc&&rc)return __gcd(lc,rc);
    if(lc)return lc;
    if(rc)return rc;
    return 0;
}
ll querySingle(node *now,int l,int r,int qp){
    if(l==qp&&qp==r){
        p[l]+=now->tag;
        now->tag=0;
        return now->v;
    }
    if(now->tag){
        now->l->tag+=now->tag;
        now->r->tag+=(m-l+1)*now->tag;
        now->tag=0;
    }
    if(qp>m)return querySingle(now->r,m+1,r,qp);
    else return querySingle(now->l,l,m,qp);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        b[i]=a[i]-a[i-1];
        p[i]=p[i-1]+a[i];
    }
    root=new node();
    build(root,1,n);

    for(int i=0,c;i<q;++i){
        cin>>c;
        if(c==1){
            int l,r;ll k;
            cin>>l>>r>>k;
            updateSingle(root,1,n,l,k);
            updateSingle(root,1,n,r+1,-k);
            updateSegm(root,1,n,l+1,n,k); //?
        }
        else{
            int l,r;
            cin>>l>>r;
            if(l==r)cout<<a[l]<<endl;
            else{
                ll seg=querySegm(root,1,n,l+1,r);
                ll pnt=querySingle(root,1,n,l);
                if(seg==0ll)cout<<pnt<<endl;
                else cout<<__gcd(seg,pnt+p[l])<<endl;
            }
        }
    }
}
