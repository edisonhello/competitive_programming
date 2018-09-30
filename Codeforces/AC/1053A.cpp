// #pragma GCC optimize("no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

bitset<31700> np;
vector<int> p;
void init(){
    for(int i=2;i<31700;++i){
        if(np[i])continue;
        p.push_back(i);
        for(int j=i+i;j<31700;j+=i)np[j]=1;
    }
}

map<int,int> decom(int x){
    map<int,int> rt;
    for(int pp:p){
        while(x%pp==0){
            ++rt[pp];
            x/=pp;
        }
        if(pp*pp>x)break;
    }
    if(x>1)++rt[x];
    return rt;
}

map<int,int> merge(map<int,int> a,map<int,int> b){
    if(a.size()>b.size())a.swap(b);
    for(auto &p:a)b[p.first]+=p.second;
    return b;
}

map<int,int> sub(map<int,int> a,map<int,int> b){
    for(auto &p:b)a[p.first]-=p.second;
    return a;
}

int main(){
    CPPinput;
    int n,m,k; cin>>n>>m>>k;
    long long area=1ll*n*m;
    long long g=__gcd((long long)k,area);
    area/=g; k/=g;
    if(k>2)exit((No,0));
    // area/=g; k/=g;
    // if(k==1)area*=2;
    init();
    map<int,int> pfacs=sub(merge(decom(n),decom(m)),decom(g));
    if(k==1)++pfacs[2],area<<=1;
    function<void(map<int,int>::iterator,map<int,int>&,long long)> dfs=[&](map<int,int>::iterator it,map<int,int> &mp,long long now)->void{
        if(it==mp.end()){
            if(now<=n && area/now<=m){
                Yes;
                cout<<"0 0\n";
                cout<<0<<" "<<area/now<<endl;
                cout<<now<<" "<<0<<endl;
                exit(0);
            }
            return;
        }
        for(int i=0;i<=it->second;++i){
            dfs(next(it),mp,now);
            now*=it->first;
        }
    };
    dfs(pfacs.begin(),pfacs,1ll);
    No;
}
