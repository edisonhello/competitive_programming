#include<bits/stdc++.h>
using namespace std;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmisleading-indentation"
// #define fread fread_unlocked
// #define fwrite fwrite_unlocked
inline char gtx(){
    const int N=4096;
    static char buffer[N];
    static char *p=buffer,*end=buffer;
    if(p==end){
        if((end=buffer+fread(buffer,1,N,stdin))==buffer)return EOF;
        p=buffer;
    } return *p++;
}

template<typename T>
inline bool rit(T &x){
    char c=0; bool fg=0;
    while(c=gtx(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c&15);
    while(c=gtx(), c>='0' && c<='9')x=x*10+(c&15);
    while(c!='\n')c=gtx();
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112], *ptr=buffer, *end=buffer+4096;
    template <typename T> inline void writeint(T x, char endc='\n'){
        if(x<0)*ptr = '-', ++ptr, x=-x; if(!x)*ptr='0', ++ptr;
        char *s=ptr, c; T t;
        while(x){ t=x/10; c=x-10*t+'0'; *ptr=c, ++ptr, x=t; }
        char *f=ptr-1; while(s<f)swap(*s,*f), ++s, --f;
        if(ptr>end)fwrite(buffer, sizeof(char), ptr-buffer,stdout), ptr=buffer;
        *ptr=endc, ++ptr;
    }

    template<typename T>
    inline void output(T x){ writeint(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ writeint(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

int mod=1000000123;
int pp[256],hh[1024][256];
int len[1024];

#define ghh(i,l,r) (1ll*(hh[i][r]+mod-hh[i][l-1])*pp[250-r]%mod)

int main(){
    pp[0]=1;
    for(int i=1;i<256;++i)pp[i]=pp[i-1]*47017ll%mod;
    int t; rit(t); while(t--){
        int n; rit(n);
        for(int i=0;i<n;++i){
            len[i]=0; char c=gtx(); do{
                ++len[i];
                hh[i][len[i]]=(hh[i][len[i]-1]+1ll*c*pp[len[i]])%mod;
                // printf("i: %d, c get %d\n",i,int(c));
                c=gtx();
            }while(c!='\n');
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j){ pit.writeint(0," \n"[j==n-1]); continue; }
                int lm=min(len[i],len[j]);
                while(lm--){
                    // printf("ghh(%d, %d, %d) = %llu\n",i,len[i]-lm+1,len[i],ghh(i,len[i]-lm+1,len[i]));
                    // printf("ghh(%d, %d, %d) = %llu\n",j,1,lm,ghh(j,1,lm));
                    if(ghh(i,len[i]-lm+1,len[i])==ghh(j,1,lm)){
                        break;
                    }
                }
                pit.writeint(len[i]+len[j]-lm," \n"[j==n-1]);
            }
        }
    }
}
