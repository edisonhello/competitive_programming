#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#define fread fread_unlocked
#define fwrite fwrite_unlocked
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
    char buffer[4112], *ptr=buffer, *end=buffer+4096;
    inline void writebyte(char c) {
        *ptr = c; ++ptr;
        if (ptr > end) fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
    }
    template <typename T> inline void writeint(T x, char endc='\n'){
        if(x<0)*ptr = '-', ++ptr, x=-x; if(!x)*ptr='0', ++ptr;
        char *s=ptr, c; T t;
        while(x){ t=x/10; c=x-10*t+'0'; *ptr=c, ++ptr, x=t; }
        char *f=ptr-1; while(s<f)swap(*s,*f), ++s, --f;
        if(ptr>end)fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
        *ptr=endc, ++ptr;
    }

    template<typename T>
    inline void output(T x){ writeint(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ writeint(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int a[200005],v[200005<<2];

#define mid ((l+r)>>1)
#define lc ((o<<1))
#define rc ((o<<1)|1)
void build(int o,int l,int r){
    if(l==r)v[o]=a[l];
    else{
        build(lc,l,mid);
        build(rc,mid+1,r);
        v[o]=max(v[lc],v[rc]);
    }
}

void add(int o,int l,int r,int x,int i){
    if(l==r){
        v[o]+=i;
        return;
    }
    if(x<=mid)add(lc,l,mid,x,i);
    else add(rc,mid+1,r,x,i);
    v[o]=max(v[lc],v[rc]);
}

void modify(int o,int l,int r,int ml,int mr,int x){
    if(v[o]<x)return;
    if(r<ml || mr<l)return;
    if(l==r){
        v[o]%=x;
        return;
    }
    if(ml<=mid)modify(lc,l,mid,ml,mr,x);
    if(mr>mid)modify(rc,mid+1,r,ml,mr,x);
    v[o]=max(v[lc],v[rc]);
}

int main(){
    int n; rit(n);
    for(int i=0;i<n;++i)rit(a[i]);
    build(1,0,n-1);
    int m; rit(m); while(m--){
        int k; rit(k);
        if(k==1){
            int x,i; rit(x,i);
            add(1,0,n-1,i,x);
        }
        else if(k==2){
            int l,r,v; rit(l,r,v);
            modify(1,0,n-1,l,r,v);
        }
        else{
            pit(v[1]);
        }
    }
}
