// zj b416
struct node{
    node *l,*r; int v;
    node():l(NULL),r(NULL),v(0){};
    node(int val):l(NULL),r(NULL),v(val){};
} *root[100009],pool[100009*20]; // pool use for speed up
int uuuuu;

#define m ((l+r)>>1)
void buildInit(node *now,int l,int r){
    if(l==r)return;
    buildInit(now->l=&pool[uuuuu++],l,m);
    buildInit(now->r=&pool[uuuuu++],m+1,r);
}
node *copy(node *base){
    node *nw=&pool[uuuuu++];
    nw->l=base->l, nw->r=base->r;
    nw->v=base->v;
    return nw;
}
void build(node *now,int l,int r,int v){
    PDE4(now,l,r,v);
    if(l==r){
        now->v+=1;
        return;
    }
    if(v<=m)build(now->l=copy(now->l),l,m,v);
    else build(now->r=copy(now->r),m+1,r,v);
    now->v=now->l->v+now->r->v;
}
int query(node *now,int l,int r,int ql,int qr){
    PDE4(l,r,ql,qr);
    if(l>qr || ql>r)return 0;
    if(ql<=l&&r<=qr)return now->v;
    return query(now->l,l,m,ql,qr)+query(now->r,m+1,r,ql,qr);
}
#undef m

int main(){
    int n,m;rit(n,m);
    buildInit(root[0]=&pool[uuuuu++],1,n);
    for(int i=1,t;i<=n;++i){
        rit(t);
        build(root[i]=copy(root[i-1]),1,n,t);
    }
    PDE1(root[9]->l->l->l->v);
    while(m--){
        int l,r,a,b;rit(l,r,a,b);
        pit(query(root[r],1,n,a,b)-query(root[l-1],1,n,a,b)),el;
    }
}
