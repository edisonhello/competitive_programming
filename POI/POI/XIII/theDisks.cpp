#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int v;
    node(int v=0):l(0),r(0),v(v){};
} *root;

int a[300005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->v=a[l];
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->v=min(now->l->v,now->r->v);
}

void modify(node *now,int l,int r,int v){
    if(l==r){
        now->v=0;
        return;
    }
    if(v<=mid)modify(now->l,l,mid,v);
    else modify(now->r,mid+1,r,v);
    now->v=min(now->l->v,now->r->v);
}

int query(node *now,int l,int r,int v){
    if(l==r)return l;
    if(now->l->v<v)return query(now->l,l,mid,v);
    else return query(now->r,mid+1,r,v);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root=new node(),1,n);
    int ans;
    while(m--){
        int w; cin>>w;
        ans=query(root,1,n,w)-1;
        if(ans)modify(root,1,n,ans);
    }
    cout<<ans<<endl;
}
// AC
