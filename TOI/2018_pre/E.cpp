// #pragma GCC optimize("no-stack-protector")
#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int val;
} *root;

int a[100005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){now->val=a[l]; return;}
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->val=min(now->l->val,now->r->val);
}
int query(node *now,int l,int r,int ql,int qr){
    // cout<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
    if(qr<l || r<ql)return 989898989;
    if(ql<=l && r<=qr)return now->val;
    return min(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i],++a[i];
    build(root=new node(),1,n);
    for(int i=0;i<n;++i){
        int a,b; cin>>a>>b;
        cout<<query(root,1,n,a,b)<<endl;
    }
}
