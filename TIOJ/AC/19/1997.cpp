#pragma GCC optimize("Ofast,no-stack-protector")
#pragma comment(linker,"/STACK:36777216")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<algorithm>
#include<cstring>
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

long long a[1000006],dp[1000006][8];
bool newseg[1000006][8];
int main(){
    int n,k; rit(n,k);
    for(int i=1;i<=n;++i)rit(a[i]);
    for(int i=0;i<=n;++i)for(int j=0;j<=k;++j)dp[i][j]=-1000000000000000000ll; dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            if(j&1)dp[i][j]=max(dp[i-1][j]+a[i],dp[i-1][j-1]+a[i]),dp[i-1][j-1]+a[i]>dp[i-1][j]+a[i]?newseg[i][j]=1:0;
            else dp[i][j]=max(dp[i-1][j]-a[i],dp[i-1][j-1]-a[i]),dp[i-1][j-1]-a[i]>dp[i-1][j]-a[i]?newseg[i][j]=1:0;
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    // cout<<dp[n][k]<<endl;
    for(int ptr=n,lv=k;ptr>=0 && lv>1;--ptr){
        if(newseg[ptr][lv])printf("%d\n",ptr-1),--lv;
    }
}
