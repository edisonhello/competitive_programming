/* tutorial by waynetu */

#include<bits/stdc++.h>
using namespace std;

pair<int,int> get(pair<int,int> a,pair<int,int> b){
    if(a.second==0)return b;
    if(b.second==0)return a;
    if(a.first==b.first)return {a.first,a.second+b.second};
    if(a.second>b.second)return {a.first,a.second-b.second};
    if(a.second<b.second)return {b.first,b.second-a.second};
    return {a.first,0};
}

struct node{
    node *l,*r;
    pair<int,int> val;
    node():l(0),r(0){val={0,0};}
    void pull(){
        val=get(l->val,r->val);
    }
} *root;

int a[500005];

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){now->val={a[l],1}; return;}
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->pull();
}

pair<int,int> query(node *now,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return {0,0};
    if(ql<=l&&r<=qr)return now->val;
    return get(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

vector<int> pos[500005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    build(root=new node(),1,n);
    // cout<<"meow: "<<root->l->r->val.first<<" "<<root->l->r->val.second<<endl;
    while(m--){
        int l,r; cin>>l>>r;
        pair<int,int> ans=query(root,1,n,l,r);
        // cout<<"ans: "<<ans.first<<" "<<ans.second<<endl;
        cout<<((upper_bound(pos[ans.first].begin(),pos[ans.first].end(),r)-lower_bound(pos[ans.first].begin(),pos[ans.first].end(),l)>(r-l+1)/2)?ans.first:0)<<'\n';
    }
}
