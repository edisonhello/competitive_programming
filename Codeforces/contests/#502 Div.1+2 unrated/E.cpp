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
#define pii pair<long long,long long>
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

ll mods[]={1000000000+7,1000000000+9,1000000000+87,1000000000+123,1000000000+861,1000000000+4329,1000000000+25261};
ll prms[]={7,13,47017};
ll mod1,mod2;

#define int long long

pii dif(pii a,pii b){ return pii(a.first-b.first,a.second-b.second); }
int cr(pii a,pii b){ return a.first*b.second-a.second*b.first; }

pair<vector<pii>,vector<pii>> doit(int n){
    vector<pair<int,int>> pt(n);
    for(auto &p:pt)cin>>p.first>>p.second;
    sort(pt.begin(),pt.end());
    int tz=0;
    vector<int> tbm;

    auto usle=[&](pii &a,pii &b,pii &c)->bool{ return cr(dif(b,a),dif(c,a))>=0; };
    for(int i=0;i<n;++i){
        while(tz>1 && usle(pt[tbm[tz-1]],pt[i],pt[tbm[tz-2]]))tbm.pop_back(),--tz;
        tbm.push_back(i); ++tz;
    }
    int ttz=tz;
    for(int i=n-2;i>=0;--i){
        while(tz>ttz && usle(pt[tbm[tz-1]],pt[i],pt[tbm[tz-2]]))tbm.pop_back(),--tz;
        tbm.push_back(i); ++tz;
    }
    --tz;
    PDE(pt,tbm,tz);
    vector<pair<int,int>> tbp(tz);
    for(int i=0;i<tz;++i)tbp[i]=pt[tbm[i]];
    PDE(tbp);
    for(pii &p:tbp)p.first*=tz,p.second*=tz;
    int xtt=0,ytt=0;
    for(pii &p:tbp)xtt+=p.first,ytt+=p.second;
    xtt/=tz; ytt/=tz;
    PDE(xtt,ytt,tbp);
    vector<pii> rt1(tz),rt2(tz);
    for(int i=0;i<tz;++i){
        int dx=abs(tbp[i].first-xtt);
        int dy=abs(tbp[i].second-ytt);
        // PDE(dx,dy);
        auto doit2=[&](int p)->int{
            int tdx=dx%p,tdy=dy%p;
            int ddd=tdx*tdx+tdy*tdy;
            // PDE(tdx,tdy,ddd);
            return ddd%p;
        };
        rt1[i].first=doit2(mod1);
        rt2[i].first=doit2(mod2);
    }
    for(int i=0;i<tz;++i){
        pii p1=tbp[i],p2=tbp[i==tz-1?0:i+1];
        pii d=dif(p2,p1);
        // PDE(d);
        auto doit2=[&](int p)->int{
            int tdx=abs(d.first)%p,tdy=abs(d.second)%p;
            int ddd=tdx*tdx+tdy*tdy;
            // PDE(tdx,tdy,ddd);
            return ddd%p;
        };
        rt1[i].second=doit2(mod1);
        rt2[i].second=doit2(mod2);
    }
    PDE(rt1,rt2);
    return make_pair(rt1,rt2);
}

bool ok(vector<pii> &vap,vector<pii> &vbp,const int mod){
    if(vap.size()!=vbp.size())return 0;
    int len=vap.size();
    PDE(vap,vbp,len);
    int p=prms[rand()%3];
    vector<int> va(1+len),vb(1+len);
    for(int i=0;i<len;++i){
        va[i+1]=(vap[i].first*7122+(vap[i].second^7122))%mod;
        vb[i+1]=(vbp[i].first*7122+(vbp[i].second^7122))%mod;
    }
    vector<int> ha(1+len*2),hb(1+len),pp(1+len*2);
    pp[0]=1;
    for(int i=1;i<=len*2;++i)pp[i]=pp[i-1]*p%mod;
    for(int i=1;i<=len*2;++i)ha[i]=(ha[i-1]+va[i>len?i-len:i]*pp[i])%mod;
    for(int i=1;i<=len;++i)hb[i]=(hb[i-1]+vb[i]*pp[i])%mod;
    PDE(va,vb,ha,hb);
    for(auto o=0u;o<vb.size();++o){
        if((ha[o+len]-ha[o]+mod)%mod==(hb[len]*pp[o]%mod))return 1;
    }
    return 0;
}

int32_t main(){
    CPPinput;
    srand(clock());
    int n,m; cin>>n>>m;
    mod1=mods[rand()%7],mod2=mods[rand()%7];
    auto rn=doit(n);
    auto rm=doit(m);
    if(ok(rn.first,rm.first,mod1) && ok(rn.second,rm.second,mod2))YES;
    else NO;
}
