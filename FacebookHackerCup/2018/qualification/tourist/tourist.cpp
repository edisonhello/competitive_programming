#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int pri,sz,i;
    string s;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
    node(string s="",int i=0):l(0),r(0),pri(rand()),sz(1),i(i),s(s){}
} *root;

void split(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->lz()>=sz){
        b=now;
        split(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split(now->r,sz-now->lz()-1,a->r,b);
        a->pull();
    }
}
node *merge(node *a,node *b){
    if(!b)return a; if(!a)return b;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void tourist(node *now,vector<pair<int,string>> &ans){
    if(!now)return;
    ans.emplace_back(now->i,now->s);
    tourist(now->l,ans);
    tourist(now->r,ans);
}

int main(){
    int t,ks=0; cin>>t; while(t--){
        long long n,k,v; cin>>n>>k>>v; --v;
        v%=n; ++v;
        root=0;
        for(int i=0;i<n;++i){
            string s; cin>>s;
            root=merge(root,new node(s,i));
        }
        for(int i=1;i<v;++i){
            node *a,*b;
            split(root,k,a,b);
            root=merge(b,a);
        }
        node *a,*b;
        split(root,k,a,b);
        vector<pair<int,string>> ans;
        tourist(a,ans);
        sort(ans.begin(),ans.end());
        cout<<"Case #"<<(++ks)<<":";
        for(auto i:ans)cout<<" "<<i.second;
        cout<<endl;
    }
}
