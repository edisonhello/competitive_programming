#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    vector<int> base;
    node():l(0),r(0){}
} *root;

int a[300005],bit[300005];

#define lb(x) ((x)&-(x))

void add(int x,int v){
    for(;x<300005;x+=lb(x))bit[x]^=v;
}
int query(int x,int v=0){
    for(;x;x-=lb(x))v^=bit[x];
    return v;
}

vector<int> merge(vector<int> a,vector<int> b){
    // cout<<"merge [ ";
    // for(int i:a)cout<<i<<", "; cout<<"] and [ ";
    // for(int i:b)cout<<i<<", "; cout<<"] get [ ";

    vector<int> rt=a;
    for(int i:b){
        for(int j:rt)i=min(i,i^j);
        if(i)rt.push_back(i);
    }
    // for(int i:rt)cout<<i<<", "; cout<<"] "<<endl;
    return rt;
}
void pull(node *now){
    now->base=merge(now->l->base,now->r->base);
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        // cout<<"at "<<l<<" val is "<<(a[l]^a[l+1])<<endl;
        if(a[l]^a[l+1])now->base.push_back(a[l]^a[l+1]);
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    // cout<<"call for merge for "<<l<<" "<<r<<endl;
    pull(now);
    // for(int i:now->base)cout<<i<<" "; cout<<endl;
}

void modify(node *now,int l,int r,int x,int val){
    if(l==r){
        if(now->base.size())now->base[0]^=val;
		else now->base.push_back(val);
        if(now->base[0]==0)now->base.pop_back();
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,val);
    else modify(now->r,mid+1,r,x,val);
    pull(now);
}

vector<int> query(node *now,int l,int r,int ql,int qr){
    // cout<<"query "<<l<<" "<<r<<" "<<ql<<" "<<qr<<endl;
    if(r<ql || qr<l)return vector<int>();
    if(ql<=l&&r<=qr)return now->base;
    return merge(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n+1;++i)add(i,a[i]^a[i-1]);

    if(n>1)build(root=new node(),0,n);
    else{
        while(q--){
            int t; cin>>t;
            if(t==1){int k; cin>>k>>k>>k; a[1]^=k;}
            else{int k; cin>>k>>k; cout<<(a[1]?2:1)<<endl;}
        }
        return 0;
    }

    while(q--){
        int t; cin>>t;
        if(t==1){
            int l,r,k; cin>>l>>r>>k;
            modify(root,0,n,l-1,k);
            modify(root,0,n,r,k);
            add(l,k);
            add(r+1,k);
        }
        else{
            int l,r; cin>>l>>r;
            if(l==r){cout<<(query(l)?2:1)<<'\n'; continue;}
            auto rt=query(root,0,n,l,r-1);
            // for(int i:rt)cout<<i<<" "; cout<<endl;
            int head=query(l);
            // cout<<"head: "<<head<<endl;
            for(int i:rt)head=min(head,head^i);
            // cout<<"head: "<<head<<endl;
            cout<<(1<<(rt.size()+(!!head)))<<endl;
        }
    }
}
