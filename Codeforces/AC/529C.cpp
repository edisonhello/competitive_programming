#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int val;
    node():l(0),r(0),val(0){}
} *root;

struct Q{
    int i,l,r,u,d;
};


bitset<200006> ans;
vector<pair<int,int>> cr;
vector<Q> qs;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int x,int v){
    if(l==r){
        now->val=max(now->val,v);
        return;
    }
    if(x<=mid)modify(now->l,l,mid,x,v);
    else modify(now->r,mid+1,r,x,v);
    now->val=min(now->l->val,now->r->val);
}
int query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 1<<30;
    if(ql<=l&&r<=qr)return now->val;
    return min(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

void solve(int n,int m){
    build(root=new node(),1,m);
    int ptr=0;
    for(auto i:qs){
        while(ptr<cr.size() && cr[ptr].first<=i.r){
            // cout<<"add car "<<cr[ptr].first<<" "<<cr[ptr].second<<endl;
            modify(root,1,m,cr[ptr].second,cr[ptr].first);
            ++ptr;
        }
        // cout<<"q: "<<i.l<<" "<<i.r<<" "<<i.u<<" "<<i.d<<endl;
        // cout<<"q res: "<<query(root,1,m,i.u,i.d)<<endl;
        if(!ans[i.i])ans[i.i]=(query(root,1,m,i.u,i.d)>=i.l);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,q; cin>>n>>m>>k>>q;
    for(int i=0;i<k;++i){
        int x,y; cin>>x>>y;
        cr.emplace_back(x,y);
    }
    for(int i=0;i<q;++i){
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        qs.push_back({i,x1,x2,y1,y2});
    }
    sort(cr.begin(),cr.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first<b.first;});
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.r<b.r;});
    solve(n,m);
    for(auto &i:cr)swap(i.first,i.second);
    for(auto &i:qs)swap(i.l,i.u),swap(i.r,i.d);
    sort(cr.begin(),cr.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.first<b.first;});
    sort(qs.begin(),qs.end(),[](const Q &a,const Q &b){return a.r<b.r;});
    solve(m,n);
    for(int i=0;i<q;++i){
        if(ans[i])cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
