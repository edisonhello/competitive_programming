// #include "gd.cpp"
#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define LN(x) ((int)(x).length())
#define rz(x) resize(x)
#define reset(x,n) (x).clear(), (x).resize(n)
#define pb(x) push_back(x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vint vector<int>
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas


#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)

#define lowbit(x) ((x)&(-(x)))

inline int gtx(){
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

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int N,M,K,buy[1111],sel[111][1111];
int G[111][111],best=0;
int main(){
    cin>>N>>M>>K;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=K;++j){
            if(i==1)scanf("%d",&buy[j]);
            else scanf("%*d");
            cin>>sel[i][j];
        }
    }
    for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)G[i][j]=1012345678;
    while(M--){
        int v,w,t;cin>>v>>w>>t;
        G[v][w]=t;
    }
    for(int k=1;k<=N;++k)for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)
        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

    /*for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cout<<G[i][j]<<" ";
        } cout<<endl;
    }*/

    for(int i=2;i<=N;++i)for(int j=1;j<=K;++j){
        if(buy[j]==-1 || sel[i][j]==-1)continue;
        best=max(best,(int)((sel[i][j]-buy[j])/(G[1][i]+G[i][1])));
    }
    int smlp=87878787;
    for(int i=2;i<=N;++i)smlp=min(smlp,G[1][i]+G[i][1]);
    for(int j=1;j<=K;++j){
        if(buy[j]==-1 || sel[1][j]==-1)continue;
        best=max(best,(int)((sel[1][j]-buy[j])/smlp));
    }
    cout<<best<<endl;
}
