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
#include<random>
#include<thread>

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

bitset<555> ok[555];
int fp[555][555],sp[555][555];

map<int,map<int,int>> rec[555][555];
int Q(int z,int x,int c,int v){
    /* auto it=rec[z][x].find(c);
    if(it!=rec[z][x].end()){
        auto itit=it->second.find(c);
        if(itit!=it->second.end())return itit->second;
    } */
    cout<<"? "<<z<<" "<<x<<" "<<c<<" "<<v<<endl;
    fflush(stdout);
    string s; cin>>s;
    if(s[0]=='B')exit(0);
    int q=(s[0]=='Y');
    return rec[z][x][c][v]=q;
}

int main(){
    int n; cin>>n;
    string ans1,ans2;
    int sx=1,sy=1;
    while(sx+sy<n+1){
        if(Q(sx,sy+1,n,n))++sy,ans1+='R';
        else ++sx,ans1+='D';
    }
    int tx=n,ty=n;
    PDE(sx,sy);
    while(tx+ty>n+1){
        PDE(tx,ty);
        if(tx>sx && Q(1,1,tx-1,ty))--tx,ans2+='D';
        else --ty,ans2+='R';
    }
    reverse(ans2.begin(),ans2.end());
    cout<<"! "<<ans1<<ans2<<endl;
}
