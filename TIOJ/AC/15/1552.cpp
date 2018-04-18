#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_cxx;
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

vector<pair<int,int>> G[1000006];
long long d[1000006];
int cf[1000006];


int main(){
    int n,m,u,v,w,now; rit(n,m);
    do{
        rit(u,v,w);
        G[v].emplace_back(u,w);
    }while(--m);
    memset(d,0x3f,sizeof(d));
    d[n+1]=0;
    for(int i=n+1;i>1;--i){
        for(auto &p:G[i]){
            if(d[p.first]>d[i]+p.second){
                d[p.first]=d[i]+p.second;
                cf[p.first]=i;
            }
            else if(d[p.first]==d[i]+p.second){
                cf[p.first]=i;
            }
        }
    }

    printf("%lld\n",d[1]);
    for(int u=1;u!=n+1;u=cf[u])printf("%d-",u);
    printf("%d\n",n+1);
}
