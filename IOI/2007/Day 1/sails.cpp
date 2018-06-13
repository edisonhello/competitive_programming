#include<bits/stdc++.h>
using namespace std;

pair<int,int> fan[100005];
int n;
int cnt[100005];
long long ans=0;

struct node{
    node *l,*r;
    int sz,pri;
    long long tag,val,tot;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void addtag(int d){ tag+=d; val+=d; tot+=1ll*d*sz; }
    void push(){ if(l)l->addtag(tag); if(r)r->addtag(tag); tag=0; }
    void pull(){ sz=lz()+rz()+1; tot=val+(l?l->tot:0ll)+(r?r->tot:0ll); }
    node(long long val=0):l(0),r(0),sz(1),pri(rand()),tag(0),val(val),tot(val){}
} *root;

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
    a->push(); b->push();
    if(a->pri>b->pri){
        a->r=merge(a->r,b);
        a->pull();
        return a;
    }
    else{
        b->l=merge(a,b->l);
        b->pull();
        return b;
    }
}
void split_sz(node *s,int sz,node *&a,node *&b){
    if(!s){ a=b=0; return; }
    s->push();
    if(s->lz()>=sz){
        b=s;
        split_sz(s->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=s;
        split_sz(s->r,sz-1-s->lz(),a->r,b);
        a->pull();
    }
}
void split_val(node *s,int val,node *&a,node *&b){
    if(!s){ a=b=0; return; }
    s->push();
    if(s->val<=val){
        a=s;
        split_val(s->r,val,a->r,b);
        a->pull();
    }
    else{
        b=s;
        split_val(s->l,val,a,b->l);
        b->pull();
    }
}

int getR(node *now){
    now->push();
    if(!now->r)return now->val;
    else return getR(now->r);
}
int getL(node *now){
    now->push();
    if(!now->l)return now->val;
    else return getL(now->l);
}

void print(node *now){
    if(!now)return;
    now->push();
    if(now->l)cout<<"(",print(now->l),cout<<")";
    cout<<now->val;
    if(now->r)cout<<"(",print(now->r),cout<<")";
}

int main(){
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    // n=10;
    for(int i=0;i<n;++i){
        cin>>fan[i].first>>fan[i].second;
        // fan[i].first=rand()%20+1;
        // fan[i].second=rand()%(fan[i].first+1);
    }
    sort(fan,fan+n);
    int slots_open=0;
    for(int i=0;i<n;++i){
        while(slots_open<fan[i].first)root=merge(new node(0),root),++slots_open;
        if(fan[i].second==0)continue;
        // cout<<fan[i].first<<" "<<fan[i].second<<endl;
        node *a,*b;
        split_sz(root,fan[i].second,a,b);
        ans+=a->tot;
        a->addtag(1);
        if(a && b){
            int rrr=getR(a);
            int lll=getL(b);
            // cout<<"rrr lll "<<rrr<<" "<<lll<<endl;
            if(rrr>lll){
                node *c,*d,*e,*f;
                split_val(a,rrr-1,c,d);
                split_val(b,lll,e,f);
                a=merge(c,e);
                b=merge(d,f);
            }
        }
        // print(a); cout<<" , "; print(b); cout<<endl;
        root=merge(a,b);
        // print(root); cout<<endl;
    }
    cout<<ans<<endl;
}
// after 25 pts
// after 40 pts
// after AC
