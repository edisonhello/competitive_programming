#pragma GCC optimize("no-stack-protector,O2")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define getchar gtx
#define fread fread_unlocked
#define fwrite fwrite_unlocked
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

struct outputter{
    char _buffer[1048576],*_ptr=_buffer,*_end=_buffer+1048576;
    template<typename T>
    inline void write(T x){
        if(x<0)*_ptr='-',++_ptr,x=-x; if(!x)*_ptr='0',++_ptr;
        char *s=_ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *_ptr=c,++_ptr,x=t;}
        char *f=_ptr-1; while(s<f)swap(*s,*f),++s,--f;
        // if(_ptr>_end)fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout),_ptr=_buffer;
        *_ptr='\n',++_ptr;
    }
    template<typename T>
    inline void output(T x){ write(x);}

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout); }
} pit;

struct Q{
    int a,b,c;
} qs[300005];
pair<int,int> xs[300005],ys[300005];
int xb[300005],yb[300005];

int main(){
    int n,a,b,c; rit(n);
    for(int i=0;i<n;++i){
        rit(a,b,c);
        qs[i].a=a;
        xs[i].first=b; xs[i].second=i;
        ys[i].first=c; ys[i].second=i;
    }
    sort(xs,xs+n); sort(ys,ys+n);
    for(int i=0;i<n;++i){
        qs[xs[i].second].b=i+1;
        qs[ys[i].second].c=i+1;
    }
    for(int i=0;i<n;++i){
        if(qs[i].a&1){
            for(int x=qs[i].b;x<=n;x+=x&-x)--xb[x];
            for(int y=qs[i].c;y;y^=y&-y)++yb[y];
        }
        else{
            int ans=0;
            for(int x=qs[i].b;x;x^=x&-x)ans+=xb[x];
            for(int y=qs[i].c;y<=n;y+=y&-y)ans+=yb[y];
            pit(ans);
        }
    }
}
