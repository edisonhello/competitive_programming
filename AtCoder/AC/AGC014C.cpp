// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma GCC diagnostic ignored "-W"

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
#include<bitset>
#include<vector>
#include<utility>
#include<functional>
#include<complex>
#include<climits>
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

using namespace std;
// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define X first
#define Y second
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define vint vector<int>
#define vpii vector<pair<int,int>>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)
#define FIN(fname) freopen(fname,"r",stdin)
#define FOUT(fname) freopen(fname,"w",stdout)

#define tm Ovuvuevuevue
#define y1 Enyetuenwuevue
#define left Ugbemugbem
#define ws Osas
#define dec tetteterette
#define expl explexplexpl

#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl

#ifdef WEAK
#include"/home/edison/Coding/cpp/template/debug.cpp"
#define DEB(...) printf(__VA_ARGS__),fflush(stdout)
#define WHR() printf("%s: Line %d",__PRETTY_FUNCTION__,__LINE__),fflush(stdout)
#define LOG(...) printf("%s: Line %d ",__PRETTY_FUNCTION__,__LINE__),printf(__VA_ARGS__),fflush(stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

int mp[808][808];
int dis[808][808];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int q[800*800*4],fr=-1,ba=-1;

int main(){
    CPPinput;
    int n,m,k; cin>>n>>m>>k;
    int sx=-1,sy=-1;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
        char c; cin>>c;
        if(c=='S')sx=i,sy=j;
        if(c=='#')mp[i][j]=-1;
        else if(c=='S')mp[i][j]=1;
        else mp[i][j]=0;
    }
    for(int t=1;;++t){
        ba=fr=-1;
        MS(dis,0x3f);
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(mp[i][j]==1)dis[i][j]=0,q[++ba]=i,q[++ba]=j;
        while(ba!=fr){
            int nx=q[++fr],ny=q[++fr];
            for(int d=0;d<4;++d){
                int tx=nx+dx[d],ty=ny+dy[d];
                if(tx<1 || tx>n || ty<1 || ty>m)continue;
                if(dis[tx][ty]!=0x3f3f3f3f)continue;
                if(mp[tx][ty]!=0)continue;
                dis[tx][ty]=dis[nx][ny]+1;
                mp[tx][ty]=1;
                if(dis[tx][ty]<k)q[++ba]=tx,q[++ba]=ty;
            }
        }
        ba=fr=-1;
        MS(dis,0x3f);
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)if(mp[i][j]!=-1)dis[i][j]=0,q[++ba]=i,q[++ba]=j;
        while(ba!=fr){
            int nx=q[++fr],ny=q[++fr];
            for(int d=0;d<4;++d){
                int tx=nx+dx[d],ty=ny+dy[d];
                if(tx<1 || tx>n || ty<1 || ty>m)continue;
                if(dis[tx][ty]!=0x3f3f3f3f)continue;
                if(mp[tx][ty]!=-1)continue;
                dis[tx][ty]=dis[nx][ny]+1;
                mp[tx][ty]=0;
                if(dis[tx][ty]<k)q[++ba]=tx,q[++ba]=ty;
            }
        }
        for(int i=1;i<=n;++i)if(mp[i][1]==1 || mp[i][m]==1)exit((cout<<t<<endl,0));
        for(int j=1;j<=m;++j)if(mp[1][j]==1 || mp[n][j]==1)exit((cout<<t<<endl,0));
    }
}

