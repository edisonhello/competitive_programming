#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int val,pri,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=lz()+rz()+1;}
    node(int v=0):l(0),r(0),val(v),pri(rand()),sz(1){}
} *xt,*yt;

void split(node *now,int va,node *&a,node *&b){
    if(!now){a=b=0; return;}
    if(now->val>va){
        b=now;
        split(now->l,va,a,b->l);
        b->psz();
    }
    else{
        a=now;
        split(now->r,va,a->r,b);
        a->psz();
    }
}

node *merge(node *a,node *b){
    if(!(a&&b))return a?:b;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;++i){
        int a,b,c; cin>>a>>b>>c;
        if(a==2){
            int ans=0;
            node *zz,*xx;
            split(xt,b,zz,xx);
            if(zz)ans-=zz->sz;
            xt=merge(zz,xx);
            split(yt,c,zz,xx);
            if(xx)ans+=xx->sz;
            yt=merge(zz,xx);
            cout<<ans<<'\n';
        }
        else{
            node *zz,*xx;
            split(xt,b,zz,xx);
            xt=merge(zz,merge(new node(b),xx));
            split(yt,c,zz,xx);
            yt=merge(zz,merge(new node(c),xx));
        }
    }
}
