#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define db double
#define X first
#define Y second
#define mid (l+r)/2

using namespace std;

const ull MOD = 1e9+7;

struct node{
    node *l,*r;
    pair<db,ull> v,s;
    node(){
        l=r=NULL;
    }
};

pair<db,ull> operator + (const pair<db,ull> &a,const pair<db,ull> &b){
    return make_pair(a.X+b.X,a.Y*b.Y%MOD);
}

vector<ull> x,y;

void build(node *now,int l,int r){
    if(l==r){
        now->s = make_pair(log(x[l]),x[l]);
        now->v = make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
        return;
    }
    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->v = max(now->l->v,now->l->s+now->r->v);
    now->s = now->l->s+now->r->s;
}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){
        assert(l==pos);
        if(type==1){
            x[l] = val;
            now->s = make_pair(log(x[l]),x[l]);
            now->v = make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
        }
        else{
            y[l] = val;
            now->v = make_pair(log(x[l]*y[l]),x[l]*y[l]%MOD);
        }
        return;
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }
    else{
        update(now->r,mid+1,r,pos,val,type);
    }

    now->v = max(now->l->v,now->l->s+now->r->v);
    now->s = now->l->s+now->r->s;
    return ;
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
    return ;
}

int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        x.clear();
        y.clear();
        x.resize(n);
        y.resize(n);
        for(int i=0;i<n;i++){
            scanf("%llu",&x[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%llu",&y[i]);
        }
        node *root = new node();
        build(root,0,n-1);
        printf("%llu\n",root->v.Y);//jizz

        int m;scanf("%d",&m);
        for(int i=0;i<m;i++){
            int k,p;ull v;
            scanf("%d%d%llu",&k,&p,&v);
            update(root,0,n-1,p,v,k);
            printf("%llu\n",root->v.Y);//jizz
        }        

        dlt(root);
    }
}
