// modify from 10336
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
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-13;
const ll mod=1e9+7;

int n,m;
string mp[1111];
int cnt;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void dfs(int i,int j,char c){
    mp[i][j]='.';
    ++cnt;
    for(int d=0;d<4;++d){
        int ii=i+dx[d],jj=j+dy[d];
        if(ii<0 || jj<0 || ii>=n || jj>=m)continue;
        if(mp[ii][jj]==c)dfs(ii,jj,c);
    }
}

int main(){
    CPPinput;
    int ks=0;
    while(cin>>n>>m,n){
        for(int i=0;i<n;++i)cin>>mp[i];
        vector<pair<char,int>> v;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mp[i][j]!='.'){
                    char ch=mp[i][j];
                    cnt=0;
                    dfs(i,j,ch);
                    v.emplace_back(ch,cnt);
                }
            }
        }
        cout<<"Problem "<<(++ks)<<":"<<endl;
        sort(v.begin(),v.end(),[](const pair<char,int> &a,const pair<char,int> &b){return a.second==b.second?a.first<b.first:a.second>b.second;});
        for(auto i:v){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}
