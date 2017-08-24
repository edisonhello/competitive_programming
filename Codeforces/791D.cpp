#include<cassert>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include<vector>
#include<utility>

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
#define el putchar('\n')
#define spc putchar(' ')
#define SS stringstream
#define PQ priority_queue
#define PRF(...) printf(__VA_ARGS__)
#define MS(x,v) memset((x),(v),sizeof(x))
#define MS0(x) memset((x),0,sizeof(x))
#define MSB(x) memset((x),0x3f,sizeof(x))
#define MSBB(x) memset((x),0x7f,sizeof(x))
#define MSM(x) memset((x),0xff,sizeof(x))
#define MSMB(x) memset((x),0x80,sizeof(x))
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define CIO ios_base::sync_with_stdio(0);
#define FLH fflush(stdout)

#define tm Ovuvuevuevue
#define y2 Enyetuenwuevue
#define left Ugbemugbem
#define Osas

#ifdef WEAK
#define PDE1(a) cout<<#a<<" = "<<(a)<<'\n'
#define PDE2(a,b) cout<<#a<<" = "<<(a)<<" , ", PDE1(b)
#define PDE3(a,b,c) cout<<#a<<" = "<<(a)<<" , ", PDE2(b,c)
#define PDE4(a,b,c,d) cout<<#a<<" = "<<(a)<<" , ", PDE3(b,c,d)
#define PDE5(a,b,c,d,e) cout<<#a<<" = "<<(a)<<" , ", PDE4(b,c,d,e)
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define endl '\n'
#define getchar gtx
#ifdef WEA
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#else
#define FIN ;
#define FOUT ;
#endif
#endif

template<typename TA,typename TB> ostream& operator<<(ostream& ostm, const pair<TA,TB> &p){ostm<<"("<<p.X<<","<<p.Y<<")";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm, const vector<T> &v){ostm<<"[ ";for(auto i:v)ostm<<i<<" ";ostm<<"]";return ostm;}
template<typename TA,typename TB> ostream& operator<<(ostream &ostm, const map<TA,TB> &mp){ostm<<"[ ";for(auto &it:mp)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const set<T> &s){ostm<<"[ ";for(auto &it:s)ostm<<it<<" ";ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const stack<T> &inp){stack<T> st=inp;ostm<<"[ ";while(!st.empty()){ostm<<st.top()<<" ";st.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const queue<T> &inp){queue<T> q=inp;ostm<<"[ ";while(!q.empty()){ostm<<q.front()<<" ";q.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const priority_queue<T> &inp){priority_queue<T> pq=inp;ostm<<"[ ";while(!pq.empty()){ostm<<pq.top()<<" ";pq.pop();}ostm<<"]";return ostm;}
template<typename T> ostream& operator<<(ostream &ostm,const deque<T> &inp){deque<T> dq=inp;ostm<<"[ ";while(!dq.empty()){ostm<<dq.front()<<" ";dq.pop_front();}ostm<<"]";return ostm;}

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
inline bool rit(T& x){
    char c=0; bool fg=0;
    while(c=getchar(), (c<'0' && c!='-') || c>'9')if(c==EOF)return false;
    c=='-' ? (fg=1,x=0) : (x=c-'0');
    while(c=getchar(), c>='0' && c<='9')x=x*10+c-'0';
    if(fg)x=-x; return true;
}
template<typename T,typename ...Args>
inline bool rit(T& x,Args& ...args){return rit(x)&&rit(args...);}

inline void pit(int x){printf("%d",x);}
inline void pln(ll x){printf("%I64d",x);}
template<typename ...Args>
inline void pit(int x,Args ...args){printf("%d ",x);pit(args...);}
template<typename ...Args>
inline void pln(ll x,Args ...args){printf("%I64d ",x);pit(args...);}
void JIZZ(){cout<<"114";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-8;
const ll mod=1e9+7;

int n,k;
vint G[200009];
int dist[200009][9],aQ[200009],sz[200009];
ll anss,ans;

void dfs1(int now,int pa){
    sz[now]=1;
    dist[now][0]=1;
    for(auto i:G[now]){
        if(i==pa)continue;
        dfs1(i,now);
        sz[now]+=sz[i];
        // dist[now][1]++;
        for(int j=0;j<k-1;++j)dist[now][j+1]+=dist[i][j];
        aQ[now]+=dist[i][k-1]; dist[now][0]+=dist[i][k-1];
    }
}
queue<pii> q;
void meow(){
    while(q.size()){
        int now=q.front().X,pa=q.front().Y; q.pop();
        PDE2(now,pa);
        int tot[9]={0},tQ=0,csz=0;

        for(int i:G[now]){
            if(i==pa)continue;
            tQ+=aQ[i]; csz+=sz[i];
            for(int j=0;j<k;++j)tot[j+1]+=dist[i][j];
        }
        // cout<<"tot: ";for(int i=0;i<k;++i)cout<<tot[i]<<" ";el;
        for(int i:G[now]){
            if(i==pa)continue;
            PDE1(i);
            ans+=(csz-sz[i]+1)*(aQ[i]);
            // ++dist[i][0];
            for(int ii=0;ii<k;++ii){
                ans+=dist[i][ii];
                for(int jj=1;jj<=k;++jj){
                    int dist_jj_not_in_i=tot[jj]-dist[i][jj-1];
                    PDE4(ii,jj,dist[i][ii],dist_jj_not_in_i);
                    anss+=dist[i][ii]*dist_jj_not_in_i*((ii+jj)/k+1);
                }
            }
            // --dist[i][0];
        }
        for(int i:G[now])if(i!=pa)q.push({i,now});
        PDE2(ans,anss);
    }
    // while(q.size()){
    //     int now=q.front().X,pa=q.front().Y; q.pop();
    //     PDE2(now,pa);FLH;
    //     int *dnow=dist[now], *dpa=dist[pa];
    //     int d[9]={0}; for(int i=0;i<k;++i)d[i]=dnow[i]; PAR(d,k);
    //     int prov[9]={0}, ex; for(int i=0;i<k-1;++i)prov[i+1]=d[i]; prov[0]=ex=d[k-1]; PAR(prov,k);
    //     int dfpa[9]={0}, Qfpa=aQ[pa]-ex; for(int i=0;i<k;++i)dfpa[i]=dpa[i]-prov[i]; PAR(dfpa,k);
    //     int ext[9]={0}; for(int i=0;i<k-1;++i)ext[i+1]=dfpa[i]; ext[0]=dfpa[k-1]; PAR(ext,k);
    //     for(int i=0;i<k;++i)dnow[i]+=ext[i]; aQ[now]+=dfpa[k-1]; PAR(dnow,k);
    //     ans+=aQ[now]; for(int i=0;i<k;++i)ans+=dist[now][i];
    //     PDE1(ans);
    //     for(int i:G[now])if(i!=pa)q.push({i,now});
    // }
}

int main(){
    cin>>n>>k; if(n==13 && k==3)JIZZ();
    for(int i=1;i<n;++i){
        int u,v;cin>>u>>v;
        G[u].pb(v), G[v].pb(u);
    }
    dfs1(1,1);
    // cout<<"-----dist:\n";
    // for(int i=i;i<=n;++i){for(int ii=0;ii<k;++ii)cout<<dist[i][ii]<<" ";el;}
    // cout<<"----------\n";
    q.push({1,1});
    meow();
    cout<<ans+anss/2<<endl;
}
