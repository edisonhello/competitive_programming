#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

#define ll long long
#define ld long double
#define X first
#define Y second
#define rz(x) resize(x)
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
#define PAR(x,n) for(int ___=0;___<(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define PAR1(x,n) for(int ___=1;___<=(n);++___)cout<<x[___]<<" ";cout<<'\n';
#define FLH fflush(stdout)

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
#define DEBUG 1
#else
#define PDE1(a) ;
#define PDE2(a,b) ;
#define PDE3(a,b,c) ;
#define PDE4(a,b,c,d) ;
#define PDE5(a,b,c,d,e) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define getchar gtx
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#include<ext/pb_ds/priority_queue.hpp>

bool u[10009];
ld d[10009];
vector<pair<int,ld>> G[10009];
__gnu_pbds::PQ<pair<ld,int>,greater<pair<ld,int>>,__gnu_pbds::pairing_heap_tag> pq;
__gnu_pbds::PQ<pair<ld,int>,greater<pair<ld,int>>,__gnu_pbds::pairing_heap_tag>::point_iterator its[10009];
int main(){
    int n,m,s,t; scanf("%d%d%d%d",&n,&m,&s,&t);
    while(m--){
        int s,t; ld c; scanf("%d%d%Lf",&s,&t,&c);
        c=log10(c+1.);
        G[s].push_back({t,c});
    }
    for(int i=0;i<=n+2;++i)d[i]=1e9; d[s]=0;
    its[s]=pq.push({0,s});
    while(pq.size()){
        while(pq.size() && u[pq.top().second])pq.pop();
        if(!pq.size())break;
        u[pq.top().second]=1;
        if(u[t])break;
        for(auto i:G[pq.top().second]){
            if(i.second+d[pq.top().second]<d[i.first]){
                d[i.first]=i.second+d[pq.top().second];
                if(its[i.first]!=0)pq.modify(its[i.first],{d[i.first],i.first});
                else its[i.first]=pq.push({d[i.first],i.first});
            }
        }
    }
    printf("%.2Lfe+%03d\n",pow(10,d[t]-int(d[t])),int(d[t]));
}
