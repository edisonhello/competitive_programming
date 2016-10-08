#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define db double
/*struct val{
    ull v,s;
    db lv,ls;
    val(){
        v=s=0;
        lv=ls=0;
    }
    void update(){
        lv=log((db)v);
        ls=log((db)s);
        return;
    }
};*/
const ull MOD = 1e9+7;
/*val operator + (const val &a,const val &b){
    val t;
    t.s=a.s*b.s%MOD;
    t.ls=a.ls+b.ls;
    bool which; //ans=max(lc->ans,lc->sum+rc->ans);
    if(abs((a.lv) - (a.ls+a.lv+b.lv))<1e-9){
        if(a.v > a.s*b.v){
            which = 0;
        }
        else{
            which = 1;
        }
    }
    else{
        if(a.lv > a.ls+b.lv){
            which = 0;
        }
        else{
            which =1;
        }
    }
    if(which==0){
        t.v = a.v*b.v;
        t.lv= a.lv+b.lv;
    }
    else{
        t.v = a.s*b.v%MOD;
        t.lv= a.ls+b.lv;
    }
    return t;
}*/
#define mid (l+r)/2
struct node{
    pair<db,ull> v,s;
    node *l,*r;
    node(){
        l = r = NULL;
    }
};

pair<db,ull> operator + (const pair<db,ull> a,const pair<db,ull> &b){
    /*pair<db,ull> t;
    t.first = a.first + b.first;
    t.second= a.second*b.second%MOD;
    return t;*/
    return make_pair(a.first + b.first , a.second*b.second%MOD);
}

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

/*void pull(node *now){
    now->v.s = now->l->v.s * now->r->v.s % MOD;
    now->v.ls= now->l->v.ls+ now->r->v.ls;
    if(now->l->v.lv > now->r->v.lv + now->l->v.ls){ ///1e-9
        now->v.lv = now->l->v.lv;
        now->v.v  = now->l->v.v ;
    }
    else{
        now->v.lv = now->r->v.lv + now->l->v.ls;
        now->v.v  = now->r->v.v  * now->l->v.s %MOD;
    }
    return;
}*/

void build(node *now,int l,int r){
    if(l==r){
        now->v.second = (x[l]*y[l])%MOD;
        now->s.second = x[l];
        now->v.first  = log(x[l]*y[l]);
        now->s.first  = log(now->s.second);
        return;
    }
    now->l = new node();
    now->r = new node();
    build(now->l,l,mid);
    build(now->r,mid+1,r);

    now->s = now->l->s + now->r->s;
    now->v = max(now->l->v,now->l->s+now->r->v);
    //pull(now);

}

void update(node *now,int l,int r,int pos,ull val,int type){
    if(l==r){
        assert(l==pos);
        if(type==1){
            x[l] = val;
            now->v.second = (x[l]*y[l])%MOD;
            now->s.second = x[l];
            now->v.first  = log(x[l]*y[l]);
            now->s.first  = log(now->s.second);
            return;
        }
        else{
            y[l] = val;
            now->v.second = (x[l]*y[l])%MOD;
            now->v.first  = log(x[l]*y[l]);
            return ;
        }
    }       //cout<<"jizz";
    if(pos>mid){
        update(now->r,mid+1,r,pos,val,type);
    }
    if(pos<=mid){
        update(now->l,l,mid,pos,val,type);
    }

    now->s = now->l->s + now->r->s;
    now->v = max(now->l->v,now->l->s+now->r->v);
    //pull(now);
}

void dlt(node *now){
    if(now->l)dlt(now->l);
    if(now->r)dlt(now->r);
    delete now;
}

int main(){
    int t=rit();
    while(t--){//cout<<"jizz"<<endl;
        node *root;
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
        printf("%llu\n",root->v.second);
        int m=rit();
        for(int i=0;i<m;i++){
            int k=rit(),p=rit();ull v=rit();
            update(root,0,n-1,p,v,k);
            printf("%llu\n",root->v.second);
        }
        dlt(root);
    }

}
