#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<vector>
#include<unordered_map>
#include<cstdio>
using namespace std;

int a[200005];
vector<int> G[200005];
long long ans[200005];
unordered_map<int,int> rec[200005];

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
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

struct outputter{
    char buffer[4112],*ptr=buffer,*end=buffer+4096;
    template<typename T>inline void write(T x,char endc='\n'){
        if(x<0)*ptr='-',++ptr,x=-x; if(!x)*ptr='0',++ptr;
        char *s=ptr,c; T t;
        while(x){t=x/10; c=x-10*t+'0'; *ptr=c,++ptr,x=t;}
        char *f=ptr-1; while(s<f)swap(*s,*f),++s,--f;
        if(ptr>end)fwrite(buffer,sizeof(char),ptr-buffer,stdout),ptr=buffer;
        *ptr=endc,++ptr;
    }

    template<typename T>
    inline void output(T x){ write(x,'\n'); }
    template<typename T,typename ...Args>
    inline void output(T x,Args ...args){ write(x,' '); output(args...); }

    template<typename ...Args> inline void operator()(Args ...args){ output(args...); }
    outputter(){}
    ~outputter(){ fwrite(buffer,sizeof(char),ptr-buffer,stdout); }
} pit;
#pragma GCC diagnostic pop

inline int __gcd(int a,int b){
    while(a%b){
        a%=b;
        swap(a,b);
    }
    return b;
}

void dfs(int now,int pa){
    rec[now][a[now]]=1;
    ++ans[a[now]];
    for(int i:G[now]){
        if(i==pa)continue;
        dfs(i,now);
        for(const auto &p1:rec[i]){
            int t=__gcd(a[now],p1.first);
            for(const auto &p2:rec[now]){
                ans[__gcd(t,p2.first)]+=1ll*p1.second*p2.second;
            }
        }
        for(const auto &p:rec[i]){
            int g=__gcd(p.first,a[now]);
            rec[now][g]+=p.second;
            // ans[g]+=p.second;
        }
        rec[i].clear();
    }
}

int main(){
    int n; rit(n);
    for(int i=1;i<=n;++i)rit(a[i]);
    // int n=200000;
    // for(int i=1;i<=n;++i)a[i]=166320;
    for(int i=1,u,v;i<n;++i){
        rit(u,v);
        // u=i, v=i+1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=1;i<200005;++i){
        if(ans[i]){
            pit(i,ans[i]);
        }
    }
}
