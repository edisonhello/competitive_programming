#include<bits/stdc++.h>
using namespace std;


struct node{
    node *l,*r,*pa;
    int pri,sz,mn,val;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    int lv(){return l?l->mn:1<<30;}
    int rv(){return r?r->mn:1<<30;}
    void psz(){sz=lz()+rz()+1;}
    void pmn(){mn=min(val,min(lv(),rv()));}
    node(int va=0):l(0),r(0),pa(0),pri(rand()),sz(1),mn(va),val(va){}
} *root;

int a[100005];
int p[100005];
node *rec[100005];

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        if(a->r)a->r->pa=a;
        a->psz();
        a->pmn();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        if(b->l)b->l->pa=b;
        b->psz();
        b->pmn();
        return b;
    }
}
void split(node *s,int sz,node *&a,node *&b){
    if(!s){a=b=0; return;}
    if(s->lz()>=sz){
        b=s;
        split(s->l,sz,a,b->l);
        if(b->l)b->l->pa=b;
        b->psz();
        b->pmn();
        return;
    }
    else{
        a=s;
        split(a->r,sz-1-s->lz(),a->r,b);
        if(a->r)a->r->pa=a;
        a->psz();
        a->pmn();
        return;
    }
}
int gpos(node *now){
    if(!now)exit(5487);
    if(now->val<now->lv() && now->val<=now->rv())return now->lz();
    if(now->lv()<=now->val && now->lv()<=now->rv())return gpos(now->l);
    return now->lz()+1+gpos(now->r);
}

void ptree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<now->mn;
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

int main(){
    srand(time(0));
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i)rec[i]=new node(a[i]);
    for(int i=1;i<=n;++i)root=merge(root,rec[i]);
    long long ans=0;
    for(int i=1;i<=n;++i){
        // ptree(root); cout<<"  ";
        int pos=gpos(root)+1;
        node *aa,*b,*c,*d;
        split(root,pos-1,aa,d);
        split(d,1,b,c);
        ans+=pos;
        root=merge(c,aa);
        // cout<<i<<" "<<pos<<endl;
    }
    cout<<ans<<endl;
}
