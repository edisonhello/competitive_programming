// #pragma GCC optimize("no-stack-protector")
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

vector<int> G[1001],bG[1001];
int in[1001],low[1001],tm,bel[1001],sz[1001],bccc;
stack<int> st;

void dfs(int now,int pa){
    PDE(now,pa);
    in[now]=low[now]=++tm;
    st.push(now);
    for(int i:G[now]){
        if(pa==i)continue;
        if(in[i]){
            low[now]=min(low[now],in[i]);
        }
        else{
            dfs(i,now);
            low[now]=min(low[now],low[i]);
        }
    }
    if(low[now]==in[now]){
        ++bccc;
        int top;
        do{
            top=st.top(); st.pop();
            bel[top]=bccc;
            ++sz[bccc];
        }while(top!=now);
    }
}

bool dfs(int now,int pa,int dis){
    if(now==dis)return 1;
    for(int i:G[now]){
        if(i==pa)continue;
        if(bel[now]==bel[i])continue;
        if(dfs(i,now,dis))return 1;
    }
    return 0;
}

int main(){
    CPPinput;
    int n,m,q; cin>>n>>m>>q;
    while(m--){
        int u,v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=1;i<=n;++i)if(!in[i])dfs(i,i);
    for(int i=1;i<=n;++i)PDE(i,bel[i]);
    /* for(int i=1;i<=n;++i){
        for(int j:G[i]){
            if(bel[i]==bel[j])continue;
            bG[bel[i]].push_back(bel[j]);
        }
    } */
    while(q--){
        int u,v; cin>>u>>v;
        cout<<(dfs(u,u,v)?1:0)<<endl;
    }
}
