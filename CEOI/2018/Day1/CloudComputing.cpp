#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    node *l,*r;
    int cores,sz,pri;
    ll prize,psum;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    ll lp(){ return l?l->psum:0; }
    ll rp(){ return r?r->psum:0; }
    void pull(){ sz=lz()+rz()+cores; psum=lp()+rp()+prize; }
    node(int p,int c):l(0),r(0),cores(c),sz(c),pri(rand()),prize(p),psum(p){}
} *root;
// sort by prize

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
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
void split_sz(node *&now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(a->sz>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        a->pull();
    }
    else{
        a=now;
        split_sz(now->r,sz-now->lz()-now->cores,a->r,b);
        b->pull();
    }
}
void split_prz(node *&now,int pp,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->prize<=pp){
        a=now;
        split_prz(now->r,pp,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split_prz(now->l,pp,a,b->l);
        b->pull();
    }
}

struct item{
    int c,f,v; 
    int type; // 0 for computer, 1 for order
};

ll dp[2005][20005];
vector<item> machine,order;

int main(){
    int n,m; cin>>n>>m;
    vector<item> v;
    for(int i=0;i<n;++i){
        int c,f,p; cin>>c>>f>>p;
        machine.push_back({c,f,p});
        v.push_back({c,f,p,0});
    }
    for(int i=0;i<m;++i){
        int c,f,p; cin>>c>>f>>p;
        order.push_back({c,f,p});
        v.push_back({c,f,p,1});
    }
    /* sort(machine.begin(),machine.end(),[](const item &a,const item &b){ return a.f<b.f; });
    sort(order.begin(),order.end(),[](const item &a,const item &b){ return a.f>b.f; });
    memset(dp,0xb0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=m;++i){
        for(int j=0;j<=2000*50;++j){
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
        }
        for(int j=order[i-1].c
    } */

    sort(v.begin(),v.end(),[](const item &a,const item &b){ return a.f==b.f?(a.type==b.type?a.v>b.v:a.type<b.type):a.f>b.f; });
    ll earn=0;
    for(item p:v){
        if(p.type==0){
            node *a,*b;
            split_prz(root,p.v,a,b);
            root=merge(merge(a,new node(p.v,p.c)),b);
        }
        else{
            node *a,*b;
            split_sz(root,p.c,a,b);
            ll cost=1e18;
            if(a)cost=a->psum;
            if(cost<p.v){
                earn+=
            }
        }
    }
    cout<<earn<<endl; */
}

