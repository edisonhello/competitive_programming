#include<bits/stdc++.h>
using namespace std;

struct node{
    node *l,*r;
    int pri,val,tag,sz;
    int lz(){return l?l->sz:0;}
    int rz(){return r?r->sz:0;}
    void psz(){sz=lz()+rz()+1;}
    node(int va=0):l(0),r(0),pri(rand()),val(va),tag(0),sz(1){}
} *root;

void push(node *now){
    if(!now)return;
    if(!now->tag)return;
    if(now->l){
        now->l->val+=now->tag;
        now->l->tag+=now->tag;
    }
    if(now->r){
        now->r->val+=now->tag;
        now->r->tag+=now->tag;
    }
    now->tag=0;
}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    push(a); push(b);
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->psz();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->psz();
        return b;
    }
}
void split_sz(node *now,int sz,node *&a,node *&b){
    if(!now){a=b=0; return;}
    push(now);
    if(now->lz()>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        b->psz();
    }
    else{
        a=now;
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->psz();
    }
}
void split_val(node *now,int val,node *&a,node *&b){
    if(!now){a=b=0; return;}
    push(now);
    if(now->val>=val){
        a=now;
        split_val(now->r,val,a->r,b);
        a->psz();
    }
    else{
        b=now;
        split_val(now->l,val,a,b->l);
        b->psz();
    }
}

int getl(node *now){
    if(!now)return 7122;
    push(now);
    if(now->l)return getl(now->l);
    return now->val;
}
int getr(node *now){
    if(!now)return 7122;
    push(now);
    if(now->r)return getr(now->r);
    return now->val;
}

void ptree(node *now){
    if(!now)return;
    if(now->l)cout<<"(",ptree(now->l),cout<<")";
    cout<<"["<<now->val<<","<<now->tag<<"]";
    if(now->r)cout<<"(",ptree(now->r),cout<<")";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ts; cin>>ts; while(ts--){
        root=0;
        int n,m; cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;++i)cin>>a[i];
        sort(a.begin(),a.end()); reverse(a.begin(),a.end());
        for(int i=0;i<n;++i)root=merge(root,new node(a[i]));
        vector<int> b(m);
        for(int i=0;i<m;++i)cin>>b[i];
        for(int i:b){
            if(i==0)continue;
            node *a,*b;
            split_sz(root,i,a,b);
            a->tag+=-1;
            a->val+=-1;
            // cout<<"a: "; ptree(a); cout<<" , b: "; ptree(b); cout<<endl;
            int lr=getr(a);
            int rl=getl(b);
            if(a && b && lr<rl){
                node *c,*d,*e,*f;
                split_val(a,lr+1,c,d);
                split_val(b,rl,e,f);
                root=merge(merge(c,e),merge(d,f));
            }
            else root=merge(a,b);
            // ptree(root); cout<<endl;
        }
        int r=getr(root);
        int l=getl(root);
        // cout<<"last lr "<<l<<" "<<r<<endl;
        if(l || r)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
}
