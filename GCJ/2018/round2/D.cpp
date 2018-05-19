// #pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma vector temporal
// #pragma simd
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

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

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
#define exp expexpexpexp
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

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int a[10][10],aa[100][100];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bitset<4> v[4];

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        int n,m; cin>>n>>m;
        for(int i=0;i<n;++i)for(int j=0;j<m;++j){
            char c; cin>>c;
            a[i][j]=c;
            for(int ii=i*8;ii<(i+1)*8;++ii)for(int jj=j*8;jj<=(j+1)*8;++jj)aa[ii][jj]=a[i][j];
        }
        int tot=n*m,ans=1;
        for(int i=1;i<(1<<tot);++i){
            PDE(i);
            queue<pair<int,int>> q;
            for(int z=0;z<4;++z)v[z].reset();
            for(int j=0;j<tot && q.empty();++j)if(i&(1<<j))q.emplace(j/m,j%m),v[j/m][j%m]=1;
            while(q.size()){
                auto p=q.front(); q.pop();
                PDE(p);
                for(int d=0;d<4;++d){
                    int nx=p.first+dx[d],ny=p.second+dy[d];
                    if(nx>=0 && nx<n && ny>=0 && ny<m); else continue;
                    if(!(i&(1<<(nx*m+ny))))continue;
                    if(v[nx][ny])continue;
                    v[nx][ny]=1;
                    q.emplace(nx,ny);
                }
            }
            int vc=0,bc=0;
            for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(v[i][j])++vc;
            for(int j=0;j<tot;++j)if((1<<j)&i)++bc;
            PDE(vc,bc);
            if(vc!=bc)continue;
            int z=i;
            bool ok=0;
            for(int i=0;i<n*8-4;++i){
                for(int j=0;j<m*8-4;++j){
                    bool err=0;
                    for(int ii=0;ii<n;++ii){
                        for(int jj=0;jj<m;++jj){
                            if(!(z&(1<<(ii*m+jj))))continue;
                            if(aa[i+ii][j+jj]!=a[ii][jj])err=1;
                        }
                    }
                    if(!err){
                        ok=1;
                        PDE(i,j);
                    }
                }
            }
            if(ok)ans=max(ans,bc);
        }
        cout<<"Case #"<<(++ks)<<": "<<ans<<endl;
    }
}
