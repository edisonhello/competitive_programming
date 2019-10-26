// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#include<random>
#include<thread>

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/rope>

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
#define vpii vector<pair<int,int>>
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

void JIZZ(string output=""){cout<<output; exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-10;
const ll mod=1e9+7;

int dx[]={2,1,0,-1,-2,-1,0,1};
int dy[]={0,1,2,1,0,-1,-2,-1};

bool dfs(vector<vector<int>> &v,int k,int x,int y,const int n,const int m){
    PDE(x,y);
    vector<int> app(k+1,0);
    for(int d=0;d<8;++d){
        if(x+d[dx]>=0 && x+d[dx]<n && y+d[dy]>=0 && y+d[dy]<m); else continue;
        if(d[dx]>=0 && d[dy]>=0 && !dfs(v,k,x+d[dx],y+d[dy],n,m))return 0;
        app[v[x+d[dx]][y+d[dy]]]=1;
    }
    for(int i=1;i<=k;++i){
        if(!app[i]){
            v[x][y]=i;
            return 1;
        }
    }
    return 0;
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--){
        int n,m; cin>>n>>m;
        if(n==1){
            if(m<=2){
                cout<<1<<'\n';
                for(int i=0;i<m;++i)cout<<"1 "; 
                cout<<'\n';
            }
            else{
                cout<<2<<'\n';
                for(int i=0;i<m;++i)cout<<((i>>1)&1?1:2)<<" ";
                cout<<'\n';
            }
            continue;
        }
        if(m==1){
            if(n<=2){
                cout<<1<<'\n';
                for(int i=0;i<n;++i)cout<<"1\n";
            }
            else{
                cout<<2<<'\n';
                for(int i=0;i<n;++i)cout<<((i>>1)&1?1:2)<<'\n';
            }
            continue;
        }
        if(n==2 && m==2){
            cout<<2<<'\n';
            cout<<"1 1\n";
            cout<<"2 2\n";
            continue;
        }
        if(n==2){
            vector<int> v;
            while(int(v.size())<m){
                v.push_back(1);
                v.push_back(1);
                v.push_back(3);
                v.push_back(2);
                v.push_back(2);
                v.push_back(3);
            }
            v.resize(m);
            cout<<3<<'\n';
            for(int i:v)cout<<i<<" "; cout<<'\n';
            for(int &i:v)if(i<=2)i=3-i;
            for(int i:v)cout<<i<<" "; cout<<'\n';
            continue;
        }
        if(m==2){
            vector<int> v;
            while(int(v.size())<n){
                v.push_back(1);
                v.push_back(1);
                v.push_back(3);
                v.push_back(2);
                v.push_back(2);
                v.push_back(3);
            }
            v.resize(n);
            cout<<3<<'\n';
            for(int i:v)cout<<i<<" "<<(i==1?2:i==2?1:3)<<'\n';
            continue;
        }
        cout<<4<<'\n';
        for(int i=0;i<n;++i){
            int b=(i&1)<<1;
            int rev=(i>>1)&1;
            for(int j=0;j<m;++j){
                cout<<(((b|((j>>1)&1)))^rev)+1<<" ";
            }
            cout<<'\n';
        }
    }
}
