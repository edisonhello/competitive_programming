#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Q{
    int l,r,i;
} qs[300005];

struct meow{
    ll sum,lps,rps,ap;
    void set(ll x){sum=lps=rps=ap=x;}
    meow():sum(0),lps(0),rps(0),ap(0){}
};

struct node{
    node *l,*r;
    meow ans;
    node():l(0),r(0){}
} *root;

int m;

int a[300005],ans[300005],pre[300005];

meow operator+(const meow &a,const meow &b){
    meow rt;
    rt.lps=(a.lps+a.ap*b.lps)%m;
    rt.rps=(b.rps+b.ap*a.rps)%m;
    rt.ap=a.ap*b.ap%m;
    rt.sum=(a.sum+b.sum+a.rps*b.lps)%m;
    return rt;
}

void pull(node *now){
    now->ans=now->l->ans+now->r->ans;
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->ans.set(a[l]);
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    pull(now);
}

void modify(node *now,int l,int r,int ml,int mr,int v){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        return;
    }
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    pull(now);
}

meow query(node *now,int l,int r,int ql,int qr){
    if(ql<=l&&r<=qr)return now->ans;
    if(qr<=mid)return query(now->l,l,mid,ql,qr);
    else if(mid<ql)return query(now->r,mid+1,r,ql,qr);
    else return query(now->l,l,mid,ql,qr)+query(now->r,mid+1,r,ql,qr);
}

void ptree(node *now,int l,int r){
    if(!now)return;
    cout<<"range "<<l<<" "<<r<<" sum: "<<now->ans.sum<<" , ap: "<<now->ans.ap<<" , lps: "<<now->ans.lps<<" , rps: "<<now->ans.rps<<endl;
    ptree(now->l,l,mid);
    ptree(now->r,mid+1,r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root=new node(),1,n);
    // ptree(root,1,n);
    for(int i=0;i<q;++i){
        int l,r; cin>>l>>r;
        cout<<query(root,1,n,l,r).sum<<'\n';
    }
}
