// #include"teams.h"
#include<bits/stdc++.h>
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,tune=native")
using namespace std;

int root[500005],node[500005*50][3],ptr;

inline int gn(int ref=-1){
    ++ptr;
    if(~ref)memcpy(node[ptr],node[ref],3<<2);
    else memset(node[ptr],0,3<<2);
    return ptr;
}


int n;
pair<int,int> p[500005];

#define mid ((l+r)>>1)
void build(int now,int l,int r){
    if(l==r)return;
    build(node[now][0]=gn(),l,mid);
    build(node[now][1]=gn(),mid+1,r);
}

void modify(int now,int l,int r,int x){
    ++node[now][2];
    if(l==r){ return; }
    if(x<=mid)modify(node[now][0]=gn(node[now][0]),l,mid,x);
    else modify(node[now][1]=gn(node[now][1]),mid+1,r,x);
}

int query(int nl,int nr,int l,int r,int ql,int qr){
    if(r<ql || qr<l)return 0;
    // cout<<"query range "<<l<<" to "<<r<<" cur v: "<<nl->v<<" and "<<nr->v<<endl;
    if(ql<=l&&r<=qr)return node[nr][2]-node[nl][2];
    return query(node[nl][0],node[nr][0],l,mid,ql,qr)+query(node[nl][1],node[nr][1],mid+1,r,ql,qr);
}

void init(int _n,int _a[],int _b[]){
    n=_n;
    for(int i=0;i<n;++i)p[i+1]={_a[i],_b[i]};
    sort(p+1,p+n+1);
    build(root[0]=gn(),1,n);
    int ptr=1;
    for(int i=1;i<=n;++i){
        root[i]=gn(root[i-1]);
        while(ptr<=n && p[ptr].first<=i)modify(root[i]=gn(root[i]),1,n,p[ptr].second),++ptr;
    }
}

namespace naive{
struct node{
    node *l,*r;
    int sz,pri,val;
    int lz(){ return l?l->sz:0; }
    int rz(){ return r?r->sz:0; }
    void pull(){ sz=lz()+rz()+1; }
    node(int v=0):l(0),r(0),sz(1),pri(rand()),val(v){}
} *root,pool[500005];

int _ptr;
node *gnode(int v){
    pool[_ptr].l=0;
    pool[_ptr].r=0;
    pool[_ptr].sz=1;
    pool[_ptr].val=v;
    return &pool[_ptr++];
}

node *merge(node *a,node *b){
    if(!a)return b; if(!b)return a;
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

void split_val(node *now,int val,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->val<=val){
        a=now;
        split_val(now->r,val,a->r,b);
        a->pull();
    }
    else{
        b=now;
        split_val(now->l,val,a,b->l);
        b->pull();
    }
}

void split_sz(node *now,int sz,node *&a,node *&b){
    if(!now){ a=b=0; return; }
    if(now->lz()>=sz){
        b=now;
        split_sz(now->l,sz,a,b->l);
        b->pull();
    }
    else{
        a=now;
        split_sz(now->r,sz-1-now->lz(),a->r,b);
        a->pull();
    }
}

int solve(int m,int k[]){
    _ptr=0;
    int ptr=1;
    for(int i=0;i<m;++i){
        while(ptr<=n && p[ptr].first<=k[i]){
            node *a,*b;
            split_val(root,p[ptr].second,a,b);
            root=merge(merge(a,gnode(p[ptr].second)),b);
            ++ptr;
        }
        node *a,*b;
        split_val(root,k[i]-1,a,b);
        if(!b || b->sz<k[i]){
            root=0;
            return 0;
        }
        node *c,*d;
        split_sz(b,k[i],c,d);
        root=d;
    }
    root=0;
    return 1;
}

}

#define BOUND 385
int dp[BOUND+4];
int can(int m,int k[]){
    sort(k,k+m);
    // return naive::solve(m,k);
    if(m>BOUND)return naive::solve(m,k);
    else{
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<m;++i){
            int mn=9897788;
            for(int j=0;j<=i;++j){
                if(j==0)mn=query(root[0],root[k[i]],1,n,k[i],n);
                else mn=min(mn,dp[j-1]+query(root[k[j-1]],root[k[i]],1,n,k[i],n));
                // cout<<"j: "<<j<<" , mn: "<<mn<<endl;
            }
            dp[i]=mn-k[i];
            // cout<<"at "<<i<<" , dp: "<<dp[i]<<endl;
            if(dp[i]<0)return 0;
        }
        return 1;
    }
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int l[500005],r[500005],a[500005];
int main(){
    int ts; rit(ts); while(ts--){
        ptr=0;
        int n; rit(n);
        for(int i=0;i<n;++i)rit(l[i],r[i]);
        init(n,l,r);
        int m; rit(m); while(m--){
            int k; rit(k);
            for(int i=0;i<k;++i)rit(a[i]);
            pit(can(k,a));
        }
    }
}
