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

bitset<200005> canteven,cantodd;
int bpre[200005],opre[200005],qpre[200005];

int Q(int *seg,int L,int R){ return seg[R-1]-(L?seg[L-1]:0); }

int main(){
    CPPinput;
    int n; cin>>n;
    string s; cin>>s;
    int m; cin>>m;
    string mms;
    for(int i=1;i<=m;++i)mms+=char(i&1?'a':'b');
    s=mms+s; n+=m;
    for(int i=0;i<n;++i){
        if(s[i]=='a')canteven[i]=1;
        if(s[i]=='b')cantodd[i]=1;
        qpre[i]=int(s[i]=='?')+(i?qpre[i-1]:0);
    }
    for(int i=0;i<n;++i){
        bpre[i]=(i?bpre[i-1]:0);
        opre[i]=(i?opre[i-1]:0);
        if(cantodd[i] && !(i&1))++bpre[i];
        if(canteven[i] && (i&1))++bpre[i];
        if(cantodd[i] && (i&1))++opre[i];
        if(canteven[i] && !(i&1))++opre[i];
    }
    vector<int> co(1,0);
    for(int i=0;i<n;++i){
        if(i+m>n)break;
        // PDE(i);
        co.push_back(qpre[i+m-1]-(i?qpre[i-1]:0));
        if(Q(i&1?opre:bpre,i,i+m))co.back()=1e8;
    }
    // while(co.size()<=n)co.push_back(1e8);
    // co.push_back(0);
    // build(root=new node(),0,n-1,co);
    vector<int> prev(co.size(),0);
    for(int i=1;i<co.size();++i)if(co[i]==1e8)prev[i]=prev[i-1]; else prev[i]=i;
    vector<int> nxt(co.size()+1,0); nxt[co.size()]=co.size();
    for(int i=co.size()-1;i>=1;--i)if(co[i]==1e8)nxt[i]=nxt[i+1]; else nxt[i]=i;
    // nxt[0]=nxt[1];
    PDE(co,nxt,prev);

    struct PII { int len,rep; PII(int z=0,int x=0):len(z),rep(x){} 
        bool operator<(const PII &b)const{ return len==b.len?rep<b.rep:len>b.len; }
    };
    vector<PII> sbit(co.size(),PII(0,1e8));
    vector<PII> uval(co.size(),PII(0,1e8));
    auto upd=[&](int x,PII v)->void{ uval[x]=min(uval[x],v); };
    int uptr=1;
    auto qry=[&](int l,int r,PII v=PII(0,1e8))->PII{ for(;uptr<=r;++uptr)for(int x=uptr;x;x-=x&-x)sbit[x]=min(sbit[x],uval[uptr]); if(!l) return 0; for(int x=l;x<co.size();x+=x&-x)v=min(v,sbit[x]); return v; };
    
    sbit[0]=PII(0,0);
    upd(1,PII(0,0));
    int ff=1;
    vector<pair<int,PII>> ups;
    for(int i=m+1;i<=co.size()-1;++i){
        if(co[i]==1e8)continue;
        while(i-nxt[ff+1]>=m){
            if(nxt[ff+1]-ff<m)nxt[ff+1]=nxt[nxt[ff+1]+1];
            else ff=nxt[ff+1];
        }
        PDE(i,ff);
        PII v=qry(ff,i-m);
        v.rep+=co[i]; ++v.len;
        PDE("up",i,"by",v.rep,v.len);
        upd(i,v);
        ups.emplace_back(i,v);
    }
    // while(n+1-m-nxt[ff+1]>=m-1)ff=nxt[ff+1];
    // PDE(ups);
    if(ups.empty())JIZZ("0\n");
    PII ans=PII(0,1e8);
    for(int i=ups.size()-1;i>=0;--i){
        if(ups.back().first-ups[i].first>=m)break;
        ans=min(ans,ups[i].second);
    }
    cout<<ans.rep<<endl;


    /* vector<vector<int>> v(1);
    int conti=0;
    for(int i:co){
        if(i==1e8)v.back().push_back(i),++conti;
        else{
            if(conti>=m){
                while(conti--)v.back().pop_back();
                if(v.back().size())v.push_back(vector<int>());
            }
            conti=0;
            v.back().push_back(i);
        }
    }
    PDE(co);
    int ans=0;
    for(auto c:v){
        int n=c.size();
        int gr=(n-1)/m+1;
        int le=n-((gr-1)*m+1);
        PDE(c,n,gr,le);
        vector<int> dp(gr*(le+1),1e8);
        for(int i=0;i<=le;++i)dp[i]=c[i];
        for(int i=1;i<=le;++i)dp[i]=min(dp[i],dp[i-1]);
        for(int i=1;i<gr;++i){
            for(int j=0;j<=le;++j){
                dp[i*(le+1)+j]=c[i*m+j];
            }
            for(int j=1;j<=le;++j)dp[i*(le+1)+j]=min(dp[i*(le+1)+j],dp[i*(le+1)+j-1]);
            for(int j=0;j<=le;++j)dp[i*(le+1)+j]+=dp[(i-1)*(le+1)+j];
            for(int j=1;j<=le;++j)dp[i*(le+1)+j]=min(dp[i*(le+1)+j],dp[i*(le+1)+j-1]);
            // if(i==gr-1)for(int j=0;j<=le;++j)mn=min(mn,dp[i*le+j]);
        }
        int mn=1e8;
        for(int i=0;i<=le;++i)mn=min(mn,dp[(gr-1)*(le+1)+i]);
        ans+=mn;
    }
    cout<<ans<<endl; */
}
