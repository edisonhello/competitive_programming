#include<cstdio>
using namespace std;
#define m ((l+r)>>1)

struct node{
    node *l,*r;
    long long val,tag;
    node():l(NULL),r(NULL),val(0),tag(0){};
    node(int v):l(NULL),r(NULL),val(v),tag(0){};
} *root;

int a[100005];


long long query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(now->tag && l!=r){
        now->l->tag+=now->tag;
        now->l->val+=now->tag*(m-l+1);
        now->r->tag+=now->tag;
        now->r->val+=now->tag*(r-m);
        now->tag=0;
    }
    if(ql<=l&&r<=qr)return now->val;
    return query(now->l,l,m,ql,qr)+query(now->r,m+1,r,ql,qr);
}
void modify(node *now,int l,int r,int ml,int mr,int k){
    if(mr<l || r<ml)return;
    if(now->tag && l!=r){
        now->l->tag+=now->tag;
        now->l->val+=now->tag*(m-l+1);
        now->r->tag+=now->tag;
        now->r->val+=now->tag*(r-m);
        now->tag=0;
    }
    if(ml<=l&&r<=mr){
        now->tag+=k;
        now->val+=k*(r-l+1);
        return;
    }
    modify(now->l,l,m,ml,mr,k);
    modify(now->r,m+1,r,ml,mr,k);
    now->val=now->l->val+now->r->val;
}
void build(node *now,int l,int r){
    if(l==r){
        now->val=a[l];
        return;
    }
    now->l=new node();now->r=new node();
    build(now->l,l,m),build(now->r,m+1,r);
    now->val=now->l->val+now->r->val;
}
void clr(node *now){
    if(!now)return;
    clr(now->l),clr(now->r);
    delete now;
}

int main(){
    int ts;scanf("%d",&ts);while(ts--){
        clr(root);
        int n,q,l,r,d,i;scanf("%d%d",&n,&q);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        root=new node();
        build(root,1,n);
        char com[8];
        while(q--){
            scanf("%s",com);
            if(com[0]=='a'){
                scanf("%d%d%d",&l,&r,&d);
                modify(root,1,n,l,r,d);
            }
            else{
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(root,1,n,l,r));
            }
        }
    }
}
