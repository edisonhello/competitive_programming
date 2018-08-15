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

pair<ll,ll> ps[2002];
int id[2002],pos[2002];
pair<int,int> line[4000006];

void sol(){
    int n; cin>>n;
    for(int i=1;i<=n;++i)cin>>ps[i].first>>ps[i].second;
    int m=0;
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)line[++m]=make_pair(i,j);
    sort(line+1,line+1+m,[&](const pair<int,int> &a,const pair<int,int> &b)->bool{
        if(ps[a.first].first==ps[a.second].first)return 0;
        if(ps[b.first].first==ps[b.second].first)return 1;
        return (double)
(ps[a.first].second-ps[a.second].second)/(ps[a.first].first-ps[a.second].first)
        < (double)
(ps[b.first].second-ps[b.second].second)/(ps[b.first].first-ps[b.second].first);
    });
    for(int i=1;i<=n;++i)id[i]=i;
    // for(int i=1;i<=n;++i)cout<<ps[i].first<<" "<<ps[i].second<<endl;
    sort(id+1,id+1+n,[&](const int &a,const int &b){ return ps[a]<ps[b]; });
    for(int i=1;i<=n;++i)pos[id[i]]=i;
    double ans=0;
    for(int i=1;i<=m;++i){
        auto l=line[i];

        int L=min(pos[l.first],pos[l.second])-1,R=n-max(pos[l.first],pos[l.second]);
        assert(L+R+2==n);

#define sq(x) ((x)*(x))
        double ttlen=[&](const pair<ll,ll> &a,const pair<ll,ll> &b)->double{
            return sqrt(sq(a.second-b.second)+sq(a.first-b.first));
        }(ps[l.first],ps[l.second]);

        double chance=0;
        if(L+2<=75){ 
            if(n>=75)chance+=pow(2,-L-2);
            else chance+=(pow(2,n-L-2)-1)/(pow(2,n)-n*(n-1)/2-n-1);
        }
        if(R+2<=75){
            if(n>=75)chance+=pow(2,-R-2);
            else chance+=(pow(2,n-R-2)-1)/(pow(2,n)-n*(n-1)/2-n-1);
        }
        PDE(l.first,l.second,L,R,chance,ttlen);
        ans+=chance*ttlen;

        tie(pos[l.first],pos[l.second],id[pos[l.first]],id[pos[l.second]])=make_tuple(pos[l.second],pos[l.first],l.second,l.first);
    }

    cout<<fixed<<setprecision(12)<<ans<<endl;
}

int main(){
    CPPinput;
    int t; cin>>t; while(t--)sol(); 
}
