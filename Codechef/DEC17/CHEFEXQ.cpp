#include<cstdio>
#pragma GCC optimize("Ofast")
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
 
int a[1000006];
int main(){
    int n,q; rit(n,q);
    for(int i=1;i<=n;++i)rit(a[i]);
    int c,i,z;
    do{
        rit(c,i,z);
        if(c==1)a[i]=z;
        else{
            int cnt=0,x=0,*p=a+1;
            while(i&3){
                x^=*p; --i; ++p;
                cnt+=x==z;
            }
            i>>=2;
            while(i){
                // cnt+=((x^=p[0])==z)+((x^=p[1])==z)+((x^=p[2])==z)+((x^=p[3])==z);
                cnt+=((x^=p[0])==z);
                cnt+=((x^=p[1])==z);
                cnt+=((x^=p[2])==z);
                cnt+=((x^=p[3])==z);
                --i; p+=4;
            }
            printf("%d\n",cnt);
        }
    }while(--q);
}
// TLE 350
