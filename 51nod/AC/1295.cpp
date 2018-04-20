#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int a[65536],ans;

struct node{
    node *ch[2];
    int gsz(int id){return ch[id]?ch[id]->sz:0;}
    int sz;
    node():sz(0){memset(ch,0,sizeof(ch));}
} *root[65536];

node *gnode(node *ref=0){
    if(!ref)return new node();
    node *rt=new node();
    rt->ch[0]=ref->ch[0];
    rt->ch[1]=ref->ch[1];
    rt->sz=ref->sz;
    return rt;
}

void add(node *&now,int x,int ptr){
    // cout<<"add "<<now<<" "<<x<<" "<<ptr<<endl;
    if(!now)now=new node();
    ++now->sz;
    if(ptr<0)return;
    add(now->ch[!!(x&(1<<ptr))]=gnode(now->ch[!!(x&(1<<ptr))]),x,ptr-1);
}

int gsz(node *q,int i){
    if(!q)return 0;
    return q->gsz(i);
}

void query(node *lnow,node *rnow,int x,int ptr){
    if(ptr<0 || lnow==rnow)return;
    // cout<<"query "<<lnow<<" "<<rnow<<" "<<x<<" "<<ptr<<endl;
    // if(lnow)cout<<"lnow size: "<<lnow->sz<<endl;
    // if(rnow)cout<<"rnow size: "<<rnow->sz<<endl;
    // cout<<"now answer is "<<ans<<endl;
    int go=!(x&(1<<ptr));
    // cout<<"want to go "<<go<<endl;
    // cout<<"r l sz: "<<gsz(rnow,go)<<" "<<gsz(lnow,go)<<endl;
    if(gsz(rnow,go)-gsz(lnow,go)){
        ans^=(go<<ptr);
        query(lnow?lnow->ch[go]:0,rnow?rnow->ch[go]:0,x,ptr-1);
    }
    else{
        ans^=((!go)<<ptr);
        query(lnow?lnow->ch[!go]:0,rnow?rnow->ch[!go]:0,x,ptr-1);
    }
}


int main(){
    int n,q; scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)add(root[i]=gnode(root[i-1]),a[i],30);
    do{
        int l,r,x; scanf("%d%d%d",&x,&l,&r); ++l,++r;
        ans=x;
        query(root[l-1],root[r],x,30);
        printf("%d\n",ans);
    }while(--q);
}
