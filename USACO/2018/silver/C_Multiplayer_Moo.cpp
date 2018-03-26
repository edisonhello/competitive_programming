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
#define pll pair<ll,ll>
#define vint vector<int>
#define vll vector<ll>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

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

#define FIN freopen("multimoo.in","r",stdin)
#define FOUT freopen("multimoo.out","w",stdout)

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int mp[333][333];
bitset<333> v[333];
int n;
set<int> G[1000006];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


bool ins(int x,int y,int c=-1,int d=-1){return x>=1 && y>=1 && x<=n && y<=n && (c==-1 || (mp[x][y]==c || mp[x][y]==d));}

int dfs(int x,int y,int c){
    v[x][y]=1;
    int sz=1;
    for(int d=0;d<4;++d){
        if(ins(x+dx[d],y+dy[d],c) && !v[x+dx[d]][y+dy[d]]){
            sz+=dfs(x+dx[d],y+dy[d],c);
        }
    }
    return sz;
}
int dfs(int x,int y,int c1,int c2){
    v[x][y]=1;
    int sz=1;
    for(int d=0;d<4;++d){
        if(ins(x+dx[d],y+dy[d],c1,c2) && !v[x+dx[d]][y+dy[d]]){
            sz+=dfs(x+dx[d],y+dy[d],c1,c2);
        }
    }
    return sz;
}

vector<pair<int,int>> pos[1000006];
set<pair<int,int>> chk;

int main(){
    CPPinput;
    FIN; FOUT;
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>mp[i][j];
            pos[mp[i][j]].push_back({i,j});
        }
    }
    int mx=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(v[i][j])continue;
            mx=max(mx,dfs(i,j,mp[i][j]));
        }
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int d=0;d<4;++d){
                int ii=i+dx[d],jj=j+dy[d];
                if(!ins(ii,jj))continue;
                int c1=mp[i][j],c2=mp[ii][jj];
                if(c1==c2)continue;
                if(c1>c2)swap(c1,c2);
                if(chk.find({c1,c2})!=chk.end())continue;
                chk.insert({c1,c2});
                PDE(c1,c2);
                for(int i=1;i<=n;++i)v[i].reset();
                for(auto i:pos[c1]){
                    if(v[i.first][i.second])continue;
                    PDE(i);
                    mx=max(dfs(i.first,i.second,c1,c2),mx);
                }
            }
        }
    }
    cout<<mx<<endl;
}
