#include<cstdio>
#include<map>
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define getchar gtx
 
inline char gtx(){
    const int N=1048576;
    static char __buffer[N];
    static char *__p=__buffer,*__end=__buffer;
    if(__p==__end){
        if((__end=__buffer+fread_unlocked(__buffer,1,N,stdin))==__buffer)return EOF;
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
    static node mem[10000000],*ptr;
    node *l,*r;
    int cnt;
    node():l(0),r(0),cnt(0){}
    node(node *ref):l(ref->l),r(ref->r),cnt(ref->cnt){}
} *root[100005],node::mem[10000000],*node::ptr=node::mem,*rec;

#define m ((l+r)>>1)
void build(node *now,int l,int r){
    if(l==r)return;
    build(now->l=new (node::ptr++) node(),l,m);
    build(now->r=new (node::ptr++) node(),m+1,r);
}
void mdf(node *now,int l,int r,int x){
    if(l==x && x==r){++now->cnt; return;}
    if(x<=m)mdf(now->l=new (node::ptr++) node(now->l),l,m,x);
    else mdf(now->r=new (node::ptr++) node(now->r),m+1,r,x);
}
int qry(node *nowr,node *nowl,int l,int r,int x){
    if(l==x && x==r)return nowr->cnt-nowl->cnt;
    if(nowr==nowl)return 0;
    if(x<=m)return qry(nowr->l,nowl->l,l,m,x);
    else return qry(nowr->r,nowl->r,m+1,r,x);
}

int a[100005],p[100005],ch[100005];
int main(){
    int n,q; rit(n,q);
    build(root[0]=new (node::ptr++) node(),0,1048576);
    rec=node::ptr;
    for(int i=1;i<=n;++i)rit(a[i]),p[i]=p[i-1]^a[i],mdf(root[i]=new (node::ptr++) node(root[i-1]),0,1048576,p[i]);
    map<int,int> mmap;
    int c,i,z,mdfcnt=0;
    do{
        rit(c,i,z);
        if(c==1){
            mmap[i]=a[i]^z;
            ch[i]=z;
            ++mdfcnt;
            if(mdfcnt>=500){
                node::ptr=rec;
                for(int i=1;i<=n;++i)(ch[i]?a[i]=ch[i],ch[i]=0:0),p[i]=p[i-1]^a[i],mdf(root[i]=new (node::ptr++) node(root[i-1]),0,1048576,p[i]);
                mmap.clear();
                mdfcnt=0;
            }
        }
        else{
            int segstart=0,ans=0;
            for(auto it:mmap){
                if(it.first>i)break;
                ans+=qry(root[it.first-1],root[segstart],0,1048576,z);
                z^=it.second;
                segstart=it.first-1;
            }
            printf("%d\n",ans+qry(root[i],root[segstart],0,1048576,z));
        }
    }while(--q);
}
// TLE 350
// AC 465
