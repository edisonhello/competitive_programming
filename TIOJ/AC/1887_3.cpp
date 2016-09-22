#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define db double
const ull MOD = 1e9+7;
struct val{
    ull v,s;
    db lv,ls;
    val(){
        v=s=0;
        lv=ls=0;
    }
    void update(){
        lv=log(v);
        ls=log(s);
        v %= MOD;
        return;
    }
};
val operator + (const val &a,const val &b){
    val t;
    t.s=a.s*b.s%MOD;
    t.ls=a.ls+b.ls;
    if(a.lv>b.lv+a.ls){
        t.v=a.v;
        t.lv=a.lv;
    }
    else{
        t.v=b.v*a.s%MOD;
        t.lv=b.lv+a.ls;
    }
    return t;
}
#define mid (l+r)/2
struct node{
    val v;
    node *l,*r;
    node(){
        l = r = NULL;
    }
} *root;

vector<ull> x,y;

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

void pull(node *now){
    now->v = now->l->v + now->r->v;//printf("%d\n",now->v.v);
}

void build(node *now,int l,int r){
    if(l==r){
        now->v.v = x[l]*y[l];
        now->v.s = x[l];
        now->v.update();
        return;
    }
    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);
    pull(now);
}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){       //cout<<"jizz"<<endl;
        assert(l==pos);
        if(type==1){
            x[l] = val;
            now->v.v = x[l]*y[l];
            now->v.s = x[l];
            now->v.update();
        }
        else{
            y[l] = val;
            now->v.v = val;
            now->v.v = x[l]*y[l];
            now->v.update();
        }
        return;
    }       //cout<<"jizz";
    if(pos>mid){
        update(now->r,mid+1,r,pos,val,type);
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }
    pull(now);
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
}


int main(){
    int t=rit();
    while(t--){//cout<<"jizz"<<endl;
        int n=rit();
        x.clear();y.clear();
        x.resize(n);y.resize(n);
        for(int i=0;i<n;i++){
            x[i]=rit();
        }
        for(int j=0;j<n;j++){
            y[j]=rit();
        }
        root = new node();
        build(root,0,n-1);
        printf("%llu\n",root->v.v/* * root->v.*/);
        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit(),p=rit();ull v=rit();
            update(root,0,n-1,p,v,k);
            printf("%llu\n",root->v.v);
        }
    }

}
