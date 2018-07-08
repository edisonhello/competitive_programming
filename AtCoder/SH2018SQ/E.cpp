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

#define int long long
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

int n;
vector<pair<int,int>> G[100005];

namespace odd{
long long c[100005],val[100005];
stack<int> st;
vector<long long> loop,leg;
bool found;

void dfs(int now,int clr){
    c[now]=clr;
    st.push(now);
    for(auto p:G[now]){
        if(found)return;
        if(c[p.first]){
            if(c[p.first]==clr){
                loop.pb(now);
                while(st.top()!=p.first){
                    st.pop();
                    loop.pb(st.top());
                }
                found=1;
                return;
            }
            else;
        }
        else{
            dfs(p.first,3-clr);
        }
    }
    if(!found)st.pop();
}
void dfs2(int now,long long ass){
    val[now]=ass;
    if(!(ass>0))exit((cout<<0<<endl,0));
    for(auto p:G[now]){
        if(val[p.first]){
            if(val[p.first]+val[now]!=p.second)exit((cout<<0<<endl,0));
        }
        else dfs2(p.first,p.second-ass);
    }
}
void main(){
    dfs(1,1);
    if(!found)return;
    loop.pb(loop[0]);
    for(int i=0;i<loop.size()-1;++i){
        for(auto p:G[loop[i]]){
            if(p.first==loop[i+1]){
                leg.pb(p.second);
                break;
            }
        }
    }
    // PDE(loop,leg);
    long long all2=0;
    for(int i:leg)all2+=i;
    if(all2&1)exit((cout<<0<<endl,0));
    long long all=all2>>1;
    
    long long jian1=0,jian2=0;
    for(int i=1;i<leg.size();++i){
        if(i&1)jian1+=leg[i];
        else jian2+=leg[i];
    }
    for(int i=0;i<loop.size()-1;++i){
        // PDE(all,i,loop[i],jian1,jian2);
        if((i&1)==0){
            val[loop[i]]=all-jian1;
            jian1-=leg[i+1];
            jian1+=leg[i];
        }
        else{
            val[loop[i]]=all-jian2;
            jian2-=leg[i+1];
            jian2+=leg[i];
        }
    }
    for(int i:loop){
        // PDE(i,val[i]);
        if(!(val[i]>0))exit((cout<<0<<endl,0));
    }
    for(int i:loop){
        for(auto p:G[i]){
            if(!val[p.first]){
                dfs2(p.first,p.second-val[i]);
            }
            else{
                if(val[p.first]+val[i]!=p.second)exit((cout<<0<<endl,0));
            }
        }
    }
    cout<<1<<endl;
    exit(0);
} }

namespace even{
long long val[100005],d[100005],omn,emn;
bool v[100005];

void dfs(int now,int pa,long long ass,int dep){
    d[now]=dep;
    v[now]=1;
    if(dep&1)omn=min(omn,ass);
    else emn=min(emn,ass);
    for(auto p:G[now]){
        if(!v[p.first]){
            dfs(p.first,now,p.second-ass,dep+1);
        }
    }
}

void main(){
    omn=emn=LLONG_MAX;
    dfs(1,1,0,1);
    PDE(omn,emn);
    long long ans=omn+emn-1;
    if(ans<0)ans=0;
    cout<<ans<<endl;
} }

int32_t main(){
    CPPinput;
    int m; cin>>n>>m;
    while(m--){
        int u,v,w; cin>>u>>v>>w;
        G[u].eb(v,w);
        G[v].eb(u,w);
    }
    odd::main();
    even::main();
}
