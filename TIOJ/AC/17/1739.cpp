#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include"lib1739.h"
using namespace std;

struct node{
    int l,r,v;
    node():l(0),r(0),v(0){}
} pool[300005*40];
int zzz=0,bead[300005],pos[300005];

int gnode(int ref=0){
    // cout<<"gnode ref: "<<ref<<endl;
    if(!ref)return ++zzz;
    ++zzz;
    // cout<<rt<<" come from "<<ref<<endl;
    pool[zzz]=pool[ref];
    return zzz;
}

#define mid ((l+r)>>1)
void build(int now,int l,int r){
    // cout<<"build: "<<now<<" "<<l<<" "<<r<<endl;
    if(l==r){pool[now].v=l; return;}
    build(pool[now].l=gnode(),l,mid);
    build(pool[now].r=gnode(),mid+1,r);
}
void modify(int now,int l,int r,int x,int v){
    // cout<<"modify "<<now<<" "<<l<<" "<<r<<" "<<x<<" "<<v<<endl;
    if(l==r){pool[now].v=v; return;}
    if(x<=mid)modify(pool[now].l=gnode(pool[now].l),l,mid,x,v);
    else modify(pool[now].r=gnode(pool[now].r),mid+1,r,x,v);
}
int query(int now,int l,int r,int x){
    // cout<<"query "<<now<<" "<<l<<" "<<r<<" "<<x<<endl;
    if(l==r)return pool[now].v;
    if(x<=mid)return query(pool[now].l,l,mid,x);
    else return query(pool[now].r,mid+1,r,x);
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m; scanf("%d%d",&n,&m);
    build(pos[0]=gnode(),1,n);
    for(int i=1;i<=n;++i)bead[i]=i;
    for(int i=1,p1,p2,n1,n2;i<=m;++i){
        scanf("%d",&p1); p2=p1+1;
        n1=bead[p1],n2=bead[p2];
        pos[i]=gnode(pos[i-1]);
        modify(pos[i],1,n,n1,p2);
        modify(pos[i],1,n,n2,p1);
        swap(bead[p1],bead[p2]);
        // cout<<"pos: "; for(int j=1;j<=n;++j)cout<<query(pos[i],1,n,j)<<" "; cout<<endl;
        // cout<<"bed: "; for(int j=1;j<=n;++j)cout<<bead[j]<<" "; cout<<endl;
    }
    int q=getNumQuestions(); while(q--){
        int a,b; getQuestion(a,b);
        answer(query(pos[b],1,n,a));
    }
}
