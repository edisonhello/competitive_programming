#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int a[100005];

struct oper{
    ld pro,add;
    oper(int x):pro(1),add(0){}
    oper(ld pro=1,ld add=0):pro(pro),add(add){}
    oper& operator+=(oper &a){
        this->pro=this->pro*a.pro;
        this->add=this->add*a.pro+a.add;
        return *this;
    }
    oper operator=(int x){
        if(!x)this->pro=0,this->add=0;
    }
};

struct node{
    node *l,*r;
    ld val;
    oper ope;
    node():l(0),r(0),val(0),ope(0){}
} *root;
#define m ((l+r)>>1)
void addop(node *now,oper &op,int wid){
    now->val=now->val*op.pro+op.add*wid;
    now->ope+=op;
}
void push(node *now,int l,int r){
    if(now->ope.pro!=1.0 || now->ope.add!=0.0){
        addop(now->l,now->ope,m-l+1);
        addop(now->r,now->ope,r-m);
        now->ope.pro=1.0;
        now->ope.add=0.0;
    }
}
void pull(node *now){
    now->val=now->l->val+now->r->val;
}
void build(node *now,int l,int r){
    if(l==r){now->val=a[l]; return;}
    build(now->l=new node(),l,m);
    build(now->r=new node(),m+1,r);
    pull(now);
}
void modify(node *now,int l,int r,int ml,int mr,oper op){
   if(mr<l||r<ml)return;
   if(ml<=l&&r<=mr)return addop(now,op,r-l+1),void();
   push(now,l,r);
   modify(now->l,l,m,ml,mr,op);
   modify(now->r,m+1,r,ml,mr,op);
   pull(now);
}
ld query(node *now,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr)return now->val;
    push(now,l,r);
    return query(now->l,l,m,ql,qr)+query(now->r,m+1,r,ql,qr);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    build(root=new node(),1,n);
    while(q--){
        int type; cin>>type;
        if(type==1){
            int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
            ld lsum=query(root,1,n,l1,r1),rsum=query(root,1,n,l2,r2);
            modify(root,1,n,l1,r1,oper(1.*(r1-l1)/(r1-l1+1),rsum/(r2-l2+1)/(r1-l1+1)));
            modify(root,1,n,l2,r2,oper(1.*(r2-l2)/(r2-l2+1),lsum/(r1-l1+1)/(r2-l2+1)));
        }
        else{
            int l,r; cin>>l>>r;
            cout<<fixed<<setprecision(40)<<query(root,1,n,l,r)<<endl;
        }
    }
}
