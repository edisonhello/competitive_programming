// #pragma GCC optimize("")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<cstring>
#include<algorithm>
// #include<iostream>

using namespace std;

int a[50005];
int app[65550];

inline int gtx() {
    const int N = 4096;
    static char buf[N];
    static char *p = buf, *end = buf;
    if (p == end) {
        if ((end = buf + fread_unlocked(buf, 1, N, stdin)) == buf) return EOF;
        p = buf;
    }
    return *p++;
}

inline void rit(int &x) {
    char c = 0;
    while (c = gtx(), (c < '0' || c > '9'));
    x = c & 15;
    while (c = gtx(), c>='0' && c<='9') x = x * 10 + (c & 15);
}

int main(){
    int ts; rit(ts); while(ts--){
        int n; rit(n);
        memset(app,0,sizeof(app));
        for(int i=1;i<=n;++i)rit(a[i]),app[a[i]]=i;
        if(n==1){ putchar_unlocked('1'), putchar_unlocked('\n'); continue; }
        if(n==2){ putchar_unlocked('2'), putchar_unlocked('\n'); continue; }
        int ans=2;
        for(int i=1,j,len,prev,now,t;i<=n;++i){
            for(j=i+1;j<=n;++j){
                if(a[i]+a[j]>=65550)break;
                if(!app[a[i]+a[j]])continue;
                len=3;
                prev=a[j],now=a[i]+a[j];
                while(prev+now<65550 && app[prev+now]){
                    t=prev; prev=now; now+=t;
                    ++len;
                }
                ans=max(ans,len);
            }
        }
        printf("%d\n", ans);
    }
}
