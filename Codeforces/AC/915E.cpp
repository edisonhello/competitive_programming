#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int tag,val;
    node(int tag=0,int val=0):l(0),r(0),tag(tag),val(val){}
} *root,pool[15000000];
int ptr=-1;

#define mid ((l+r)>>1)

inline void push(node *now,int l,int r){
    if(l==r){
        now->tag=0;
        return;
    }
    if(now->tag==1){
        if(!now->l){
            now->l=&pool[++ptr];
            now->l->tag=1;
        }
        now->l->tag=1;
        now->l->val=0;
        if(!now->r){
            now->r=&pool[++ptr];
            now->r->tag=1;
        }
        now->r->tag=1;
        now->r->val=0;
    }
    else if(now->tag==2){
        if(now->l){
            now->l->tag=2;
            now->l->val=mid-l+1;
        }
        if(now->r){
            now->r->tag=2;
            now->r->val=r-mid;
        }
    }
    now->tag=0;
}
inline void pull(node *now,int l,int r){
    now->val=0;
    if(now->l)now->val+=now->l->val;
    else now->val+=mid-l+1;
    if(now->r)now->val+=now->r->val;
    else now->val+=r-mid;
}

void modify(node *&now,int l,int r,int ml,int mr,int k){
    if(r<ml || mr<l)return;
    if(!now)now=&pool[++ptr];
    if(ml<=l&&r<=mr){
        if(k==1)now->tag=1,now->val=0;
        else now->tag=2,now->val=r-l+1;
        return;
    }
    push(now,l,r);
    if(ml<=mid)modify(now->l,l,mid,ml,mr,k);
    if(mr>mid)modify(now->r,mid+1,r,ml,mr,k);
    pull(now,l,r);
}

int main(){
    int n,q; scanf("%d%d",&n,&q);
    while(q--){
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        modify(root,1,n,l,r,k);
        printf("%d\n",root->val);
    }
}
