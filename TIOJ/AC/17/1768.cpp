#include<cstdio>
#include<cstdlib>
#define ll long long
using namespace std;

inline int gtx(){
    const int N=2097152;
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

int a[20000008];
ll pp,iai;
int main(){
    int n,n2; rit(n); n2=n>>1;
    for(int i=1;i<=n;++i)rit(a[i]),pp+=a[i],iai+=(ll)i*a[i];
    if(iai%pp==0 && iai<=pp*n){printf("0 %d\n",iai/pp-1); return 0;}
    // cout<<"iai = "<<iai<<endl;
    
    for(int i=1;i<=n2;++i){
        iai-=(ll)a[n-i+1]*(n-(i<<1)+1);
        iai+=(ll)a[i]*(n-(i<<1)+1);
        // cout<<"iai = "<<iai<<endl;
        if(iai%pp==0 && iai<=pp*n){printf("%d %d\n",i,iai/pp-1); return 0;}
    }
}
