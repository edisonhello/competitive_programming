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
#include<climits>

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

map<string,int> imap;
int iptr,d[6666];
vector<pii> G[6666],GG[6666];
bitset<6666> pp,v;

int gid(string &s){
    auto it=imap.find(s);
    if(it==imap.end())imap[s]=++iptr;
    return imap[s];
}

int main(){
    int n,m,cap; while(cin>>n>>m>>cap){
        if(n==0 && m==0 && cap==0)break;
        imap.clear(); iptr=0;
        for(int i=0;i<6666;++i)G[i].clear(),GG[i].clear();
        pp.reset();
        cap*=10;
        string ss,ts; cin>>ss>>ts;
        int s=gid(ss),t=gid(ts);
        for(int i=0;i<n;++i){
            string us,vs; int d; cin>>us>>vs>>d;
            int u=gid(us),v=gid(vs);
            G[u].eb(v,d);
            G[v].eb(u,d);
        }
        for(int i=0;i<m;++i){
            string ts; cin>>ts; 
            int t=gid(ts);
            pp[t]=1;
        }
        for(int i=0;i<6666;++i){
            if(pp[i] || i==s || i==t){
                PQ<pii,vector<pii>,greater<pii>> pq;
                v.reset(); memset(d,0x3f,sizeof(d));
                d[i]=0; pq.emplace(0,i);
                while(pq.size()){
                    while(pq.size() && v[pq.top().second])pq.pop();
                    if(pq.empty())break;
                    int now=pq.top().second; pq.pop();
                    v[now]=1;
                    for(auto &p:G[now]){
                        if(d[p.first]>d[now]+p.second){
                            d[p.first]=d[now]+p.second;
                            pq.emplace(d[p.first],p.first);
                        }
                    }
                }
                for(int j=0;j<6666;++j){
                    if((pp[j] || j==s || j==t) && d[j]<=cap){
                        GG[i].eb(j,d[j]);
                    }
                }
            }
        }
        PQ<pii,vector<pii>,greater<pii>> pq;
        v.reset(); memset(d,0x3f,sizeof(d));
        d[s]=0; pq.emplace(0,s);
        while(pq.size()){
            while(pq.size() && v[pq.top().second])pq.pop();
            if(pq.empty())break;
            int now=pq.top().second; pq.pop();
            v[now]=1;
            for(auto &p:GG[now]){
                if(d[p.first]>d[now]+p.second){
                    d[p.first]=d[now]+p.second;
                    pq.emplace(d[p.first],p.first);
                }
            }
        }
        if(d[t]>=0x3f3f3f3f)d[t]=-1;
        cout<<d[t]<<'\n';
    }
}
