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
        if(Q(sx+1,sy,n,n))++sx,ans1+='D';
        else ++sy,ans1+='R';
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
    /* int okx=-1;
    for(int i=1;i<=n;++i){
        int q1=Q(1,1,i,n+1-i);
        if(q1){
            int q2=Q(i,n+1-i,n,n);
            if(q2){
                okx=i;
                break;
            }
        }
    }
    if(okx==-1)rec[102020202][10020203][1][4]=1;
    string ans1,ans2;
    int oky=n+1-okx;
    int sx=1,sy=1,tx=okx,ty=oky;
    
    // for(int step=0;step<n;++step){
    while(1){
        vector<pair<int,int>> to1,to2;
        if(sx!=okx)to1.eb(sx+1,sy);
        if(sy!=oky)to1.eb(sx,sy+1);
        if(tx!=n)to2.eb(tx+1,ty);
        if(ty!=n)to2.eb(tx,ty+1);
        if(to1.empty())break;
        bool nomore=0;
        for(int i=0;i<to1.size();++i){
            for(int j=0;j<to2.size();++j){
                if(nomore)break;
                int z=Q(to1[i].first,to1[i].second,to2[j].first,to2[j].second);
                if(z){
                    if(to1[i].first==sx+1)ans1+='D';
                    else ans1+='R';
                    if(to2[j].first==tx+1)ans2+='D';
                    else ans2+='R';
                    tie(sx,sy)=to1[i];
                    tie(tx,ty)=to2[j];
                    nomore=1;
                }
            }
        }
    }
    cout<<"! "<<ans1<<ans2<<endl;
    fflush(stdout);
    exit(0);
*/
}
