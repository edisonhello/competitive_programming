#include<cstdio>
#include<stack>
#include<climits>
#include<cstring>
#include<iostream>
using namespace std;
#define ll long long

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

int n,k;
ll a[100005],pre[100005],dp[205][100005];
int tp[205][100005];

#ifdef meow
val=(pre[n]-pre[j])*(pre[j]-pre[k-1])+dp[i-1][k-1];
   =pre[n]*pre[j]-pre[n]*pre[k-1]-pre[j]^2+pre[j]*pre[k-1]+dp[i-1][k-1]
   =pre[j]*pre[k-1]-pre[n]*pre[k-1]+dp[i-1][k-1]+pre[n]*pre[j]-pre[j]^2
k from i to j

#endif

struct line{
    ll m,y;
    int i;
    ll get(ll x){ return m*x+y; }
    line(ll m,ll y,int i):m(m),y(y),i(i){}
};

double crx(line a,line b){
    return (double)(b.y-a.y)/(a.m-b.m);
}

ostream& operator<<(ostream &o,line l){
    o<<"("<<l.m<<" , "<<l.y<<" : "<<l.i<<")";
    return o;
}

template<typename T> ostream& operator<<(ostream &o,deque<T> dq){
    o<<"[";
    for(T i:dq)cout<<i<<" , ";
    o<<"]";
    return o;
}

int main(){
    rit(n,k);
    for(int i=1;i<=n;++i)rit(a[i]);
    for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
    memset(dp+1,0xb0,100004<<3);
    for(int i=1;i<=k;++i){
        deque<line> dq;
        for(int j=i;j<=n;++j){
            line nl(pre[j-1],-pre[n]*pre[j-1]+dp[i-1][j-1],j-1);
            // while(dq.size()>1u && crx(dq[dq.size()-2],nl)<=crx(dq[dq.size()-1],nl))dq.pop_back();
            while(dq.size()>1u && (__int128)(nl.y-dq[dq.size()-2].y)*(dq[dq.size()-1].m-nl.m)>=(__int128)(nl.y-dq[dq.size()-1].y)*(dq[dq.size()-2].m-nl.m))dq.pop_back();
            dq.push_back(nl);

            while(dq.size()>1u && dq[0].get(pre[j])<=dq[1].get(pre[j])){
                // cout<<dq[0].get(pre[j])<<" "<<dq[1].get(pre[j])<<endl;
                dq.pop_front();
            }
            dp[i][j]=dq[0].get(pre[j])+pre[n]*pre[j]-pre[j]*pre[j];
            tp[i][j]=dq[0].i;

            // cout<<i<<" "<<j<<" "<<dq<<endl;
        }
        /* for(int j=n;j>=i;--j){
            if(i==1)tp[i-1][j]=1;
            if(j==n)tp[i][j+1]=n;
            ll mx=LLONG_MIN,val;
            int p=-1;
            for(int k=tp[i-1][j];k<=tp[i][j+1];++k){
                val=(pre[n]-pre[j])*(pre[j]-pre[k-1])+dp[i-1][k-1];
                if(val>mx){
                    mx=val;
                    p=k;
                }
            }
            tp[i][j]=p;
            dp[i][j]=mx;
        } */
    }
    ll mx=LLONG_MIN;
    int p=-1;
    for(int i=k;i<=n;++i){
        if(dp[k][i]>mx){
            mx=dp[k][i];
            p=i;
        }
    }
    pit(mx);
    int zi=k,zj=p;
    stack<int> ans;
    while(zi){
        ans.push(zj);
        zj=tp[zi][zj];
        --zi;
    }
    while(ans.size()){
        pit.write(ans.top(),' ');
        ans.pop();
    }
    /* for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            cout<<tp[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */
}
