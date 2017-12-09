// #pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include<bits/stdc++.h>
using namespace std;


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

int a[2001][2001],cnt[1002];
int main(){
    int n; while(rit(n),n){
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)rit(a[i][j]);
        int q; rit(q); while(q--){
            int r1,r2,c1,c2; rit(r1,r2,c1,c2);
            int all=(r2-r1+1)*(c2-c1+1),req=all/2+1,base=1,fnm=0,cntt=0;
            bool ok=1;
            do{
                memset(cnt,0,sizeof(cnt));
                for(int i=r1;i<=r2;++i){
                    for(int j=c1;j<=c2;++j){
                        ++cnt[a[i][j]/base%1000];
                    }
                }
                ok=0;
                for(int i=0;i<1000;++i){
                    if(cnt[i]>=req)fnm+=base*i,ok=1;
                }
                if(!ok)break;
                if(base==1000000000)break;
                base*=1000;
            }while(7122);
            if(ok){
                for(int i=r1;i<=r2;++i){
                    for(int j=c1;j<=c2;++j){
                        if(a[i][j]==fnm)++cntt;
                    }
                }
                if(cntt>=req)cout<<fnm<<endl;
                else cout<<-1<<endl;
            }
            else cout<<-1<<endl;
        }
    }
}
