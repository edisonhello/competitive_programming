#pragma GCC optimize("no-stack-protector")
#include<cstdio>
#include<algorithm>
using namespace std;

#define getchar gtx
// #define fread fread_unlocked
inline char gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread(__buffer,1,N,stdin))==__buffer)return EOF;
        __p=__buffer;
    } return *__p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=getchar(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct node{
    node *l,*r;
    int v,tag;
    node():l(0),r(0),v(0),tag(0){};
} *root[1005],pool[4000005];

int ptr=-1;
#define mid ((l+r)>>1)

void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=&pool[++ptr],l,mid);
    build(now->r=&pool[++ptr],mid+1,r);
}

void push(node *now){
    if(now->tag){
        now->l->tag=max(now->l->tag,now->tag);
        now->r->tag=max(now->r->tag,now->tag);
        now->l->v=max(now->l->v,now->tag);
        now->r->v=max(now->r->v,now->tag);
        now->tag=0;
    }
}

void modify(node *now,int l,int r,int ml,int mr,int v){
    if(mr<l || r<ml)return;
    if(ml<=l&&r<=mr){
        now->v=now->tag=v;
        return;
    }
    push(now);
    modify(now->l,l,mid,ml,mr,v);
    modify(now->r,mid+1,r,ml,mr,v);
    now->v=max(now->l->v,now->r->v);
}

int query(node *now,int l,int r,int ql,int qr){
    if(qr<l || r<ql)return 0;
    if(ql<=l&&r<=qr)return now->v;
    push(now);
    return max(query(now->l,l,mid,ql,qr),query(now->r,mid+1,r,ql,qr));
}

int main(){
    int x,y,n; rit(x,y,n);
    for(int i=0;i<x;++i)build(root[i]=&pool[++ptr],0,y-1);
    while(n--){
        int d,s,w,xl,yl; rit(d,s,w,xl,yl);
        int xr=xl+d-1,yr=yl+s-1;
        int mx=0;
        for(int i=xl;i<=xr;++i)mx=max(mx,query(root[i],0,y-1,yl,yr));
        mx+=w;
        for(int i=xl;i<=xr;++i)modify(root[i],0,y-1,yl,yr,mx);
    }
    int mx=0;
    for(int i=0;i<x;++i)mx=max(mx,root[i]->v);
    printf("%d\n",mx);
}
