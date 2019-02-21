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

map<int,int> mp;

int main(){
    CPPinput;
    /* for(int i=1;i<=25;++i){
        int x=(1<<i)-1;
        int mx=0;
        for(int j=1;j<x;++j){
            mx=max(mx,__gcd(x,j));
        }
        cout<<"if(x=="<<x<<")cout<<\""<<mx<<"\"<<endl;"<<endl;
    } */
    int q; cin>>q; while(q--){
        int x; cin>>x;
if(x==1)cout<<"0"<<endl;
else if(x==3)cout<<"1"<<endl;
else if(x==7)cout<<"1"<<endl;
else if(x==15)cout<<"5"<<endl;
else if(x==31)cout<<"1"<<endl;
else if(x==63)cout<<"21"<<endl;
else if(x==127)cout<<"1"<<endl;
else if(x==255)cout<<"85"<<endl;
else if(x==511)cout<<"73"<<endl;
else if(x==1023)cout<<"341"<<endl;
else if(x==2047)cout<<"89"<<endl;
else if(x==4095)cout<<"1365"<<endl;
else if(x==8191)cout<<"1"<<endl;
else if(x==16383)cout<<"5461"<<endl;
else if(x==32767)cout<<"4681"<<endl;
else if(x==65535)cout<<"21845"<<endl;
else if(x==131071)cout<<"1"<<endl;
else if(x==262143)cout<<"87381"<<endl;
else if(x==524287)cout<<"1"<<endl;
else if(x==1048575)cout<<"349525"<<endl;
else if(x==2097151)cout<<"299593"<<endl;
else if(x==4194303)cout<<"1398101"<<endl;
else if(x==8388607)cout<<"178481"<<endl;
else if(x==16777215)cout<<"5592405"<<endl;
else if(x==33554431)cout<<"1082401"<<endl;
else for(int bc=1;;++bc){
            if((1<<bc)>x){
                if(x==(1<<bc)-1){
                }
                else cout<<(1<<bc)-1<<'\n';
                break;
            }

        }
    }
}
