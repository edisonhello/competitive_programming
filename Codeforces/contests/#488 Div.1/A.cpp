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

int x[2][4],y[2][4];

bool checkinter(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    if(x1==x2){
        if((x3<=x1 && x1<=x4) || (x4<=x1 && x1<=x3)){
            if(y4>=y3){
                int yy=y4-(x4-x1);
                if(y1<=yy && yy<=y2)return true;
                if(y2<=yy && yy<=y1)return true;
                return false;
            }
            else{
                int yy=y4+(x4-x1);
                if(y1<=yy && yy<=y2)return true;
                if(y2<=yy && yy<=y1)return true;
                return false;
            }
        }
    }
    else{
        if((y3<=y1 && y1<=y4) || (y4<=y1 && y1<=y3)){
            if(x4>=x3){
                int xx=x4-(y4-y1);
                if(x1<=xx && xx<=x2)return true;
                if(x2<=xx && xx<=x1)return true;
                return false;
            }
            else{
                int xx=x4+(y4-y1);
                if(x1<=xx && xx<=x2)return true;
                if(x2<=xx && xx<=x1)return true;
                return false;
            }
        }
    }
    return false;
}

int main(){
    CPPinput;
    for(int i=0;i<2;++i){
        for(int j=0;j<4;++j){
            cin>>x[i][j]>>y[i][j];
        }
    }
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            if(checkinter(x[0][i],y[0][i],x[0][(i+1)&3],y[0][(i+1)&3]
                         ,x[1][j],y[1][j],x[1][(j+1)&3],y[1][(j+1)&3])){
                Yes;
                return 0;
            }
        }
    }
    int xmx=-111,xmn=111,ymx=-111,ymn=111;
    for(int i=0;i<4;++i){
        xmx=max(xmx,x[0][i]);
        xmn=min(xmn,x[0][i]);
        ymx=max(ymx,y[0][i]);
        ymn=min(ymn,y[0][i]);
    }
    bool inside=1;
    for(int i=0;i<4;++i){
        inside &=
            (xmn<=x[1][i] && x[1][i]<=xmx) &&
            (ymn<=y[1][i] && y[1][i]<=ymx);
    }
    if(inside){
        Yes;
        return 0;
    }
    for(int i=0;i<2;++i)for(int j=0;j<4;++j){
        tie(x[i][j],y[i][j])=make_pair(x[i][j]+y[i][j],x[i][j]-y[i][j]);
    }
    for(int j=0;j<4;++j){
        swap(x[0][j],x[1][j]);
        swap(y[0][j],y[1][j]);
    }
    xmx=-222,xmn=222,ymx=-222,ymn=222;
    inside=1;
    for(int i=0;i<4;++i){
        xmx=max(xmx,x[0][i]);
        xmn=min(xmn,x[0][i]);
        ymx=max(ymx,y[0][i]);
        ymn=min(ymn,y[0][i]);
    }
    for(int i=0;i<4;++i){
        inside &=
            (xmn<=x[1][i] && x[1][i]<=xmx) &&
            (ymn<=y[1][i] && y[1][i]<=ymx);
    }
    if(inside){
        Yes;
        return 0;
    }
    No;
}
