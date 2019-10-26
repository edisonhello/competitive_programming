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
const ll mod=998244353;

int a[200005];

long long pw(long long b,long long n,long long m,long long a=1){
    while(n){
        if(n&1)a=a*b%m;
        b=b*b%m; n>>=1;
    } return a;
}

long long inv(long long k){
    return pw(k,mod-2,mod);
}

long long go(vector<int> &v,long long k){
    PDE(v);
    if(v.empty())return 1;
    auto all_1 = [&]()->bool{
        for(int i:v)if(i!=-1)return 0;
        return 1;
    };
    if(all_1()){
        long long rt=k;
        for(int i=1;i<int(v.size());++i){
            rt=rt*(k-1)%mod;
        }
        return rt;
    }
    int cnt=0;
    long long rt=1;
    while(v.size() && v.back()==-1){
        ++cnt;
        v.pop_back();
    }
    rt=rt*pw(k-1,cnt,mod)%mod;
    cnt=0;
    reverse(v.begin(),v.end());
    while(v.size() && v.back()==-1){
        ++cnt;
        v.pop_back();
    }
    rt=rt*pw(k-1,cnt,mod)%mod;
    PDE(rt,v);
    for(int i=0,j;i<int(v.size());){
        for(j=i+1;j<int(v.size());++j){
            if(v[j]>0)break;
        }
        if(j==i+1){
            ++i;
            continue;
        }
        int L=i+1,R=j-1;
        int len=R-L+1;
        int same=(v[L-1]==v[R+1]);
        PDE(L,R,len,same);
        long long isB=same;
        long long notB=1-isB;
        for(int i=1;i<=len;++i){
            long long nx_isB=notB;
            long long nx_notB=(isB*(k-1)+notB*(k-2))%mod;
            tie(isB, notB)=make_pair(nx_isB,nx_notB);
            PDE(i, isB, notB);
        }
        rt=rt*notB%mod;
        i=j;
    }
    PDE(rt);
    return rt;
}

int main(){
    CPPinput;
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=3;i<=n;++i){
        if(a[i]==a[i-2] && a[i]>0){
            cout<<0<<endl;
            exit(0);
        }
    }
    if(k==2){
        int ok=0;
        vector<int> b(n+5);
        for(int i=1;i<=n;++i){
            if(i%4==1)b[i]=1;
            if(i%4==2)b[i]=1;
            if(i%4==3)b[i]=2;
            if(i%4==0)b[i]=2;
        }
        bool notok=0;
        for(int i=1;i<=n;++i){
            if(a[i]==-1);
            else if(a[i]!=b[i])notok=1;
        }
        if(!notok)++ok;
        for(int i=1;i<=n;++i){
            if(i%4==1)b[i]=1;
            if(i%4==2)b[i]=2;
            if(i%4==3)b[i]=2;
            if(i%4==0)b[i]=1;
        }
        notok=0;
        for(int i=1;i<=n;++i){
            if(a[i]==-1);
            else if(a[i]!=b[i])notok=1;
        }
        if(!notok)++ok;
        for(int i=1;i<=n;++i){
            if(i%4==1)b[i]=2;
            if(i%4==2)b[i]=2;
            if(i%4==3)b[i]=1;
            if(i%4==0)b[i]=1;
        }
        notok=0;
        for(int i=1;i<=n;++i){
            if(a[i]==-1);
            else if(a[i]!=b[i])notok=1;
        }
        if(!notok)++ok;
        for(int i=1;i<=n;++i){
            if(i%4==1)b[i]=2;
            if(i%4==2)b[i]=1;
            if(i%4==3)b[i]=1;
            if(i%4==0)b[i]=2;
        }
        notok=0;
        for(int i=1;i<=n;++i){
            if(a[i]==-1);
            else if(a[i]!=b[i])notok=1;
        }
        if(!notok)++ok;
        cout<<ok<<endl;
        exit(0);
    }
    long long ans=1;
    vector<int> v[2];
    for(int i=1;i<=n;++i){
        v[i&1].push_back(a[i]);
    }
    ans=go(v[0],k)*go(v[1],k)%mod;
    /* for(int i=1;i<=n;++i){
        if(a[i]>0)continue;
        if(i<=2){
            if(i+2<=n){
                if(a[i+2]==-1)ans*=k;
                else ans*=k-1;
            }
            else ans*=k;
        }
        else{
            if(a[i-2]==-1){
                if(i+2<=n){
                    if(a[i+2]==-1)ans*=k-1;
                    else ans*=(k-2)*1ll*(k-1)%mod*inv(k)%mod+(k-1)*1ll*inv(k)%mod;
                }
                else ans*=k-1;
            }
            else{
                if(i+2<=n){
                    if(a[i+2]==-1)ans*=k-1;
                    else if(a[i+2]==a[i-2])ans*=k-1;
                    else ans*=k-2;
                }
                else ans*=k-1;
            }
        }
        ans%=mod;
    } */
    cout<<ans<<endl;
}
