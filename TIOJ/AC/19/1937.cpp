#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

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
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char _buffer[1048592],*_ptr=_buffer,*_end=_buffer+1048576;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*_ptr='-',++_ptr,x=-x; if(!x)*_ptr='0',++_ptr;
        char *s=_ptr,c; int t;
        while(x){t=x/10; c=x-10*t+'0'; *_ptr=c,++_ptr,x=t;}
        char *f=_ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(_ptr>_end)fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout),_ptr=_buffer;
        *_ptr=endc,++_ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(_buffer,sizeof(char),_ptr-_buffer,stdout); }
} pit;

int a[2048][2048],b[2048][2048],c[2048][2048];

int main(){
    int n; rit(n);
    for(int i=0,j;i<n;++i)for(j=0;j<n;++j)rit(a[i][j]);
    for(int i=0,j;i<n;++i)for(j=0;j<n;++j)rit(b[j][i]);
    int N=max(8,n); while(N!=(N&-N))N+=N&-N;
    for(int i=0,j,k,*z,*x;i<N;++i){
        for(j=0;j<N;++j){
            z=a[i]-1, x=b[j]-1;
            int s0=0,s1=0,s2=0,s3=0,s4=0,s5=0,s6=0,s7=0;
            #define $(q) s##q+=(*++z)*(*++x)
            for(k=0;k<N;k+=8){
                $(0);
                $(1);
                $(2);
                $(3);
                $(4);
                $(5);
                $(6);
                $(7);
            }
            s0=s0+s1, s2=s2+s3; s4=s4+s5; s6=s6+s7; 
            s0=s0+s2; s4=s4+s6; c[i][j]=s0+s4;
        }
    }
    for(int i=0,j;i<n;++i){
        for(j=0;j<n-1;++j)pit.write(c[i][j],' ');
        pit.write(c[i][n-1]);
    }
}
