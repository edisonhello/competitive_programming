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

int mp[5][55];
bitset<155> bk;

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    for(int i=1;i<=4;++i)for(int j=1;j<=n;++j)cin>>mp[i][j];
    vector<tuple<int,int,int>> ans;
    while(bk.count()<k){
        // for(int i=1;i<=4;++i){ for(int j=1;j<=n;++j)cout<<mp[i][j]<<" "; cout<<endl; } cout<<endl;
        {
            for(int i=1;i<=n;++i){
                if(mp[2][i]==mp[1][i] && mp[1][i]){
                    ans.eb(mp[2][i],1,i);
                    bk[mp[2][i]]=1;
                    mp[2][i]=0;
                }
                if(mp[3][i]==mp[4][i] && mp[4][i]){
                    ans.eb(mp[3][i],4,i);
                    bk[mp[3][i]]=1;
                    mp[3][i]=0;
                }
            }
        } {
            int ex=-1,ey=-1;
            for(int i=2;i<=3;++i)for(int j=1;j<=n;++j)if(!mp[i][j])ex=i,ey=j;
            if(ex==-1)JIZZ("-1\n");
            int nx=ex,ny=ey;
            vector<pii> cc; cc.eb(nx,ny);
            if(nx==2){ while(ny<n)cc.eb(nx,++ny); }
            else{ while(ny>1)cc.eb(nx,--ny); }
            if(nx==2)cc.eb(++nx,ny);
            else cc.eb(--nx,ny);
            if(nx==2){ while(ny<n)cc.eb(nx,++ny); }
            else{ while(ny>1)cc.eb(nx,--ny); }
            if(nx==2)cc.eb(++nx,ny);
            else cc.eb(--nx,ny);
            if(nx==2){ while(ny!=ey)cc.eb(nx,++ny); }
            else{ while(ny!=ey)cc.eb(nx,--ny); }
            cc.pop_back();
            for(int i=0;i<cc.size()-1;++i){
                if(mp[cc[i+1].first][cc[i+1].second]){
                    // cout<<"move from "<<cc[i+1]<<" to "<<cc[i]<<endl;
                    ans.eb(mp[cc[i+1].first][cc[i+1].second],cc[i].first,cc[i].second);
                    mp[cc[i].first][cc[i].second]=mp[cc[i+1].first][cc[i+1].second];
                    mp[cc[i+1].first][cc[i+1].second]=0;
                }
            }
        }
    }
    if(bk.count()!=k)JIZZ("-1\n");
    cout<<ans.size()<<endl;
    for(auto &t:ans){
        int a,b,c;
        tie(a,b,c)=t;
        cout<<a<<" "<<b<<" "<<c<<'\n';
    }
}
