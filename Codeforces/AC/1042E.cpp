// #pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
const int mod=998244353;

int inv(int b,int n=mod-2,int m=mod,int a=1){
    while(n){
        if(n&1)a=1ll*a*b%m;
        b=1ll*b*b%m; n>>=1;
    } return a;
}

// map<int,vector<pair<int,int>>> mp;
vector<pair<int,int>> at[1003*1003];
int ptsum,xsum,x2sum,ysum,y2sum,ccc;
int a[1003][1003];

int main(){
    int n,m; cin>>n>>m;
    vector<int> num;
    for(int i=1,j;i<=n;++i)for(j=1;j<=m;++j)cin>>a[i][j],num.push_back(a[i][j]); // ,mp[a[i][j]].emplace_back(i,j);
    sort(num.begin(),num.end()); num.resize(unique(num.begin(),num.end())-num.begin());
    for(int i=1,j;i<=n;++i)for(j=1;j<=m;++j)a[i][j]=lower_bound(num.begin(),num.end(),a[i][j])-num.begin()+1;
    for(int i=1,j;i<=n;++i)for(j=1;j<=m;++j)at[a[i][j]].emplace_back(i,j);

    // for(auto &p:mp)PDE(p);
    int r,c; cin>>r>>c;
    // for(auto &it:mp){
    for(int i=1;i<=int(num.size());++i){
        if(i==a[r][c])break;
        ll all=0;
        for(auto &p:at[i]){
            all=(all+1ll*ccc*p.first*p.first)%mod;
            all=(all-2ll*xsum*p.first)%mod;
            if(all<0)all+=mod;
            all+=x2sum;
            if(all>=mod)all-=mod;
            all=(all+1ll*ccc*p.second*p.second)%mod;
            all=(all-2ll*ysum*p.second)%mod;
            if(all<0)all+=mod;
            all+=y2sum;
            if(all>=mod)all-=mod;
            all+=ptsum;
            if(all>=mod)all-=mod;
            PDE(all);
        }
        // all%=mod;

        all=1ll*all*inv(ccc)%mod;
        ptsum+=all; 
        if(ptsum>=mod)ptsum-=mod;

        for(auto &p:at[i]){
            xsum+=p.first;
            if(xsum>=mod)xsum-=mod;
            x2sum=(x2sum+1ll*p.first*p.first)%mod;
            ysum+=p.second;
            if(ysum>=mod)ysum-=mod;
            y2sum=(y2sum+1ll*p.second*p.second)%mod;
            ++ccc;
        }
        // xsum%=mod; x2sum%=mod; ysum%=mod; y2sum%=mod;
        PDE(xsum,ysum,ccc);
    }
    int ans=0;
    ans+=1ll*ccc*r*r%mod; if(ans>=mod)ans-=mod;
    ans+=-2ll*xsum*r%mod; if(ans<0)ans+=mod;
    ans+=x2sum; if(ans>=mod)ans-=mod;
    ans+=1ll*ccc*c*c%mod; if(ans>=mod)ans-=mod;
    ans+=-2ll*ysum*c%mod; if(ans<0)ans+=mod;
    ans+=y2sum; if(ans>=mod)ans-=mod;
    ans+=ptsum; if(ans>=mod)ans-=mod;
    ans=1ll*ans*inv(ccc)%mod;
    cout<<ans<<endl;
}
