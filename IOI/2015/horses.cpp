#include"horses.h"
#include<bits/stdc++.h>
using namespace std;

const int mod=1000000007;

#define data pair<long double,int>
#define X first
#define Y second

data operator+(const data &a,const data &b){ return data(a.X+b.X,1ll*a.Y*b.Y%mod); }

struct node{
    node *l,*r;
    // data v,tag,mx;
    data v,tag;
    void addtag(data z){ v=v+z; tag=tag+z; }
    void push(){ l->addtag(tag); r->addtag(tag); tag=data(0,1); }
    void pull(){ v=max(l->v,r->v); }
    node():l(0),r(0),v(0,1),tag(0,1){}
} *root;

int n,*x,*y;

int pw(int b,int n,int m,int a=1){
    if(!n)return a;
    if(n&1)return pw(1ll*b*b%m,n>>1,m,1ll*a*b%m);
    else return pw(1ll*b*b%m,n>>1,m,a);
}
int inv(int x){ return pw(x,mod-2,mod); }

data make(int v){ return data(log(v),v); }
data makei(int v){ return data(-log(v),inv(v)); }

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r){
        now->v=make(y[l]);
        return;
    }
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
    now->pull();
}
void modify(node *now,int l,int r,int ml,int mr,data v){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->addtag(v);
        return;
    }
    now->push();
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->pull();
}

int init(int _n,int _x[],int _y[]){ 
    n=_n; x=_x; y=_y;
    build(root=new node(),0,n-1);
    // cout<<"init: "<<root->v.Y<<endl;
    data pre(0,1);
    for(int i=0;i<n;++i)pre=pre+make(x[i]),modify(root,0,n-1,i,i,pre);
    return root->v.Y;
}
int updateX(int pos,int val){
    modify(root,0,n-1,pos,n-1,makei(x[pos]));
    x[pos]=val;
    modify(root,0,n-1,pos,n-1,make(x[pos]));
    return root->v.Y;
}
int updateY(int pos,int val){
    modify(root,0,n-1,pos,pos,makei(y[pos]));
    y[pos]=val;
    modify(root,0,n-1,pos,pos,make(y[pos]));
    return root->v.Y;
}

#ifdef WEAK
int _x[500005],_y[500005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i)cin>>_x[i];
    for(int i=0;i<n;++i)cin>>_y[i];
    cout<<init(n,_x,_y)<<endl;
    int q; cin>>q; while(q--){
        int t,p,v; cin>>t>>p>>v;
        if(t==1)cout<<updateX(p,v)<<endl;
        else cout<<updateY(p,v)<<endl;
    }
}
#endif
