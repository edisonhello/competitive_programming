#include<bits/stdc++.h>
#define mid (l+r)/2
#define ull unsigned long long
#define db double
#define P pair<db,ull>
#define M(x,y) make_pair(x,y)
#define X first
#define Y second
using namespace std;
const ull MOD = 1e9+7;

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

struct node{
    P s,v;
    node *l,*r;
    node(){
        l=r=NULL;
    }
};
vector<ull> x,y;

P operator + (const P &a,const P &b){
    return M(a.X+b.X,a.Y*b.Y%MOD);
}

void build(node *now,int l,int r){
    if(l==r){
        now->s=M(log(x[l]),x[l]);
        now->v=M(log(x[l]*y[l]),x[l]*y[l]%MOD);
        return ;
    }
    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->v = max(now->l->v,now->l->s+now->r->v);
    now->s = now->l->s + now->r->s;
}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){
        assert(l==pos);
        if(type==1){
            x[pos]=val;
            now->s=M(log(x[l]),x[l]);  //jizz
            now->v=M(log(x[l]*y[l]),x[l]*y[l]%MOD);
            return ;
        }
        if(type==2){
            y[pos]=val;
            now->v=M(log(x[l]*y[l]),x[l]*y[l]%MOD); //jizz
            return ;
        }
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }
    else{
        update(now->r,mid+1,r,pos,val,type);
    }

    now->v = max(now->l->v,now->l->s+now->r->v);
    now->s = now->l->s + now->r->s;
    return ;
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
    return ;
}

int main(){
    int t=rit();
    while(t--){
        node *root = new node();
        int n=rit();
        x.clear();
        y.clear();
        x.resize(n);
        y.resize(n);
        for(int i=0;i<n;i++){
            x[i]=rit();
        }
        for(int i=0;i<n;i++){
            y[i]=rit();
        }

        build(root,0,n-1);

        printf("%llu\n",root->v.Y);

        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit(),p=rit();ull v=rit();
            update(root,0,n-1,p,v,k);
            printf("%llu\n",root->v.Y);
        }

        dlt(root);
    }
}
