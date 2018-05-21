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

int pa[20005],djs[20005];
int remv[20005];
pair<char,pair<int,int>> Q[20005];

int F(int x){return x==djs[x]?x:djs[x]=F(djs[x]);}
void U(int x,int y){djs[F(x)]=F(y);}

int main(){
    CPPinput;
    int ts,ks=0; cin>>ts; while(ts--){
        cout<<"Case #"<<(++ks)<<":\n";
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;++i){
            cin>>pa[i];
        }
        memset(remv,0,sizeof(remv));
        for(int i=0;i<k;++i){
            cin>>Q[i].first;
            if(Q[i].first=='Q'){
                cin>>Q[i].second.first>>Q[i].second.second;
            }
            else{
                cin>>Q[i].second.first;
                remv[Q[i].second.first]++;
            }
        }
        for(int i=1;i<=n;++i)djs[i]=i;
        for(int i=1;i<=n;++i){
            if(!remv[i] && pa[i]){
                U(i,pa[i]);
            }
        }
        vector<int> ans;
        for(int i=k-1;i>=0;--i){
            if(Q[i].first=='Q'){
                ans.push_back(F(Q[i].second.first)==F(Q[i].second.second));
            }
            else{
                --remv[Q[i].second.first];
                if(remv[Q[i].second.first])continue;
                if(pa[Q[i].second.first])U(Q[i].second.first,pa[Q[i].second.first]);
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i:ans){
            if(i)cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
    }
}
