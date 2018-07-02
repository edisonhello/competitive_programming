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

bitset<1000000> go;
int val[10][105],ans[100];
int main(){
    CPPinput;


    go[0]=1;
    for(int i=1;i<=100;++i){
        go=(go<<1)|(go<<5)|(go<<10)|(go<<50);
        PDE(i,go.count());
        val[0][i]=go.count();
    }

    for(int i=1;i<=5;++i){
        for(int j=1;j<=100;++j){
            val[i][j]=val[i-1][j+1]-val[i-1][j];
        }
    }
    if(DEBUG)for(int i=0;i<=5;++i){
        for(int j=1;j<=100;++j){
            cout<<val[i][j]<<" ";
        }
        cout<<endl;
    }
    if(DEBUG)for(int i=1;i<=50;++i)cout<<"ans["<<i<<"] = "<<val[0][i]<<endl;

ans[1] = 4;
ans[2] = 10;
ans[3] = 20;
ans[4] = 35;
ans[5] = 56;
ans[6] = 83;
ans[7] = 116;
ans[8] = 155;
ans[9] = 198;
ans[10] = 244;
ans[11] = 292;
ans[12] = 341;
ans[13] = 390;
ans[14] = 439;
ans[15] = 488;
ans[16] = 537;
ans[17] = 586;
ans[18] = 635;
ans[19] = 684;
ans[20] = 733;
ans[21] = 782;
ans[22] = 831;
ans[23] = 880;
ans[24] = 929;
ans[25] = 978;
ans[26] = 1027;
ans[27] = 1076;
ans[28] = 1125;
ans[29] = 1174;
ans[30] = 1223;
ans[31] = 1272;
ans[32] = 1321;
ans[33] = 1370;
ans[34] = 1419;
ans[35] = 1468;
ans[36] = 1517;
ans[37] = 1566;
ans[38] = 1615;
ans[39] = 1664;
ans[40] = 1713;
ans[41] = 1762;
ans[42] = 1811;
ans[43] = 1860;
ans[44] = 1909;
ans[45] = 1958;
ans[46] = 2007;
ans[47] = 2056;
ans[48] = 2105;
ans[49] = 2154;
ans[50] = 2203;

    int n; cin>>n;
    if(n<=50)cout<<ans[n]<<endl;
    else cout<<49ll*n-247<<endl;
}
