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

vint p;
bitset<33333> np;
void init(){
    for(int i=2;i<33333;++i){
        if(np[i])continue;
        p.pb(i);
        for(int j=i*i;j<33333;j+=i){
            np[j]=1;
        }
    }
    PDE(p.size());
}


void decomp(int x,unordered_map<int,int> &mp){
    for(int i:p){
        while(x%i==0)++mp[i],x/=i;
        if(i*i>x)break;
    }
    if(x!=1)++mp[x];
    PDE(mp,x);
}
void dfs(unordered_map<int,int>::iterator it,const unordered_map<int,int> &mp,int val,vector<int> &facs){
    if(it==mp.end()){ facs.pb(val); return; }
    auto p=*it; ++it;
    for(int i=0;i<=p.second;++i){
        dfs(it,mp,val,facs);
        val*=p.first;
    }
}

void sol(){
    auto getpw_3=[&](int x)->int{
        int xxx=pow(x,1.0/3);
        --xxx; --xxx; xxx=max(1,xxx);
        for(int z=5;z;--z,++xxx){
            if(xxx*xxx*xxx==x)return xxx;
        }
        return -1;
    };
    auto getpw_2=[&](int x)->int{
        int xxx=pow(x,1.0/2);
        --xxx; --xxx; xxx=max(1,xxx);
        for(int z=5;z;--z,++xxx){
            if(xxx*xxx==x)return xxx;
        }
        return -1;
    };

    int n; cin>>n;
    set<int> v;
    for(int i=0;i<n;++i){ int t; cin>>t; v.insert(t); }
    if(v.size()>4u){ cout<<-1<<'\n'; return; }
    if(DEBUG)cout<<"---------------- in sol ------------- "<<endl;
    // 1 1
    /* if([&]()->bool{ for(int i:v)if(i!=1)return 0; return 1; }()){ cout<<1<<" "<<1<<'\n'; return; }
    if(DEBUG)cout<<"fin 1 1"<<endl; */
    // 1 x
    int mx=*prev(v.end());
    int mx_3=getpw_3(mx);
    if(mx_3!=-1 && [&]()->bool{ for(int i:v)if(i!=1 && i!=mx_3 && i!=mx_3*mx_3 && i!=mx_3*mx_3*mx_3)return 0; return 1; }()){ cout<<1<<" "<<mx_3<<'\n'; return; }
    int mx_2=getpw_2(mx);
    if(mx_2!=-1 && [&]()->bool{ for(int i:v)if(i!=1 && i!=mx_2 && i!=mx_2*mx_2)return 0; return 1; }()){ cout<<1<<" "<<mx_2<<'\n'; return; }
    if(v.size()==2u && *v.begin()==1){ cout<<1<<" "<<mx<<'\n'; return; }
    if(DEBUG)cout<<"fin 1 x"<<endl;
    // x y
    set<int> allfac;
    unordered_map<int,int> pfac;
    vector<int> facs;
    for(int i:v){
        pfac.clear();
        decomp(i,pfac);
        facs.clear();
        dfs(pfac.begin(),pfac,1,facs);
        for(int i:facs)allfac.insert(i);
    }
    
    for(int i:allfac){
        if(i==1)continue;
        PDE(i);
        auto getpw_3=[&](int x)->int{
            int xxx=pow(x,1.0/3);
            --xxx; --xxx; xxx=max(1,xxx);
            for(int z=5;z;--z,++xxx){
                if(xxx*xxx*xxx==x)return xxx;
            }
            return -1;
        };
        auto getpw_2=[&](int x)->int{
            int xxx=pow(x,1.0/2);
            --xxx; --xxx; xxx=max(1,xxx);
            for(int z=5;z;--z,++xxx){
                if(xxx*xxx==x)return xxx;
            }
            return -1;
        };
        auto getok=[&](int x,set<int> &st)->void{
            int pw_3=getpw_3(x);
            if(pw_3!=-1)st.insert(pw_3);
            if(x%i==0)x/=i;
            else return;
            int pw_2=getpw_2(x);
            if(pw_2!=-1)st.insert(pw_2);
            if(x%i==0)x/=i;
            else return;
            st.insert(x);
            if(x==i)st.insert(-1);
        };
        auto sect=[&](set<int> &s1,set<int> &s2)->set<int>{
            if(s1.size() && *s1.begin()==-1)return s2;
            if(s2.size() && *s2.begin()==-1)return s1;
            set<int> rt;
            auto i1=s1.begin(),i2=s2.begin();
            while(i1!=s1.end() && i2!=s2.end()){
                if(*i1==*i2)rt.insert(*i1),++i1,++i2;
                else if(*i1>*i2)++i2;
                else ++i1;
            }
            return rt;
        };
        set<int> oks;
        getok(*v.begin(),oks);
        oks.erase(i);
        for(int i:v){
            set<int> t;
            getok(i,t);
            PDE(i,t);
            if(t.size() && *t.begin()==-1)continue;
            t.erase(i);
            oks=sect(oks,t);
            PDE(oks);
            if(oks.empty())break;
        }
        if(oks.size()){ cout<<i<<" "<<*oks.begin()<<'\n'; return; }
    }
    cout<<-1<<'\n';
}

int main(){
    CPPinput;
    init();
    int t; cin>>t; while(t--){
        sol();
        if(DEBUG)fflush(stdout);
    }
}


