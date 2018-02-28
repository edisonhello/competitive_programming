#pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;
#define ll long long


struct node{
    node *l,*r;
    ll val,tag;
    node():l(0),r(0),val(0),tag(0){}
    node(node *ref):l(ref->l),r(ref->r),val(ref->val),tag(ref->tag){}
} *root;

ll a[300005],pre[300005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}

void push(node *now,int l,int r){
    if(!now->tag)return;
    if(!now->l){now->tag=0; return;}
    now->l->val+=now->tag*(mid-l+1);
    now->l->tag+=now->tag;
    now->r->val+=now->tag*(r-mid);
    now->r->tag+=now->tag;
    now->tag=0;
    return;
}

void modify(node *now,int l,int r,int ml,int mr,int v){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->val+=1ll*(r-l+1)*v;
        now->tag+=v;
        return;
    }
    push(now,l,r);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->val=now->l->val+now->r->val;
}

ll query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return now->val;
    push(now,l,r);
    return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}   

struct M{
    int l,r,v;
};
struct Q{
    int l,r,x,t,i;
};
ll ans[300005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i],pre[i]=pre[i-1]+a[i];
    build(root=new node(),1,n);
    vector<M> ms;
    for(int i=1;i<=m;++i){
        int l,r,v; cin>>l>>r>>v;
        ms.push_back({l,r,v});
    }
    vector<Q> qs;
    int q; cin>>q; for(int i=0;i<q;++i){
        int l,r,L,R; cin>>l>>r>>L>>R;
        qs.push_back({l,r,R,1,i});
        if(L)qs.push_back({l,r,L-1,-1,i});
        ans[i]+=pre[r]-pre[l-1];
    }
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.x<b.x;});
    int mptr=0;
    for(Q q:qs){
        while(mptr<q.x){
            modify(root,1,n,ms[mptr].l,ms[mptr].r,ms[mptr].v);
            ++mptr;
        }
        ans[q.i]+=query(root,1,n,q.l,q.r)*q.t;
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
