#include<bits/stdc++.h>
using namespace std;

#include<ext/rope>
using namespace __gnu_cxx;

#define lowbit(x) ((x)&(-(x)))

int lpt[100009],ptr;
struct want{int l,r,g;} p[100009];
struct node{
    node *l,*r;
    int val;
    node(int _val=0):l(NULL),r(NULL),val(_val){};
    node(node *now):l(now->l),r(now->r),val(now->val){};
} *root[100009],pool[2000009];

#define mid ((l+r)>>1)
node* copy(node *&now){
    pool[ptr].l=now->l;
    pool[ptr].r=now->r;
    pool[ptr].val=now->val;
    return &pool[ptr++];
}
void build(node *&now,int l,int r){
    if(l==r)return;
    build(now->l=&pool[ptr++],l,mid);
    build(now->r=&pool[ptr++],mid+1,r);
}
void modify(node *&now,int l,int r,int &pos,int &val){
    if(l==pos && r==pos)now->val+=val;
    else{
        if(pos<=mid)modify(now->l=copy(now->l),l,mid,pos,val);
        else modify(now->r=copy(now->r),mid+1,r,pos,val);
        now->val=now->l->val+now->r->val;
    }
}
int query(node *&now,int l,int r,int pos){
    if(l>pos || r<pos)return 0;
    if(l==pos && r==pos)return now->val;
    if(pos>mid)return now->l->val+query(now->r,mid+1,r,pos);
    return query(now->l,l,mid,pos);
}
#undef mid

int main(){
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    build(root[0]=&pool[ptr++],1,n);
    for(int i=0;i<m;++i)scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].g);
    for(int i=1;i<=q;++i){
        int p,v;scanf("%d%d",&p,&v);
        lpt[p]+=v;
        modify(root[i]=copy(root[i-1]),1,n,p,v);
    }
    for(int i=1;i<=n;++i)lpt[i]+=lpt[i-1];
    for(int i=0;i<m;++i){
        if(lpt[p[i].r]-lpt[p[i].l-1]<p[i].g)puts("-1");
        else{
            int L=1,R=q;
            while(R>L){
                if(query(root[(L+R)>>1],1,n,p[i].r)-query(root[(L+R)>>1],1,n,p[i].l-1)<p[i].g)L=((L+R)>>1)+1;
                else R=(L+R)>>1;
            }
            printf("%d\n",L);
        }
    }
}
