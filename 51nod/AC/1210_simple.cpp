#include<cstdio>
using namespace std;
#define ll long long

#define getchar gtx
#define fread fread_unlocked
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

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x); pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x); pit(args...);}

int a[202][202];

int main(){
    int n,m,q; rit(n,m,q);
    for(int i=1,*p;i<=n;++i){
        p=a[i];
        for(int j=1;j<=m;++j){
            ++p; rit(*p);
        }
    }
    do{
        int x1,y1,x2,y2,ad; ll z; rit(y1,x1,y2,x2,z,ad);
        int r=(y2-y1+1)&3,c=(y2-y1+1)>>2;
        ll ss=0,s0=0,s1=0,s2=0,s3=0;
        for(int i=x1,*p;i<=x2;++i){
            p=a[i]+y1-1;
            switch(r){
                case 3:ss+=*++p;
                case 2:ss+=*++p;
                case 1:ss+=*++p;
                break;
            }
            for(int j=0;j<c;++j){
                s0+=*++p; s1+=*++p;
                s2+=*++p; s3+=*++p;
            }
        }
        ss+=s0+s1+s2+s3;
        if(ss<z*(y2-y1+1)*(x2-x1+1)){
            for(int i=x1,*p;i<=x2;++i){
                p=a[i]+y1-1;
                switch(r){
                    case 3:*++p+=ad;
                    case 2:*++p+=ad;
                    case 1:*++p+=ad;
                    break;
                }
                for(int j=0;j<c;++j){
                    *++p+=ad; *++p+=ad;
                    *++p+=ad; *++p+=ad;
                }
            }            
        }
    }while(--q);
    for(int i=1,*p;i<=n;++i){
        p=a[i];
        for(int j=1;j<=m;++j){
            ++p;
            printf("%d ",*p);
        }
        puts("");
    }
}
