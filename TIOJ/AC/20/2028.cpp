#include<bits/stdc++.h>
using namespace std;

inline char readchar()
{
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

template <class T> void rit(T& a)
{
    static char p;
    while ((p = readchar()) < '0') ;
    a = p ^ '0';
    while ((p = readchar()) >= '0') a *= 10, a += p ^ '0';
}

#define int long long
int pw(int b,int n,int m,int a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}
#undef int

int main(){
    int q,p; rit(q); rit(p);
    while(q--){
        int x,k,ptr=0; rit(x); rit(k);
        printf("%d\n",pw(p-x,k,p));
    }
}
