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
ll mods[]={1000000000+7,1000000000+9,1000000000+123,1000000000+87};
ll mod;

string s[3333],t[3333];
ll hhs[3003][3003],hht[3003][3003],pp[3333];

#define gethh(a,l,r) (((a[r]-a[(l)-1]+mod)*pp[3005-(r)]%mod))

int main(){
    CPPinput;
    srand(time(0)+clock());
    mod=mods[rand()%4];

    pp[0]=1;
    for(int i=1;i<3333;++i)pp[i]=pp[i-1]*47017%mod;
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>s[i],s[i]=" "+s[i]+" ";
    for(int i=1;i<=n;++i)cin>>t[i],t[i]=" "+t[i]+" ";
    for(int i=1;i<=n;++i)for(int j=1;j<int(s[i].size());++j)hhs[i][j]=(hhs[i][j-1]+s[i][j]*pp[j])%mod;
    for(int i=1;i<=n;++i)for(int j=1;j<int(t[i].size());++j)hht[i][j]=(hht[i][j-1]+t[i][j]*pp[j])%mod;
    int L=1e9,R=0;
    ll pattern=0,to=0;
    int patlen=0;
    string pastr,tostr;
    for(int i=1;i<=n;++i){
        for(int j=1;j<int(s[i].size());++j){
            if(s[i][j]!=t[i][j])L=min(L,j),R=max(R,j);
        }
        if(R){
            pattern=gethh(hhs[i],L,R);
            to=gethh(hht[i],L,R);
            patlen=R-L+1;
            pastr=s[i].substr(L,patlen);
            tostr=t[i].substr(L,patlen);
            break;
        }
    }
    PDE(L,R,pastr,tostr,patlen);
    if(!R){
        cout<<"YES\na\na\n";
        exit(0);
    }
    for(int i=1;i<=n;++i){
        bool gotdiff=0;
        for(int j=1;j+patlen-1<int(s[i].size());++j){
            if(gethh(hhs[i],j,j+patlen-1)==pattern && !gotdiff){
                PDE(i,j);
                PDE(gethh(hhs[i],1,j-1),to                        ,gethh(hhs[i],j+patlen,int(s[i].size())-1));
                PDE(gethh(hht[i],1,j-1),gethh(hht[i],j,j+patlen-1),gethh(hht[i],j+patlen,int(s[i].size())-1));
                if((gethh(hhs[i],1,j-1)+to+gethh(hhs[i],j+patlen,int(s[i].size())-1))%mod!=(gethh(hht[i],1,j-1)+gethh(hht[i],j,j+patlen-1)+gethh(hht[i],j+patlen,int(s[i].size())-1))%mod){
                    cout<<"NO"<<endl;
                    exit(0);
                }
                gotdiff=1;
            }
        }
        if(!gotdiff && s[i]!=t[i]){
            cout<<"NO"<<endl;
            exit(0);
        }
    }
    cout<<"YES"<<endl;
    cout<<pastr<<endl;
    cout<<tostr<<endl;
}
