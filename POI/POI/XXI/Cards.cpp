#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[200005];

struct node{
    node *l,*r;
    vector<pair<int,int>> ans;
    node():l(0),r(0){}
} *root;

void pull(node *now){
    now->ans.clear();
    for(auto &i:now->l->ans){
        for(auto &j:now->r->ans){
            if(i.second<=j.first){
                now->ans.emplace_back(i.first,j.second);
                break;
            }
        }
    }
}

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->ans.emplace_back(a[l].first,a[l].first);
        now->ans.emplace_back(a[l].second,a[l].second);
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    pull(now);
}
void modify(node *now,int l,int r,int x){
    if(x<l || r<x)return;
    if(l==r){
        now->ans.clear();
        now->ans.emplace_back(a[l].first,a[l].first);
        now->ans.emplace_back(a[l].second,a[l].second);
        return;
    }
    modify(now->l,l,mid,x);
    modify(now->r,mid+1,r,x);
    pull(now);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        if(a[i].second<a[i].first)swap(a[i].first,a[i].second);
    }
    build(root=new node(),1,n);
    cin>>m;
    while(m--){
        int u,v; cin>>u>>v;
        swap(a[u],a[v]);
        modify(root,1,n,u);
        modify(root,1,n,v);
        cout<<(root->ans.size()?"TAK\n":"NIE\n");
    }
}
