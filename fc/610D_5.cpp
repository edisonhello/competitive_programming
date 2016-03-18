#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

const ll BIG=1000000000;
const ll SML=-1000000000;

#define midx x1+x2<0 ? (x1+x2-1)/2 : (x1+x2)/2
#define midy y1+y2<0 ? (y1+y2-1)/2 : (y1+y2)/2


inline ll rit(){
    ll t=0,key=1;char c;
    do{
        c=getchar();
        if(c=='-')key=-1;
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }
    while(c>='0'&&c<='9');
    return t*key;
}

struct _node{
    _node *_l,*_r;
    ll val;
    _node(){
        _l=_r=NULL;
        val=0;
    }
};

struct node{
    node *l,*r;
    _node *_rt;
    ll val;
    node(){
        l=r=NULL;
        _rt=NULL;
        val=0;
    }
} *root;


void _pnt(_node *now,ll y1,ll y2,ll fy1,ll fy2,ll wid){
        /*g*/printf("pnt d2 %I64d %I64d (%I64d %I64d) by %I64d\n",y1,y2,fy1,fy2,wid);
    if(y2<fy1||fy2<y1){
            /*g*/printf("    d2 out\n");
        return;
    }
    if(fy1<=y1&&y2<=fy2){

        now->val=wid*(y2-y1+1);
            /*g*/printf("    d2 in,val %I64d\n",now->val);
        return;
    }
    if(now->val == wid*(y2-y1+1)){
        return;
    }
    if(fy1<=midy){
        if(now->_l==NULL)now->_l = new _node();
        _pnt(now->_l,y1,midy,fy1,fy2,wid);
    }
    if(midy<fy2){
        if(now->_r==NULL)now->_r = new _node();
        _pnt(now->_r,midy+1,y2,fy1,fy2,wid);
    }
    ll tmp=0;
    if(now->_l!=NULL)tmp+=now->_l->val;
    if(now->_r!=NULL)tmp+=now->_r->val;
    now->val=tmp;
}

void pnt(node *now,ll x1,ll x2,ll fx1,ll fx2,ll fy1,ll fy2){
        /*g*/printf("pnt d1 %I64d %I64d (%I64d %I64d %I64d %I64d)\n",x1,x2,fx1,fx2,fy1,fy2);
    if(x2<fx1||fx2<x1){
        return;
    }
    if(now->_rt==NULL)now->_rt = new _node();
    _pnt(now->_rt,SML,BIG,fy1,fy2,(fx2-fx1+1));
    if(fx1<=x1&&x2<=fx2){
        now->val=now->_rt->val;
        return;
    }
    if(now->val==(x2-x1+1)*(BIG-SML)){
        return;
    }
    if(fx1<=midx){
        if(now->l==NULL)now->l = new node();
        pnt(now->l,x1,midx,fx1,fx2,fy1,fy2);
    }
    if(midx<fx2){
        if(now->r==NULL)now->r = new node();
        pnt(now->r,midx+1,x2,fx1,fx2,fy1,fy2);
    }
    ll tmp=0;
    if(now->l!=NULL)tmp+=now->l->val;
    if(now->r!=NULL)tmp+=now->r->val;
    now->val=tmp;
}

int main(){
    ll n=rit();
    root = new node();
    for(int i=0;i<n;i++){
        ll x1=rit(),y1=rit(),x2=rit(),y2=rit();
        if(x1>x2){ll t=x1;x1=x2;x2=t;}
        if(y1>y2){ll t=y1;y1=y2;y2=t;}
        pnt(root,SML,BIG,x1,x2,y1,y2);
        /*g*/printf("now val %d\n",root->val);
    }
    printf("%I64d\n",root->val);
}
