#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define left mmeeooww

struct res{
    ll cost,rest,left;
    res():cost(0),rest(0),left(0){}
};

struct node{
    node *l,*r;
    res ans;
    node():l(0),r(0){}
} *root;

ll x[200005],z[200005];

#define mid ((l+r)>>1)
res _query(node *now,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr)return now->ans;
    res rt1=_query(now->l,l,mid,ql,qr);

}

res pull(res a,res b,int l,int rmid,int rlim,node *now){
    res rt;
    rt.cost=a.cost;
    rt.left=a.left;
    rt.rest=max(a.rest,b.rest);
    while(rt.rest>=x[rmid] && rmid<=rlim){
        ++rmid;
        rt.rest=max(rt.rest,x[rmid]+z[rmid]);
    }
    if(rmid>rlim)return rt;
    rt.cost+=x[rmid]-rt.rest;
    res rtt=_query(now,l,rlim,rmid,rlim);
    rt.rest=rtt.rest;
    rt.cost+=rtt.cost;
    return rt;
}

void build(node *now,int l,int r){
    if(l==r){
        now->ans.rest=x[l]+z[l];
        now->ans.left=x[l];
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->ans=pull(now->l->ans,now->r->ans,l,mid+1,r,now);
}
res query(node *now,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr)return now->ans;
    if(qr<=mid)return query(now->l,l,mid,ql,qr);
    if(ql>mid)return query(now->r,mid+1,r,ql,qr);
    return pull(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>z[i];
    }
    build(root=new node(),1,n);
    int q; cin>>q; while(q--){
        int u,v; cin>>u>>v;
        cout<<query(root,1,n,u,v).cost<<endl;
    }
}
