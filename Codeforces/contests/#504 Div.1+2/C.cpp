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
#include<random>
#include<thread>

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

int match[200005];
int fa[200005];
bitset<200005> noo;
int bit[200005];

void add(int x,int v){
    ++x;
    for(;x<200005;x+=lowbit(x))bit[x]+=v;
}
int query(int x,int v=0){
    ++x;
    for(;x;x-=lowbit(x))v+=bit[x];
    return v;
}
int qlr(int l,int r){
    return query(r)-query(l-1);
}

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    string s; cin>>s;
    int off=n-k; off>>=1;    
    stack<int> st;
    st.push(-1);
    for(int i=0;i<n;++i){
        if(s[i]=='('){
            fa[i]=st.top();
            st.push(i);
        }
        else{
            match[i]=st.top();
            match[st.top()]=i;
            st.pop();
        }
    }
    queue<int> q;
    for(int i=0;i<n;++i){
        if(match[i]==i+1){
            q.push(i);
        }
        add(i,1);
    }
    PDE(off);
    for(int i=0;i<n;++i)PDE(i,fa[i]);
    while(off--){
        PDE(off,q);
        int now=q.front(); q.pop();
        int RRR=match[now];
        noo[now]=noo[RRR]=1;
        add(now,-1);
        add(RRR,-1);
        int F=fa[now];
        PDE(now,F);
        if(F!=-1){
            int QQ=qlr(F+1,match[F]-1);
            PDE(QQ,F+1,match[F]-1);
            if(QQ==0)q.push(F);
        }
    }
    for(int i=0;i<n;++i)if(!noo[i])cout<<s[i];
}
