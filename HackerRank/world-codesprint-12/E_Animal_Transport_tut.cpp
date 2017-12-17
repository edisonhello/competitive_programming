#include<bits/stdc++.h>
using namespace std;

struct anm{
    int l,r,t;
} a[50004];
int dp[2][50004];

struct segtree{
    #define val v
    struct node{
        node *l,*r;
        int v,tag,mxtag;
        node():l(0),r(0),v(0),tag(0),mxtag(0){}
    } *root;
    void clear(node *now){
        if(!now)return;
        clear(now->l); clear(now->r);
        delete now;
    }
    #define m ((l+r)>>1)
    void build(node *now,int l,int r){
        if(l==r)return;
        build(now->l=new node(),l,m);
        build(now->r=new node(),m+1,r);
    }
    void rebuild(int l,int r){
        clear(root);
        build(root=new node(),l,r);
    }
    void push(node *now){
        now->l->val+=now->tag;
        now->l->tag+=now->tag;
        now->l->mxtag+=now->tag;
        now->r->val+=now->tag;
        now->r->tag+=now->tag;
        now->r->mxtag+=now->tag;
        now->tag=0;
        now->l->mxtag=max(now->l->mxtag,now->mxtag);
        now->l->v=max(now->l->v,now->mxtag);
        now->r->mxtag=max(now->r->mxtag,now->mxtag);
        now->r->v=max(now->r->v,now->mxtag);
    }
    void modify(int l,int r,int ml,int mr,node *now){
        // cout<<"modify: "<<l<<" "<<r<<" "<<ml<<" "<<mr<<endl;
        if(ml<=l&&r<=mr){++now->tag, ++now->val, ++now->mxtag; return;}
        if(r<ml || mr<l)return;
        push(now);
        // cout<<"after push: tracking val is "<<root->l->l->r->val<<endl;
        modify(l,m,ml,mr,now->l);
        modify(m+1,r,ml,mr,now->r);
        // cout<<"back to "<<l<<" "<<r<<", "<<now->tag<<" "<<now->val<<" "<<now->mxtag<<endl;
    }
    void modifi(int l,int r,int ml,int mr,int v,node *now){
        if(ml<=l&&r<=mr){now->mxtag=max(now->mxtag,v); now->v=max(now->v,v); return;}
        if(r<ml || mr<l)return;
        push(now);
        modifi(l,m,ml,mr,v,now->l);
        modifi(m+1,r,ml,mr,v,now->r);
    }
    int query(int l,int r,int q,node *now){
        // cout<<"query "<<l<<" "<<r<<" "<<q<<endl;
        if(q<l || r<q)return 0;
        if(l==r)return now->v;
        // cout<<"before push: tracking val is "<<root->l->l->r->val<<endl;
        push(now);
        // cout<<"after push: tracking val is "<<root->l->l->r->val<<endl;
        return max(query(l,m,q,now->l),query(m+1,r,q,now->r));
    }
    void modify(int l,int r,int ml,int mr){modify(l,r,ml,mr,root);}
    void modifi(int l,int r,int ml,int mr,int v){modifi(l,r,ml,mr,v,root);}
    int query(int l,int r,int q){return query(l,r,q,root);}
    #undef m
    #undef val
    segtree():root(0){}
} seg[2];

void solll(int m,int n){
    sort(a,a+n,[](const anm &a,const anm &b){return a.l<b.l;});
    memset(dp,0,sizeof(dp));
    seg[0].rebuild(1,m); seg[1].rebuild(1,m);
    // cout<<"rebuilded"<<endl;
    for(int i=0;i<n;++i){
        // cout<<"animal "<<a[i].l<<" "<<a[i].r<<" "<<a[i].t<<endl;
        if(a[i].l>a[i].r)continue;
        seg[a[i].t].modify(1,m,a[i].r,m);
        seg[a[i].t].modifi(1,m,a[i].r,m,seg[!a[i].t].query(1,m,a[i].l)+1);
    }
    int ptr=0,vvv=0;
    for(int i=1;i<=n;++i){
        while(ptr<m && vvv<i){
            ++ptr;
            vvv=max(vvv,max(seg[0].query(1,m,ptr),seg[1].query(1,m,ptr)));
        }
        if(vvv>=i)cout<<ptr<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t; while(t--){
        int m,n; cin>>m>>n;
        for(int i=0;i<n;++i){
            char c; cin>>c;
            if(c=='E' || c=='C')a[i].t=0;
            else a[i].t=1;
        }
        for(int i=0;i<n;++i)cin>>a[i].l;
        for(int i=0;i<n;++i)cin>>a[i].r;
        solll(m,n);
    }
}
