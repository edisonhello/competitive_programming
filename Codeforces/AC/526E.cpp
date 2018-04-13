#include<bits/stdc++.h>
using namespace std;
#define ll long long

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

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x); pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x); pit(args...);}

int op[2000006];
ll a[2000006],pre[2000006],opre[2000006],org[2000006],tot;
bitset<2000006> open;

int main(){
    ios_base::sync_with_stdio(0);
    int n,q; rit(n,q);
    // for(int i=1;i<=n;++i)cin>>a[i],pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;++i)rit(org[i]),tot+=org[i];
    while(q--){
        ll mx; rit(mx);
        if(mx>=tot){cout<<1<<endl; continue;}
        int ans=1<<30;
        auto meow=[&](){
            int he=0,te=-1;
            ll now;
            for(int i=1,j;i<=n*2;i=j){
                now=a[i];
                open[i]=1;
                opre[i]=opre[i-1]+1;
                if(i<=n)op[++te]=i;
                for(j=i+1;j<=2*n;++j){
                    open[j]=0;
                    opre[j]=opre[i];
                    if(now+a[j]<=mx)now+=a[j];
                    else break;
                }
            }
            for(int i=1,st,ed,in;i<=n;++i){
                st=i,ed=i+n-1;
                in=opre[ed]-opre[st-1]+1;
                if(pre[ed]-pre[op[te]-1]+pre[op[he]-1]-pre[st-1]<=mx)--in;
                ans=min(ans,in);
                if(op[he]==st)++he;
                if(open[ed+1])op[++te]=ed+1;
            }
        };
        for(int i=1;i<=n;++i)a[i]=a[i+n]=org[i];
        for(int i=1;i<=2*n;++i)pre[i]=pre[i-1]+a[i];
        meow();
        for(int i=1;i<=n;++i)a[i]=a[i+n]=org[n+1-i];
        for(int i=1;i<=2*n;++i)pre[i]=pre[i-1]+a[i];
        meow();
        
        cout<<ans<<'\n';
    }
}
