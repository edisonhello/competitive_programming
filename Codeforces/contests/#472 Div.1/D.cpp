// #pragma GCC optimize("no-stack-protector")
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
#define pll pair<ll,ll>
#define vint vector<int>
#define vll vector<ll>
#define SS stringstream
#define PQ priority_queue
#define MS(x,v) memset((x),(v),sizeof(x))
#define RZUNI(x) sort(x.begin(),x.end()), x.resize(unique(x.begin(),x.end())-x.begin())
#define FLH fflush(stdout)
#define CPPinput ios_base::sync_with_stdio(0); cin.tie(0)

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
#define FIN freopen("in","r",stdin)
#define FOUT freopen("out","w",stdout)
#define DEBUG 1
#define exit(x) cout<<"exit code "<<x<<endl, exit(0)
#else
#define PDE(...) ;
#define DEB(...) ;
#define WHR() ;
#define LOG(...) ;
#define FIN ;
#define FOUT ;
#define DEBUG 0
#endif

#define lowbit(x) ((x)&(-(x)))

#if __cplusplus >= 201103L
#include<unordered_map>
#include<unordered_set>
#include<tuple>
#endif

void JIZZ(){cout<<"";exit(0);}

const ld PI=3.14159265358979323846264338327950288;
const ld eps=1e-9;
const ll mod=1e9+7;

int bit[200005];
ll ans;

void add(int x,int v){
    x=200002-x;
    for(;x<200005;x+=lowbit(x))bit[x]=max(bit[x],v);
}
int query(int x,int v=0){
    x=200002-x;
    for(;x;x-=lowbit(x))v=max(v,bit[x]);
    return v;
}

void check_in(vector<pair<ld,ld>> &v,const vector<ld> &num){
    memset(bit,0,sizeof(bit));
    vector<pair<int,int>> vv;
    for(auto &i:v){
        int l=lower_bound(num.begin(),num.end(),i.X-eps)-num.begin()+1;
        int r=lower_bound(num.begin(),num.end(),i.Y-eps)-num.begin()+1;
        vv.emplace_back(l,r);
    }
    sort(vv.begin(),vv.end(),[](const pair<int,int> &a,const pair<int,int> &b){return a.Y==b.Y?a.X>b.X:a.Y<b.Y;});
    PDE(vv);
    for(auto i:vv){
        int qq=query(i.first);
        ans+=qq;
        ++qq;
        add(i.first,qq);
    }
}
void check_inter(vector<pair<pair<ld,ld>,int>> &tot){
    vector<pair<ld,pair<int,int>>> ev;
    for(auto i:tot){
        ev.emplace_back(i.first.first,make_pair(1,i.second));
        ev.emplace_back(i.first.second,make_pair(-1,i.second));
    }
    sort(ev.begin(),ev.end(),[](const pair<ld,pair<int,int>> &a,const pair<ld,pair<int,int>> &b){
        if(abs(a.X-b.X)>eps)return a.X<b.X;
        // if(a.Y.Y==b.Y.Y)return a.Y.X<b.Y.X;
        return a.Y.X>b.Y.X;
    });
    PDE(ev);
    int cnt0=0,cnt1=0;
    for(auto i:ev){
        if(i.Y.X==1){
            if(i.Y.Y==1){
                ans+=cnt0;
                ++cnt1;
            }
            else{
                ans+=cnt1;
                ++cnt0;
            }
        }
        else{
            if(i.Y.Y==1)--cnt1;
            else --cnt0;
        }
        PDE(ans,cnt0,cnt1);
    }
}

int main(){
    CPPinput;
    int n; ld w; cin>>n>>w;
    vector<pair<ld,ld>> v1,v2;
    vector<pair<pair<ld,ld>,int>> tot;
    vector<ld> num;
    for(int i=0;i<n;++i){
        ld x,vv; cin>>x>>vv;
        ld t1=-x/(vv+w),t2=-x/(vv-w);
        if(t1<t2)v1.emplace_back(t1,t2);
        else v2.emplace_back(t2,t1);
        tot.emplace_back(make_pair(min(t1,t2),max(t1,t2)),t1<t2);
        PDE(t1,t2);

        num.pb(t1);
        num.pb(t2);
    }
    PDE(tot);
    sort(num.begin(),num.end());
    num.resize(unique(num.begin(),num.end(),[](const ld &a,const ld &b){return abs(a-b)<eps;})-num.begin());
    // num.resize(j);
    PDE(num);

    check_in(v1,num);
    PDE(ans);
    check_in(v2,num);
    PDE(ans);
    if(w)check_inter(tot);
    cout<<ans<<endl;
}
