#include<bits/stdc++.h>
using namespace std;

struct E{
    int l,r,x,w;
};
vector<E> es;

struct node{
    node *l,*r;
    int mx,tag;
    node():l(0),r(0),mx(0),tag(0){}
} *root;

#define mid ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new node(),l,mid);
    build(now->r=new node(),mid+1,r);
}
void modify(node *now,int l,int r,int ml,int mr,int x){
    if(r<ml || mr<l)return;
    if(ml<=l&&r<=mr){
        now->mx+=x;
        now->tag+=x;
        return;
    }
    if(now->tag){
        now->l->tag+=now->tag;
        now->l->mx+=now->tag;
        now->r->tag+=now->tag;
        now->r->mx+=now->tag;
        now->tag=0;
    }
    modify(now->l,l,mid,ml,mr,x);
    modify(now->r,mid+1,r,ml,mr,x);
    now->mx=max(now->l->mx,now->r->mx);
}

int main(){
    int n; cin>>n;
    vector<int> xs,ys;
    for(int i=0;i<n;++i){
        int x1,y1,x2,y2,w; cin>>x1>>y1>>x2>>y2>>w;
        if(!w)continue;
        xs.push_back(x1); xs.push_back(x2);
        ys.push_back(y1); ys.push_back(y2);
        es.push_back({y1,y2,x1,w});
        es.push_back({y1,y2,x2+1,-w});
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    build(root=new node(),0,ys.size());
    for(auto &e:es){
        e.x=lower_bound(xs.begin(),xs.end(),e.x)-xs.begin();
        e.l=lower_bound(ys.begin(),ys.end(),e.l)-ys.begin();
        e.r=lower_bound(ys.begin(),ys.end(),e.r)-ys.begin();
        if(e.w>0)modify(root,0,ys.size(),e.l,e.r,e.w);
    }
    sort(es.begin(),es.end(),[](const E &a,const E &b){return a.x<b.x;});
    int mx=root->mx,in=0;
    for(int i=0;i<es.size();++i){
        modify(root,0,ys.size(),es[i].l,es[i].r,-es[i].w);
        in+=es[i].w;
        if(i!=es.size()-1 && es[i+1].x==es[i].x)continue;
        mx=max(mx,in+root->mx);
    }
    cout<<mx<<endl;
}
