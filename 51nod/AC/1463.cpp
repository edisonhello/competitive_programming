#include<bits/stdc++.h>
using namespace std;

struct Q{
    int l,r,i;
} qs[100005];

struct node{
    node *l,*r;
    int mx;
    node(int v=0):l(0),r(0),mx(v){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->mx=max(now->mx,v);
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->mx=max(now->l->mx,now->r->mx);
}
int query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return now->mx;
    return max(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int a[100005],b[100005],bpos[100005],ans[100005];

int main(){
    int n,q,m; cin>>n>>q>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)cin>>b[i],bpos[b[i]]=i;
    set<int> k;
    for(int i=1,t;i<=m;++i)cin>>t,k.insert(t);
    for(int i=0;i<q;++i){
        int l,r; cin>>l>>r;
        qs[i]={l,r,i};
    }
    auto add=[&](int ix){
        for(int i:k){
            int v=b[ix]-i;
            if(v>0 && bpos[v]<ix)modify(root,1,n,bpos[v],a[bpos[v]]+a[ix]);
            v=b[ix]+i;
            if(v<=n && bpos[v]<ix)modify(root,1,n,bpos[v],a[bpos[v]]+a[ix]);
        }
    };
    sort(qs,qs+q,[](const Q &a,const Q &b){return a.r<b.r;});
    int R=0;
    build(root=new node(),1,n);
    for(int i=0;i<q;++i){
        Q &q=qs[i];
        while(R<q.r)add(++R);
        ans[q.i]=query(root,1,n,q.l,q.r);
    }
    for(int i=0;i<q;++i)cout<<ans[i]<<'\n';
}
