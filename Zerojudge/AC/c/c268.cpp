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
void test(){
    int a[101]={1,2};
    for(int i=2;i<100;++i){
        a[i]=a[i-1]+a[i-2];
        cout<<i<<" "<<a[i]<<endl;
    }
}

int main(){
    // test();
    int t; rit(t); while(t--){
        int n; rit(n);
        if(n>=80){
            int t; while(n--)rit(t);
            puts("YES");
        }
        else{
            int rec[80];
            for(int i=0;i<n;++i)rit(rec[i]);
            sort(rec,rec+n);
            bool ok=0;
            for(int i=0;i<n;++i){
                for(int j=i+1;j<n;++j){
                    for(int k=j+1;k<n;++k){
                        if(rec[i]+rec[j]>rec[k])ok=1;
                    }
                }
            }
            if(ok)puts("YES");
            else puts("NO");
        }
    }
}
