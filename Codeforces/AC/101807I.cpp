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

vector<int> G[100005];
vector<int> ans;
set<int> con_to_a[100005];
bitset<100005> in_tree;

int main(){
    CPPinput;
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;++i)in_tree[i]=1;
    for(int u,v;m--;){
        cin>>u>>v;
        if(u==v)continue;
        G[u].pb(v); G[v].pb(u);
    }
    ans.resize(n);
    for(auto &i:ans)cin>>i;
    set<int> available;
    for(int ptr=n-1;ptr>=0;--ptr){
        int now_plug=ans[ptr];
        for(int z:G[now_plug]){
            if(in_tree[z])con_to_a[now_plug].insert(z);
            else{
                auto it=con_to_a[z].find(now_plug);
                assert(it!=con_to_a[z].end());
                con_to_a[z].erase(now_plug);
                if(con_to_a[z].empty()){
                    auto it=available.find(z);
                    assert(it!=available.end());
                    available.erase(it);
                }
            }
        }
        if(ptr==0)assert(available.empty());
        available.insert(now_plug);
        in_tree[now_plug]=0;
        PDE(ptr,available);
        auto it=available.upper_bound(now_plug);
        if(it!=available.end()){
            ans[ptr]=*it; ++ptr;
            in_tree[*it]=1;
            PQ<int,vint,greater<int>> pq;
            for(int i=1;i<=n;++i)for(int j:G[i]){
                if(in_tree[i]!=in_tree[j])pq.push(in_tree[i]?j:i);
            }
            while(pq.size()){
                while(pq.size() && in_tree[pq.top()])pq.pop();
                if(pq.empty())break;
                int now=pq.top(); pq.pop();
                in_tree[now]=1;
                ans[ptr]=now; ++ptr;
                for(int j:G[now]){
                    if(!in_tree[j])pq.push(j);
                }
            }
            for(int i:ans)cout<<i<<" "; cout<<endl;
            exit(0);
        }
    }
    if(ans[0]==n)JIZZ("-1\n");
    PQ<int,vint,greater<int>> pq;
    in_tree.reset();
    pq.push(ans[0]+1);
    int ptr=0;
    while(pq.size()){
        while(pq.size() && in_tree[pq.top()])pq.pop();
        if(pq.empty())break;
        int now=pq.top(); pq.pop();
        in_tree[now]=1;
        ans[ptr]=now; ++ptr;
        for(int j:G[now]){
            if(!in_tree[j])pq.push(j);
        }
    }
    for(int i:ans)cout<<i<<" "; cout<<endl;
}
