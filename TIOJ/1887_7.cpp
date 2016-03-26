#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define mid (l+r)/2
#define X first
#define Y second
#define P pair<db,ull>
using namespace std;
const ull MOD=1e9+7;
inline ull rit(){
    ull t=0,k=1;char c;
    do{
        c=getchar();
    }while(c<'0'||c>'9');
    do{
        t=t*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return t*k;
}

vector<ull> x,y;

P operator + (const P &a,const P &b){
    return make_pair(a.X+b.X,a.Y*b.Y%MOD);
}

struct node{
    P s,v;
    node *l,*r;
    node(){
        l=r=NULL;
    }
};

void build(node *now,int l,int r){
    if(l==r){
        now->s=make_pair(log(x[l]),x[l]);
        now->v=make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
        return ;
    }
    now->l=new node();
    now->r=new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->s=now->l->s+now->r->s;
    now->v=max(now->l->v,now->l->s+now->r->v);
    return ;
}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){
        if(type==1){
            x[l]=val;
            now->s=make_pair(log(x[l]),x[l]);
            now->v=make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
            return ;
        }
        else{
            y[l]=val;
            now->v=make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
            return ;
        }
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }
    else{
        update(now->r,mid+1,r,pos,val,type);
    }

    now->s=now->l->s+now->r->s;
    now->v=max(now->l->v,now->l->s+now->r->v);
    return ;
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
}

int main(){
    int t=rit();
    while(t--){
        int n=rit();
        x.clear();
        x.resize(n);
        y.clear();
        y.resize(n);
        for(int i=0;i<n;i++)x[i]=rit();
        for(int i=0;i<n;i++)y[i]=rit();
        node *root = new node();
        build(root,0,n-1);
        printf("%llu\n",root->v.Y);
        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit();int p=rit();ull v=rit();
            update(root,0,n-1,p,v,k);
            printf("%llu\n",root->v.Y);
        }
        dlt(root);
    }
}
